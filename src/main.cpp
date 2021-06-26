// Esteban Castañeda Blanco - C01795
#include <iostream>
#include <random>
#include <time.h>
#include <fstream>
#include <cstring>
#include "Scramble.h"
#include "StatisticsList.h"
using namespace std;

/*
  EFECTO: llena DictionaryList con la información de un archivo .txt
  REQUIERE: DictionaryList, string
  MODIFICA: DictionaryList
*/
void fillDictionary(DictionaryList *list, string wordsFile) {
    string line;
    ifstream file(wordsFile);
    while(getline(file, line)) {
        list -> addWord(line);
    }
}

/*
  EFECTO: añade una palabra a la DictionaryList y maneja parte gráfica de opción menú
  REQUIERE: DictionaryList 
  MODIFICA: DictionaryList
*/
void addToDictionary(DictionaryList *list) {
    string word = "";
    system("cls");
    cout << "---------------  A G R E G A R  P A L A B R A  ---------------" << endl << endl;
    cout << "Palabra: "; cin >> word;
    char transform[word.length()];
    strcpy(transform, word.c_str());
    strlwr(transform);
    word = transform;
    if(list -> searchWord(word) == true) 
        cout << "Esa palabra ya existe en el diccionario" << endl;
    else {
        list -> addWord(word);
        cout << "Se ha guardado la palabra exitosamente" << endl;
        cout << list -> searchWord(word);
    }
    system("Pause");
    system("cls");
}

/*
  EFECTO: despliega las palabras presententes en DictionaryList y maneja parte gráfica de opción menú
  REQUIERE: DictionaryList 
*/
void consultDictionary(DictionaryList *list) {
    system("cls");
    cout << "---------------  D I C C I O N A R I O  ---------------" << endl << endl;
    list -> printDictionary();
    cout << endl << endl;
    system("Pause");
    system("cls");
}

/*
  EFECTO: maneja parte grafica de la opción de juego, guarda estadísticas de las partidas en StatisticsList
  REQUIERE: DictionaryList, StatisticsList 
  MODIFICA: DictionaryList, StatisticsList
*/
void playScramble(DictionaryList *list, StatisticsList *stats) {
    int gameScore = 0;
    int gameFaults = 0;
    int gameHits = 0;
    Scramble* game = new Scramble(list);
    DictionaryList* gameDictionary = new DictionaryList();
    game -> play();
    gameScore = game -> getScore();
    gameFaults = game -> getFaults();
    gameHits = game -> getGuessed();
    gameDictionary = game -> getGameDictionary();
    stats -> addStatistic(gameScore, gameFaults, gameHits, gameDictionary);
}

int main() {
    int option = 0;
    StatisticsList *statistics = new StatisticsList();
    DictionaryList *globalDictionary = new DictionaryList();
    fillDictionary(globalDictionary, "words.txt");
    system("cls");
    while(option != 5) {
        cout << "---------------  M E N U  D E  O P C I O N E S  ---------------" << endl << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Estadisticas" << endl;
        cout << "3. Consultar diccionario" << endl;
        cout << "4. Agregar al diccionario" << endl;
        cout << "5. Salir" << endl;
        cout << "Escoge una opcion: ";  cin >> option;
        switch(option) {
            case 1: { playScramble(globalDictionary, statistics); }   break;
            case 2: { statistics -> printStatistics(); }   break;
            case 3: { consultDictionary(globalDictionary); }   break;
            case 4: { addToDictionary(globalDictionary); }   break;
        }
    }
    statistics -> ~StatisticsList();
    globalDictionary -> ~DictionaryList();
    return 0;
}