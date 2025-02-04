#include <iostream>
#include <cstdlib>
#include <random>

const std::string HANGMAN[] = { // The hangman figure
  "  +---+\n      |\n      |\n      |\n     ===",
  "  +---+\n  O   |\n      |\n      |\n     ===",
  "  +---+\n  O   |\n  |   |\n      |\n     ===",
  "  +---+\n  O   |\n /|   |\n      |\n     ===",
  "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
  "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
  "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
};

void display(const std::string& guessed, int attempts); // Declaration of "display" function. Defined at the end.

int main()
{
  std::cout << "Hangman. Enter one word at a time but enter a whole word if you want to.\n";
  std::string words[] = {"meshan", "gun", "apple"}; // Predefined array of words, can be changed. (Line 24 needs to be changed accordingly).
  std::random_device rd;
  std::mt19937 gen(rd()); // Initialize the random number generator
  
  std::uniform_int_distribution<> dis(0, 2); // Random number between 0 and 2 (size of words array)
  
  std::string word = words[dis(gen)]; // Select a random word from the words[] array
  std::string guessed(word.length(), '_');

  int attempts = 6; // Number of attempts, do not modify.

  while (attempts > 0 && guessed != word) { // This loop controls the game's progress, handling guesses, updating the display, and checking for win/loss conditions.
    display(guessed, attempts);
    char guess;
    std::cin >> guess;
    bool found = false; // Will be used later to check if the guessed character exists in the word.

    for (size_t i = 0; i < word.length(); i++) { // Iterates through each letter of the word, one by one. 'i' is the index of each character in the word.
      if (word[i] == guess) { // Checks if the guessed letter matches the letter at position i in the word. If they match, it means the player has guessed a correct letter.
        guessed[i] = guess; // Updates the guessed string at position 'i' to show the correct letter in place of the underscore.
        found = true; // Found is set to true when the guess is correct. Indicates that the player has guessed at least one correct letter in this round.
      }
    }

    if (!found) attempts--; // If no match was found (while "found" is still false), the player's number of attempts is decreased by 1.
  }

  std::cout << HANGMAN[6 - attempts] << "\n" << (guessed == word ? "You win! " : "You lose! ") << "The word was: " << word << '\n'; // First part displays the current state of the hangman figure. Second part shows whether the player has won or lost based on the condition: guessed == word. 
  return 0;
}

void display(const std::string& guessed, int attempts) // Shows the current state of the game
{
  std::cout << HANGMAN[6 - attempts] << "\n" << guessed << " (" << attempts << " attempts left)\nGuess: ";    
}
