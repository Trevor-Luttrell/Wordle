#pragma once
#include <string>

namespace io {

    std::string inputSecret();

    std::string inputGuess();

    void outputAndCheckGuess(const std::string& userGuessWord, const std::string& secretWord);

    void outputWinMessage();

    void outputLossMessage(const std::string& secretWord);

    std::string toUpperCase(const std::string& str);
}
