#pragma once
#include <string>
#include <vector>

namespace wordle {
    class State {
    public:
        State();

        std::string secretWord;
        std::string userGuessWord;
        int guesses;
    };
}