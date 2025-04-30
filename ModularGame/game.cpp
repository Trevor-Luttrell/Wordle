#include "game.hpp"
#include "io.hpp"
#include <iostream>

namespace wordle {

    Wordle::Wordle() : state() {
        state.secretWord = io::inputSecret();
    }

    void Wordle::playGame() {
        bool hasUserWon = false;

        while (state.guesses < 6 && !hasUserWon) {
            state.userGuessWord = io::inputGuess();

            io::outputAndCheckGuess(state.userGuessWord, state.secretWord);

            int correctlyGuessedLetters = 0;
            for (int i = 0; i < state.secretWord.size(); ++i) {
                if (state.secretWord[i] == state.userGuessWord[i]) {
                    ++correctlyGuessedLetters;
                    if (correctlyGuessedLetters == 5) {
                        io::outputWinMessage();
                        hasUserWon = true;
                    }
                }
            }

            ++state.guesses;

            if (state.guesses == 6 && !hasUserWon) {
                io::outputLossMessage(state.secretWord);
            }
        }
    }
}
