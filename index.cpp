#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

vector<string> words = {"hangman", "computer", "programming", "cplusplus", "algorithm", "openai", "developer"};

string selectRandomWord() {
    srand(static_cast<unsigned int>(time(nullptr)));
    return words[rand() % words.size()];
}

bool contains(const string& word, char guess) {
    return word.find(guess) != string::npos;
}

string updateDisplayWord(const string& word, const string& displayWord, char guess) {
    string updatedDisplayWord = displayWord;
    for (size_t i = 0; i < word.size(); ++i) {
        if (word[i] == guess) {
            updatedDisplayWord[i] = guess;
        }
    }
    return updatedDisplayWord;
}

void printHangman(int remainingGuesses) {
    switch (remainingGuesses) {
        case 6:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
        case 5:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|         0    " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
        case 4:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|         0    " << endl;
            cout << "|         |    " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
        case 3:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|         0    " << endl;
            cout << "|        /|    " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
        case 2:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|         0    " << endl;
            cout << "|        /|\\  " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
        case 1:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|         0    " << endl;
            cout << "|        /|\\  " << endl;
            cout << "|        /     " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
        case 0:
            cout << " _________     " << endl;
            cout << "|         |    " << endl;
            cout << "|         0    " << endl;
            cout << "|        /|\\  " << endl;
            cout << "|        / \\  " << endl;
            cout << "|              " << endl;
            cout << "|              " << endl;
            break;
    }
}

int main() {
    string word = selectRandomWord();
    string displayWord(word.size(), '_');
    int remainingGuesses = 6;
    vector<char> guessedChars;

    cout << "Welcome to Hangman!" << endl;
    cout << "Try to guess the word before you run out of guesses." << endl;

    while (remainingGuesses > 0) {
        cout << "\nWord: " << displayWord << endl;
        cout << "Remaining guesses: " << remainingGuesses << endl;
        cout << "Guessed characters: ";
        for (char c : guessedChars) {
            cout << c << " ";
        }
        cout << endl;

        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        if (contains(word, guess)) {
            cout << "Correct guess!" << endl;
            displayWord = updateDisplayWord(word, displayWord, guess);
        } else {
            cout << "Incorrect guess!" << endl;
            remainingGuesses--;
            printHangman(remainingGuesses);
        }

        guessedChars.push_back(guess);

        if (displayWord == word) {
            cout << "Congratulations! You guessed the word: " << word << endl;
            break;
        }
    }

    if (remainingGuesses == 0) {
        cout << "You ran out of guesses! The word was: " << word << endl;
    }

    return 0;
}

