#include <iostream>
#include <cstdlib>  // needed for rand() and srand()
#include <ctime>    // needed for time()

using namespace std;

int game(int maxNum) {
    // seeds random number generator with time
    srand(time(0));

    // generates random number between 1 and maxNum
    int randomNumber = rand() % maxNum + 1;

    int playerGuess;
    int numGuesses = 0; // amount of guesses

    do {
        // asks the player for a guess
        cout << "Arvaa numero väliltä 1 ja " << maxNum << endl;
                    cin >> playerGuess;

        numGuesses++;

        // checks if the guess is smaller, larger, or equal
        if (playerGuess < randomNumber) {
            cout << "Numero on isompi." << endl;
        } else if (playerGuess > randomNumber) {
            cout << "Numero on pienempi." << endl;
        } else {
            cout << "Oikea vastaus!" << endl;
        }
    } while (playerGuess != randomNumber);

    return numGuesses;
}

int main() {
    // sets the possible highest random number
    int maxNum = 40;

    // calls the game function
    int numGuesses = game(maxNum);

    // prints the number of guesses
    cout << numGuesses << " arvausta." << endl;

    return 0;
}

