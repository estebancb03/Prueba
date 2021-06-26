#ifndef STATISTICSLIST_H
#define STATISTICSLIST_H
#include "statisticsNode.h"
#include "DictionaryList.h"

class StatisticsList {
    StatisticsNode* head;
    public:
        StatisticsList() { head = nullptr; };
        ~StatisticsList() { delete head; };
        void addStatistic(int s, int f, int h, DictionaryList* d);
        void printStatistics();
};

#endif 