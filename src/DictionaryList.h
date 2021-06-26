#ifndef DICTIONARYLIST_H
#define DICTIONARYLIST_H
#include "DictionaryNode.h"

class DictionaryList {
    DictionaryNode *head;
    public:
        DictionaryList() { head = nullptr; };
        ~DictionaryList() { delete head; };
        string disarrangeWord(string w);
        int size();
        void printDictionary();
        void addWord(string w);
        void createRandomArray(int array[], int range);
        bool compareWord(string w, string w2);
        bool checkRandom(int arry[], int range, int num);
        bool searchWord(string w);
        DictionaryNode *searchWord(int num);
};

#endif