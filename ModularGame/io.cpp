#include <iostream>
#include <cctype>
#include "io.hpp"

namespace io {

    std::string toUpperCase(const std::string& str) {
        std::string result = str;
        for (char& ch : result) {
            ch = std::toupper(static_cast<unsigned char>(ch));
        }
        return result;
    }

    std::string inputSecret() {
        std::string secretWord;

        std::cout << "Enter a five letter word for the player to guess!" << std::endl;
        std::cin >> secretWord;

        while (secretWord.size() != 5) {
            std::cout << "Try again. It has to be five letters." << std::endl;
            std::cin >> secretWord;
        }

        secretWord = toUpperCase(secretWord);
        system("cls");

        return secretWord;
    }

    std::string inputGuess() {
        std::string userGuessWord;

        std::cout << "Guess a word!" << std::endl;
        std::cin >> userGuessWord;

        while (userGuessWord.size() != 5) {
            std::cout << "Please guess a different word. It must be five characters." << std::endl;
            std::cin >> userGuessWord;
        }

        return toUpperCase(userGuessWord);
    }

    void outputAndCheckGuess(const std::string& userGuessWord, const std::string& secretWord) {
        const std::string RESET = "\033[0m";
        const std::string GREEN = "\033[42m";
        const std::string YELLOW = "\033[43m";
        const std::string GRAY = "\033[48;5;240m";

        bool isGuessedCharacterGreen, isGuessedCharacterYellow;
        for (int i = 0; i < userGuessWord.size(); ++i) {
            isGuessedCharacterYellow = false;
            isGuessedCharacterGreen = false;
            for (int j = 0; j < secretWord.size(); ++j) {
                if (secretWord[j] == userGuessWord[i]) {
                    isGuessedCharacterYellow = true;
                    if (i == j) {
                        isGuessedCharacterGreen = true;
                    }
                }
            }

            if (isGuessedCharacterGreen) {
                std::cout << GREEN << userGuessWord[i] << ' ' << RESET;
            }
            else if (isGuessedCharacterYellow) {
                std::cout << YELLOW << userGuessWord[i] << ' ' << RESET;
            }
            else {
                std::cout << GRAY << userGuessWord[i] << ' ' << RESET;
            }
        }
        std::cout << std::endl << std::endl;
    }

    void outputWinMessage() {
        std::cout << "Congratulations you won the game!!!" << std::endl;
    }

    void outputLossMessage(const std::string& secretWord) {
        std::cout << "Sorry, but you're out of guesses! The word was... " << secretWord << "! Better luck next time." << std::endl;
    }
}
