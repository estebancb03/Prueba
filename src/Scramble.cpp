#include <iostream>
#include <time.h>
#include "Scramble.h"
using namespace std;

/*
  EFECTO: maneja las secuencias de las partidas de Scramble
  MODIFICA: DictionaryList
*/
void Scramble :: play() {
    system("cls");
    srand(time(NULL));
    int attempts = 5;
    int localScore = 0;
    int localFaults = 0;
    int localGuessed = 0;
    int consecutiveFaults = 0;
    int numRandom = 1 + rand() % (globalDictionary -> size() - 1);
    string wordToFind = globalDictionary -> searchWord(numRandom) -> getWord();
    string disarrangedWord = globalDictionary -> disarrangeWord(wordToFind);
    string userAttemp = "";
    while(attempts > 0) {
        cout << "---------------  J U G A R  S C R A M B L E  ---------------" << endl << endl;
        cout << "Intentos: " << attempts << endl;
        cout << "Puntaje: " << localScore << endl;
        cout << "Palabra oculta: " << disarrangedWord << "[" << numRandom + 1 << "]" << endl << endl;
        cout << "Palabra: "; cin >> userAttemp;
        if(globalDictionary -> compareWord(wordToFind, userAttemp)) {
            gameDictionary -> addWord(wordToFind);
            cout << endl << "Perfecto! Le atinaste a la palabra" << endl;
            localScore += 10;
            localGuessed++;
            attempts++;
            numRandom = 1 + rand() % (globalDictionary -> size() - 1);
            wordToFind = globalDictionary -> searchWord(numRandom) -> getWord();
            disarrangedWord = globalDictionary -> disarrangeWord(wordToFind);
        }
        else {
            cout << endl << "Fallaste, sigue intentando" << endl;
            attempts--;
            localFaults++;
            consecutiveFaults++;
            if(consecutiveFaults == 3) {
                cout << endl << "No pudiste adivinar, se cambiara la palabra" << endl;
                gameDictionary -> addWord(wordToFind);
                numRandom = 1 + rand() % (globalDictionary -> size() - 1);
                wordToFind = globalDictionary -> searchWord(numRandom) -> getWord();
                disarrangedWord = globalDictionary -> disarrangeWord(wordToFind);
                consecutiveFaults = 0;
            }
        }
        system("Pause");
        system("cls");
    }
    gameDictionary -> addWord(wordToFind);
    setScore(localScore);
    setFaults(localFaults);
    setHits(localGuessed);
    cout << "---------------  J U G A R  S C R A M B L E  ---------------" << endl << endl;
    cout << "-----------------  F I N  D E L  J U E G O  ----------------"  << endl << endl;
    system("Pause");
    system("cls");
}