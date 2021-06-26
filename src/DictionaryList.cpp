#include <cstring>
#include <random>
#include <time.h>
#include <iostream>
#include "DictionaryList.h"
using namespace std;

/*
  EFECTO: añade una palabra a la DictionaryList
  REQUIERE: string
  MODIFICA: DictionaryList
*/
void DictionaryList :: addWord(string w) {
    DictionaryNode *temp = head;
    DictionaryNode *newWord = new DictionaryNode(w);
    if(temp == nullptr) 
        head = newWord;
    else {
        while(temp -> getNext() != nullptr) 
            temp = temp -> getNext();
        temp -> setNext(newWord);
    }
}

/*
  EFECTO: devuelve un string con la palabra de un DictionaryNode pero desordenada
  REQUIERE: string
*/
string DictionaryList :: disarrangeWord(string w) {
    int wordSize = w.length();
    int randomNumber[wordSize];
    string disaranged;
    createRandomArray(randomNumber, wordSize);
    for(int i = 0; i < wordSize; i++) 
        disaranged += w[randomNumber[i]];
    return disaranged;
}

/*
  EFECTO: llena un arreglo de un determinado tamaño con números random de 0 al tamaño
  REQUIERE: array int, int
*/
void DictionaryList :: createRandomArray(int array[], int range) {
    int num; 
    srand(time(NULL));
    for (int i = 0; i < range; i++) {
        num = rand() % range;
        while(checkRandom(array, range, num))
            num = rand() % range;
        array[i] = num;
    }
}

/*
  EFECTO: verifica que en el método createRandomArray no se guarden números repetidos en el arreglo
  REQUIERE: array int, int, int
*/
bool DictionaryList :: checkRandom(int array[], int range, int num) {
    int i = 0;
    bool answer = false;
    while(i < range) {
        if(array[i] == num) 
            answer = true;
        i++;
    }
    return answer;
}

/*
  EFECTO: compara dos variables string y determina si son iguales o no
  REQUIERE: string, string
*/
bool DictionaryList :: compareWord(string w1, string w2) {
    bool result = false;
    char word1[w1.length()] = "";
    char word2[w2.length()] = "";
    strcpy(word1, w1.c_str());
    strcpy(word2, w2.c_str());
    strupr(word1);
    strupr(word2);
    if(strcmp(word1, word2) == 0)
        result = true;
    return result;
}

// EFECTO: devuelve el tamaño de la DictionaryList
int DictionaryList :: size() {
    int result = 0;
    DictionaryNode *temp = head;
    while(temp -> getNext() != nullptr) {
        result++;
        temp = temp -> getNext();
    }
    result++;
    return result;
}

/*
  EFECTO: averigua si en la DictionaryList existe una determinada palabra o no
  REQUIERE: string
*/
bool DictionaryList :: searchWord(string w) {
    bool result = false;
    DictionaryNode *temp = head;
    while(temp) {
        if(temp -> getWord() == w) {
            result = true; 
        }
        temp = temp -> getNext();
    }
    return result;
}

/*
  EFECTO: busca y devuelve un DictionaryNode por su posición en la DictionaryList
  REQUIERE: int
*/
DictionaryNode* DictionaryList :: searchWord(int n) {
    int cont = 0;
    DictionaryNode *temp = head;
    if(cont != n) {
        while(temp -> getNext() != nullptr && cont != n) {
            cont++;
            temp = temp -> getNext();
        }
    }
    return temp;
}

// EFECTO: imprime los DictionaryNode de la DictionaryList
void DictionaryList :: printDictionary() {
    DictionaryNode *temp = head;
    if(temp == nullptr)
        cout << "La lista esta vacia";
    else {
        while(temp != nullptr){
            cout << temp -> getWord();
            if(temp -> getNext() != nullptr)
                cout << ", ";
            temp = temp -> getNext();
        }
    }
}
