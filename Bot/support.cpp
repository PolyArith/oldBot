#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <time.h>
#pragma once
using namespace std;


void pushBackLength(vector<string>& wordList, int length){
    ifstream inWord("wordLibrary.txt");
    string word;
    while (inWord >> word){
        if (word.length() == length) wordList.push_back(word);
    }
}


map<char, vector<int>> wordToData(string secretWord){
    map<char, vector<int>> data;
    for (auto i = data.begin(); i != data.end(); i++) i->second.clear();
    for (int i = 0; i < secretWord.length(); i++){
        if (secretWord[i] != '-') data[secretWord[i]].push_back(i);
    }
    return data;
}