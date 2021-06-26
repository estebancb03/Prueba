#ifndef SCRAMBLE_H
#define SCRAMBLE_H
#include "DictionaryList.h"

class Scramble {
    DictionaryList* gameDictionary;
    DictionaryList* globalDictionary;
    int score;
    int faults;
    int guessed;
    public:
        Scramble(DictionaryList* gb) { globalDictionary = gb; gameDictionary = new DictionaryList(); score = 0; faults = 0; guessed = 0; };
        ~Scramble() { delete gameDictionary; delete globalDictionary; };
        void setScore(int s) { score = s; };
        void setFaults(int f) { faults = f; };
        void setHits(int g) { guessed = g; };
        int getScore() { return score; };
        int getFaults() { return faults; };
        int getGuessed() { return guessed; };
        DictionaryList* getGameDictionary() { return gameDictionary; };
        void play();
}; 

#endif