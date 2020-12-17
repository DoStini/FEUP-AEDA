/*
 * CinemaFinder.cpp
 */

#include "CinemaFinder.h"
#include "Cinema.h"
#include "Film.h"
#include <algorithm>

CinemaFinder::CinemaFinder() { }

CinemaFinder::~CinemaFinder() { }

void CinemaFinder::addFilm(Film *f1) {
	FilmPtr fp1;
	fp1.film = f1;
	films.insert(fp1);
}

void CinemaFinder::addCinema(const Cinema &c1)
{ cinemas.push(c1); }

tabHFilm CinemaFinder::getFilms() const
{ return films; }

priority_queue<Cinema> CinemaFinder::getCinemas() const
{ return cinemas; }


list<string> CinemaFinder::filmsWithActor(string actorName) const {
	list<string> res;

    for(const auto f : films)
        // Infinite loop using std::find ??
        for(const string & name : f.film->getActors())
            if(name == actorName){
                res.push_back(f.film->getTitle());
                break;
            }

	return res;
}


void CinemaFinder::addActor(string filmTitle, string actorName) {
    Film film(filmTitle);
    FilmPtr ptr; ptr.film = &film;
    auto it = films.find(ptr);
    if(it == films.end()){
        Film * newFilm = new Film(filmTitle);
        newFilm->addActor(actorName);
        ptr.film = newFilm;
        films.insert(ptr);
    }
    else
        it->film->addActor(actorName);
}


//c1
string CinemaFinder::nearestCinema(string service1) const {
	string cName="";

    priority_queue<Cinema> copy = cinemas;

    bool found = false;
    while (!copy.empty() && !found){
        for(const auto & serv : copy.top().getServices())
            if(serv == service1){
                cName = copy.top().getName();
                found = true;
                break;
            }
        copy.pop();
    }

	return cName;
}


//c2
void CinemaFinder::addServiceToNearestCinema(string service1, unsigned maxDistance) {

    if(!cinemas.empty() && cinemas.top().getDistance() < maxDistance){
        Cinema cinema = cinemas.top();
        cinemas.pop();
        cinema.addService(service1);
        cinemas.push(cinema);
    }
    else throw CinemaNotFound();
}
