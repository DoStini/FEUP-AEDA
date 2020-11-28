#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "bst.h"


class WordMeaning {
        string word;
        string meaning;
        public:
        WordMeaning(string w, string m): word(w), meaning(m) {}
        string getWord() const { return word; }
        string getMeaning() const { return meaning; }
        void setWord(string w) {word=w; }
        void setMeaning(string m) { meaning=m; }
        bool operator < (const WordMeaning &wm1) const;
};


class Dictionary
{
    BST<WordMeaning> words;
public:
    Dictionary(): words(WordMeaning("","")){};
    BST<WordMeaning> getWords() const;
    void readDictionary(ifstream &f);
    string searchFor(string word) const;
    bool correct(string word, string newMeaning);
    void print() const;
};


//TODO
class WordInexistent
{
private:
    WordMeaning wb, wa;
public:
    WordInexistent(WordMeaning wb, WordMeaning wa) : wb(std::move(wb)), wa(std::move(wa)) {}
    string getWordBefore() const { return wb.getWord(); }
    string getMeaningBefore() const { return wb.getMeaning(); }
    string getWordAfter() const { return wa.getWord(); }
    string getMeaningAfter() const { return wa.getMeaning(); }
};

#endif