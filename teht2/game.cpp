#include "game.h" // header tiedosto
#include <iostream>
#include <cstdlib>
#include <ctime>

// konstruktori
Game::Game(int max) : maxNumber(max), playerGuess(0), randomNumber(0), numOfGuesses(0) {
    std::cout << "GAME CONSTRUCTOR: object initialized with " << maxNumber << " as a maximum value." << std::endl;
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
}

// destruktori, tulostuu kun peli päättyy
Game::~Game() {
    std::cout << "GAME DESTRUCTOR: object cleared from stack memory" << std::endl;
}

// metodi pelille
void Game::play() {

    do {
        std::cout << "Guess a number between 1 and " << maxNumber << ": " << std::endl;;
        std::cin >> playerGuess;
        numOfGuesses++;

        if (playerGuess < randomNumber) {
            std::cout << "Your guess is too small" << std::endl;
        } else if (playerGuess > randomNumber) {
            std::cout << "Your guess is too big" << std::endl;
        }

    } while (playerGuess != randomNumber);
    printGameResult();
}

// tulostaa tulokset
void Game::printGameResult() {
    std::cout << "Your guess is right = " << randomNumber << std::endl;
    std::cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << std::endl;
}
