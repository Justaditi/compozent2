# Compozent Task 2
# Hangman Game

This repository contains a simple text-based implementation of the popular game Hangman, written in C++.

## Overview

Hangman is a word guessing game where the player tries to guess a hidden word letter by letter within a certain number of guesses. For each incorrect guess, a part of a gallows and a victim is drawn. The game ends when the player correctly guesses the word or runs out of guesses.

## Features

- **Random Word Selection:** The game randomly selects a word from a predefined list.
- **Display Word:** Displays the current state of the word with blank spaces for unguessed letters.
- **Guessing:** Allows the player to guess letters one at a time.
- **Remaining Guesses:** Tracks the remaining guesses and displays a visual representation of the gallows.
- **Game Over:** Ends the game when the player either guesses the word or runs out of guesses.

## Usage

### Compilation

Compile the source code using a C++ compiler. For example:

```bash
g++ hangman.cpp -o hangman
