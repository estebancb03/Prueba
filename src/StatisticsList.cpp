#include <iostream>
#include "StatisticsList.h"
using namespace std;

/*
  EFECTO: añade una estadística a la StatisticsList
  REQUIERE: int, int, int, DictionaryList
  MODIFICA: StatisticsList
*/
void StatisticsList :: addStatistic(int s, int f, int g, DictionaryList* d) {
    StatisticsNode *temp = head;
    StatisticsNode *newStatistic = new StatisticsNode(s,f,g,d);
    if(temp == nullptr)
        head = newStatistic;
    else {
        while(temp -> getNext() != nullptr) 
            temp = temp -> getNext();
        temp -> setNext(newStatistic);
    }
}

// EFECTO: imprime los StatisticsNode de la StatisticsList
void StatisticsList :: printStatistics() {
    StatisticsNode *temp = head;
    int cont = 1;
    system("cls");
    cout << "---------------  E S T A D I S T I C A S  ---------------" << endl;
    if(temp == nullptr)
        cout << "No hay estadisticas" << endl;
    else {
        while(temp != nullptr){
            cout << endl;
            cout << "Partida: " << cont << endl;
            cout << "Puntaje: " << temp -> getScore() << endl;
            cout << "Fallos : " << temp -> getFaults() << endl;
            cout << "Aciertos: " << temp -> getGuessed() << endl;
            cout << "Palabras: " << "[ "; temp -> getDictionary() -> printDictionary(); cout << " ]" << endl;
            cout << endl << "---------------------------------------------------------" << endl;
            cont++;
            temp = temp -> getNext();
        }
    }
    system("Pause");
    system("cls");
}