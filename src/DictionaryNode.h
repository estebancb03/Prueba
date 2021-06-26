#ifndef DICTIONARYNODE_H
#define DICTIONARYNODE_H
#include <string>
using namespace std;

class DictionaryNode {
    string word;
    DictionaryNode *next;
    public:
        DictionaryNode() { word = ""; next = nullptr; }
        DictionaryNode(string w) { word = w ; next = nullptr; };
        string getWord() { return word; };
        void setWord(string w) { word = w; };
        DictionaryNode* getNext() { return next; };
        void setNext(DictionaryNode* n) { next = n; };
};

#endif