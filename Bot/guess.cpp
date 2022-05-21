#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <time.h>
#include "support.cpp"
using namespace std;

// (1) guess vowels
// (2) process after each guess
// (3) compile length, mask, for max data driven guess



const string vowels = {'a', 'e', 'i', 'o', 'u'};

// --a--


bool emptyWord(string secretWord){
    if (secretWord == string(secretWord.length(), '-')) return true;
    return false;
}

char vowelGuess(int& vowelsGuessed){
    vowelsGuessed++;
    return vowels[vowelsGuessed - 1];
}

bool acceptable(string word, map<char, vector <int>> data){ 
    map<char, vector<int>> checkData = wordToData(word);
    for (auto i = data.begin(); i != data.end(); i++){
        bool found = false;
        for (auto j = checkData.begin(); j != checkData.end(); j++){
            if (i->first == j->first && i->second == j->second){
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

vector<char> charFrequency(vector<string> wordList){  //check v
    int frequency[26] = {0};
    for (int i = 0; i < wordList.size(); i++){
        for (int j = 0; j < wordList[i].length(); j++) frequency[wordList[i][j] - 'a']++;
    }

    vector<char> alphabet;
    for (int i = 0; i < 26; i++) alphabet.push_back('a' + i);
    for (int i = 0; i < 26; i++){
        for (int j = 0; j < 26; j++){
            if (frequency[alphabet[j] - 'a'] < frequency[alphabet[i] - 'a']){
                char temp = alphabet[j];
                alphabet[j] = alphabet[i];
                alphabet[i] = temp;
            }
        }
    }
    return alphabet;
}

char randomChar(){
    srand(time(NULL));
    return rand() % 26 + 'a';
}

vector<string> updateWordList(vector<string> wordList, map<char, vector<int>> data){
    vector<string> accepted;
    for (int i = 0; i < wordList.size(); i++){
        if (acceptable(wordList[i], data)) accepted.push_back(wordList[i]);
    }
    return accepted;
}





char getNextGuess(string secretWord, string previousGuess, vector<string> wordList, int& vowelsGuessed){
    // get one vowel first
    
    if (emptyWord(secretWord)) return vowelGuess(vowelsGuessed);
    

    //find possible answers (data driven - kinda)
    // (1) break down secret word to data
    map<char, vector<int>> compiledData = wordToData(secretWord);
    

    // filter wordList

    wordList = updateWordList(wordList, compiledData);

    // rank after update
    // get vector of ranked chars
    vector<char> rankedChar = charFrequency(wordList);

    for (int i = 0; i < rankedChar.size(); i++){
        if (secretWord.find(rankedChar[i]) == string::npos && previousGuess.find(rankedChar[i]) == string::npos) return rankedChar[i];
    }
    // can either use map or just an array of frequency

    // supposed, there are no words whose structure fits
    // random choice it is
    return randomChar();

}


