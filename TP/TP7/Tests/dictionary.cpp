#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "bst.h"

using namespace std;

BST<WordMeaning> Dictionary::getWords() const {
    return words;
}

bool WordMeaning::operator < (const WordMeaning &wm1) const {
    return word < wm1.word;
}

void Dictionary::readDictionary(ifstream &f)
{
    std::string word, mean;
    if(f.is_open()){
        while (f >> word){
            f.ignore(10, '\n');
            std::getline(f, mean);
            words.insert(WordMeaning(word,mean));
            mean = std::string("");
        }
    }
}

//TODO
string Dictionary::searchFor(string word) const
{
    auto it = BSTItrIn<WordMeaning>(words);
    auto itpre = BSTItrIn<WordMeaning>(words);
    while (!it.isAtEnd()){
        if(it.retrieve().getWord() == word)
            return it.retrieve().getMeaning();
        if(itpre.retrieve().getWord() < word && it.retrieve().getWord() > word )
        {
            throw WordInexistent(itpre.retrieve(), it.retrieve());
        }
        itpre = it;
        it.advance();
    }
    throw WordInexistent(itpre.retrieve(), itpre.retrieve());
}

//TODO
bool Dictionary::correct(string word, string newMeaning)
{
    bool ret = false;
    auto it = BSTItrIn<WordMeaning>(words);
    while (!it.isAtEnd()){
        if(it.retrieve().getWord() == word){
            words.remove(it.retrieve());
            ret = true;
            break;
        }
        it.advance();
    }
    words.insert(WordMeaning(word,newMeaning));
    return ret;
}

void Dictionary::print() const
{
    auto it = words.begin();

    while (it != words.end()){
        std::cout << (*it).getWord() << std::endl << (*it).getMeaning() << std::endl;
        it++;
    }
}

