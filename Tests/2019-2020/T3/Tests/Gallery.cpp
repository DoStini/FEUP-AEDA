#include "Gallery.h"
#include <ostream>
using namespace std;

Gallery::Gallery(vector<Paint*> c): catalog(PaintCatalogItem("", "", 0, 0.00)), collection(c) {

}

vector<Paint*> Gallery::getCollection() const {
    return collection;
}

void Gallery::setCollection(vector<Paint*> c) {
    collection = c;
}

priority_queue<ExhibitionItem> Gallery::getPaintsToShow() const {
    return paintsToShow;
}
HashTableAuthorRecord Gallery::getAuthorRecords () const {
    return  authorRecords;
}

void Gallery::addAuthorRecord(AuthorRecord ar) {
    authorRecords.insert(ar);
}

void Gallery::generateCatalog() {
    catalog.makeEmpty();
    for(int i = 0; i < collection.size(); i++) {
        catalog.insert(collection[i]);
    }
}

BST<PaintCatalogItem> Gallery::getCatalog() const {
    return catalog;
}


void Gallery::prepareExhibition() {
    while( !paintsToShow.empty())
        paintsToShow.pop();
    for(int i = 0; i < collection.size(); i++) {
        ExhibitionItem ei(collection[i]);
        paintsToShow.push(ei);
    }
}

//-------------------------------------------------------------------------------

vector<Paint*> Gallery::getPaintsBy(string a) const {
    vector<Paint*> tmp;

    BSTItrIn<PaintCatalogItem> it(catalog);

    while (!it.isAtEnd()){
        if(it.retrieve().getAuthor() == a)
            tmp.push_back(it.retrieve().getPaint());
        it.advance();
    }

    return tmp;
}

vector<Paint*> Gallery::getPaintsBetween(int y1, int y2) const {
    vector<Paint*> tmp;
    BSTItrIn<PaintCatalogItem> it(catalog);

    while (!it.isAtEnd()){
        if(it.retrieve().getYear() >= y1 && it.retrieve().getYear() <= y2)
            tmp.push_back(it.retrieve().getPaint());
        it.advance();
    }
    return tmp;
}

bool Gallery::updateTitle(Paint* p, string tnew) {

    PaintCatalogItem temp = catalog.find(p);
    if(temp.getPaint()->getTitle().empty())
        return false;

    catalog.remove(temp);

    catalog.insert(PaintCatalogItem(p->getAuthor(), tnew, p->getYear(), p->getPrice() ));

    return true;
}


int Gallery::recordAvailablePainters() { //carrega a tabela de dispersao com AuthorRecords

    auto it = collection.begin();

    int counter = 0;
    while (it != collection.end()) {
        auto temp = authorRecords.find(AuthorRecord((*it)->getAuthor()));

        if (temp == authorRecords.end()) {
            AuthorRecord t((*it)->getAuthor());
            authorRecords.insert(t);
            counter++;
        } else {
            AuthorRecord rec = *temp;
            authorRecords.erase(temp);
            rec.addAvaliablePaint();
            authorRecords.insert((rec));
        }
        it++;
    }
    return counter;
}

double Gallery::totalSells() const {
    double a = 0.0;
    for(auto rec: authorRecords) a += rec.getTotalSells();
    return a;
}

double Gallery::sellPaint(string a, string t) {

    double price = 0.0;


    auto it = collection.begin();
    Paint * found = nullptr;
    while (it != collection.end()){
        if((*it)->getAuthor() == a && (*it)->getTitle() == t){
            found = *it;
            break;
        }
        it++;
    }

    if(found != nullptr && !found->getTitle().empty()){
        price = found->getPrice();

        auto temp = *authorRecords.find(a);

        AuthorRecord rec(temp.getAuthor(), temp.addAvaliablePaint() - 1, temp.getTotalSells() + price);
        authorRecords.erase(temp);
        authorRecords.insert((rec));
        collection.erase(it);
    }

    return price;
}

vector<Paint*> Gallery::nBestExibition(int n, int maxPerYear) {  //escolhe as N mais caras pinturas, dos anos mais antigos, para realizar uma exposição
    vector<Paint*> tmp;
    int counter = 0;
    priority_queue<ExhibitionItem> copy;
    int year = 0;
    while (!paintsToShow.empty() && n > 0){
        if(paintsToShow.top().getYear() == year){
            counter++;
            if(counter >= maxPerYear) {
                copy.push(paintsToShow.top());
                paintsToShow.pop();
                continue;
            }
        }
        else{
            counter = 0;
            year = paintsToShow.top().getYear();
        }
        tmp.push_back(paintsToShow.top().getPaint());
        n--;
        paintsToShow.pop();
    }
    while (!paintsToShow.empty()){
        copy.push(paintsToShow.top());
        paintsToShow.pop();
    }

    paintsToShow = copy;

    return tmp;
}

int Gallery::itemExibitionOrder(string a, string t) {
    auto copy = paintsToShow;

    int counter = 0;

    while (!copy.empty()){
        counter++;
        if(copy.top().getTitle() == t && copy.top().getAuthor() == a)
            break;
        copy.pop();
    }

    return !copy.empty() ? counter : 0;
}

