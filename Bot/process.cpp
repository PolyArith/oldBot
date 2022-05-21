#include <iostream>
#include <vector>
#include <map>
#include "support.cpp"
using namespace std;




int getWordLength(){
    int length;
    cout << "Enter your word length: ";
    cin >> length;
    return length;
}

bool stillPlaying(int incorrectGuess, string secretWord){
    return (incorrectGuess < 7) && (secretWord.find('-') != string::npos);
}

// string is usable if either blank or contains only one good input
// check if string is usable

bool check(string mask, string secretWord, char guess){
    // length
    if (mask.length() != secretWord.length()) return false;

    // one distinct char

    map<char, vector<int>> charFrequency = wordToData(mask);
    if (charFrequency.size() > 1) return false;

    // check if any overlapsing

    if (secretWord.find(charFrequency.begin()->first) != string::npos) return false;
    if (charFrequency.size() == 1 && charFrequency.begin()->first != guess) return false;


    // check positions
    vector<int> positions = charFrequency.begin()->second;


    for (int i = 0; i < positions.size(); i++){
        if (secretWord[positions[i]] != '-') return false;
    }

    return true;


}

void inviteMask(string& mask, string secretWord, char guess){
    cout << "My guess is " << guess << ", enter your mask please: ";
    cin >> mask;
    while (!check(mask, secretWord, guess)){
        cout << "Invalid input!" << endl;
        cout << "Enter your mask please: ";
        cin >> mask;
    }

}

// update after having checked in process void
void update(string& secretWord, string mask){

    map<char, vector<int>> charFrequency = wordToData(mask);
    char input = charFrequency.begin()->first;
    vector<int> inputPos = charFrequency[input];
    for (int i = 0; i < inputPos.size(); i++){
        secretWord[inputPos[i]] = input;
    }

}



void process(int& badGuessCount, string mask, string& secretWord, string& guessesMade, char guess){
    string a(mask.size(), '-');
    if (mask == a) {
        badGuessCount++;
        guessesMade += string(1, guess);

    } else update(secretWord, mask);
    //if correct

}

