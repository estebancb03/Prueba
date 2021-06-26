#ifndef STATISTICSNODE_H
#define STATISTICSNODE_H
#include "DictionaryList.h"
using namespace std;

class StatisticsNode {
    int score;
    int faults;
    int guessed;
    DictionaryList* dictionary;
    StatisticsNode* next;
    public:
        StatisticsNode() { score = 0; faults = 0; guessed = 0; dictionary = new DictionaryList(); next = nullptr; };
        StatisticsNode(int s, int f, int g, DictionaryList* d) { score = s; faults = f; guessed = g; dictionary = d; next = nullptr; };
        ~StatisticsNode() { delete dictionary; };
        int getScore() { return score; };
        int getFaults() { return faults; };
        int getGuessed() { return guessed; };
        StatisticsNode* getNext() { return next; };
        DictionaryList* getDictionary() { return dictionary; };
        void setNext(StatisticsNode* n) { next = n; };
};

#endif 