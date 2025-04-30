#pragma once 
#include "state.hpp"

namespace wordle {

    class Wordle {
    public:
        Wordle();
        void playGame();
    private:
        wordle::State state;
    };
}