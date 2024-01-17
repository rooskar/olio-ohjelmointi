#ifndef GAME_H
#define GAME_H

class Game {

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    // konstruktori, annetaan maksimiluku
    Game(int max);

    // destruktori
    ~Game();

    // metodi eli funktio pelille
    void play();

    // metodi pelin tuloksille
    void printGameResult();
};

#endif // GAME_H
