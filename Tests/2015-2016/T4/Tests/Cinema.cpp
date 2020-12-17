/*
 * Cinema.cpp
 */
#include "Cinema.h"

Cinema::Cinema(string nm, unsigned d, unsigned nr): name(nm), distance(d),
		numberOfRooms(nr),timetable(FilmTime(0,NULL, 0))
{}

Cinema::Cinema(string nm, unsigned d, unsigned nr, list<string> ls): name(nm), distance(d),
		numberOfRooms(nr),services(ls), timetable(FilmTime(0,NULL,0))
{}

Cinema::~Cinema() { }

string Cinema::getName() const
{ return name; }

unsigned Cinema::getDistance() const
{ return distance; }

list<string> Cinema::getServices() const
{ return services; }

BST<FilmTime> Cinema::getTimetable() const
{ return timetable; }

void Cinema::addService(string service1)
{ services.push_back(service1); }

void Cinema::addFilmTime(const FilmTime &ft1)
{ timetable.insert(ft1); }



bool Cinema::operator<(const Cinema & cr) const
{
    return   distance > cr.distance ||
             (distance == cr.distance && services.size() < cr.services.size());
}


Film *Cinema::filmAtHour(unsigned &h1) const {
	Film *res = NULL;
    FilmTime * last = NULL;
    BSTItrIn<FilmTime> it(timetable);


    while(!it.isAtEnd()){
        last = &it.retrieve();
        if(last->getHour() == h1){
            res = last->getFilm();
            break;
        }
        it.advance();
    }

    if(res == NULL && last != NULL && last->getHour() < h1){
        h1 =  last->getHour();
        res = last->getFilm();
    }

	return res;
}


bool Cinema::modifyHour(unsigned h1, unsigned room1, unsigned h2) {

    FilmTime found = timetable.find(FilmTime(h1,NULL,room1));
    FilmTime found2 = timetable.find(FilmTime(h2,NULL,room1));

    if(found.getFilm() == nullptr || found2.getFilm() != nullptr)
        return false;

    timetable.remove(found);
    timetable.insert(FilmTime(h2,found.getFilm(), room1));

	return true;
}


unsigned Cinema::addFilm(Film *f1, unsigned h1) {
	unsigned roomToUse = 0;

    BSTItrIn<FilmTime> it(timetable);

    int id = 1;

    while(!it.isAtEnd()){

        if(it.retrieve().getHour() == h1)
            id++;

        it.advance();
    }

    if(id <= numberOfRooms)
        timetable.insert(FilmTime(h1,f1,id));
    else id = 0;

	return id;
}






