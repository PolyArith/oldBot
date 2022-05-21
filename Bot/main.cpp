#include <iostream>
#include "display.cpp"
#include "guess.cpp"
#include "support.cpp"
#include "process.cpp"
using namespace std;

void gameplay(){
    int length = getWordLength();
    int vowelsGuessed = 0;
    int incorrectGuess = 0;
    string guessesMade = "";
    string secretWord = string(length, '-');
    string mask;
    vector<string> wordList;
    pushBackLength(wordList, length);

    while (stillPlaying(incorrectGuess, secretWord)){
        display(incorrectGuess, guessesMade, secretWord);
        char guess = getNextGuess(secretWord, guessesMade, wordList, vowelsGuessed);
        inviteMask(mask, secretWord, guess);
        // process co van de voi mask trong
        process(incorrectGuess, mask, secretWord, guessesMade, guess);

    }
    display(incorrectGuess, guessesMade, secretWord);
    if (incorrectGuess < 7) cout << "Yay! I've won! Hurray!" << endl;
    else cout << "Oh man, that was a close one!" << endl;
}


int main(){
    bool play_again = true;
    while (play_again){
        char ifPlayAgain = '1';
        gameplay();
        while (ifPlayAgain != 'y' && ifPlayAgain != 'n'){
            cout << "Would you like to play again? (y/n)" << endl;
            cin >> ifPlayAgain;
            if (ifPlayAgain == 'y'){
                continue;
            } else if (ifPlayAgain == 'n') play_again = false;
        }
    }
    cout << "Hope you enjoyed your time!" << endl;
}
