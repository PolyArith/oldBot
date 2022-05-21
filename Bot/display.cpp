#include <iostream>
#include <stdlib.h>
using namespace std;

const string FIGURE[] = {
" ------------- \n"
" | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" | \n"
" | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |           | \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /| \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" | \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" |          / \n"
" | \n"
" ----- \n",
" ------------- \n"
" |           | \n"
" |           O \n"
" |          /|\\ \n"
" |          / \\ \n"
" | \n"
" ----- \n",
};

void display(int incorrectGuess, string guessesMade, string secretWord){
    system("CLS");
    cout << "Incorrect guesses: " << incorrectGuess << "      " << "Guesses made: " << guessesMade << string(10 - incorrectGuess, ' ') << "Secret word: " << secretWord << endl;
    for (int i = 0; i < 5; i++) cout << endl;
    cout << FIGURE[incorrectGuess];
}