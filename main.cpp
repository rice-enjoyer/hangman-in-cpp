#include <iostream>
#include <cstdlib>
#include <ctime>

const std::string HANGMAN[] = {
    "  +---+\n      |\n      |\n      |\n     ===",
    "  +---+\n  O   |\n      |\n      |\n     ===",
    "  +---+\n  O   |\n  |   |\n      |\n     ===",
    "  +---+\n  O   |\n /|   |\n      |\n     ===",
    "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
    "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
    "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
};

void display(const std::string& guessed, int attempts) {
    std::cout << HANGMAN[6 - attempts] << "\n" << guessed 
              << " (" << attempts << " attempts left)\nGuess: ";
}

int main() {
    std::string words[] = {"apple", "banana", "orange"};
    std::srand(std::time(0));
    std::string word = words[std::rand() % 3], guessed(word.length(), '_');
    int attempts = 6;

    while (attempts > 0 && guessed != word) {
        display(guessed, attempts);
        char guess;
        std::cin >> guess;
        bool found = false;

        for (size_t i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                found = true;
            }
        }

        if (!found) attempts--;
    }

    std::cout << HANGMAN[6 - attempts] << "\n" 
              << (guessed == word ? "You win! " : "You lose! ") 
              << "The word was: " << word << '\n';
}
