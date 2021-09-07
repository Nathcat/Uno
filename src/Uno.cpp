#include "Uno.h"
#include "Cards.cc"


int main() {
  vector<Card> deck = generateDeck();  // Generate a new deck

  // Get the number of playes
  int numberOfPlayers;

  cout << "How many players? > ";
  cin >> numberOfPlayers;

  // Generate the player decks
  vector<vector<Card>> playerDecks;

  for (int x = 0; x < numberOfPlayers; x++) {
    playerDecks.push_back(generatePlayerDeck(&deck));
  }

  // Create the TurnCounter
  TurnCounter turnCounter;

  // Create the cardsPlayed list, and add a card from the deck to it
  vector<Card> cardsPlayed;

  cardsPlayed.push_back(deck[0]);
  deck.erase(0);

  while (true) {  // Main game loop
    checkForWin();  // Check if a player has once

    cout << "\n--------------------\nIt's player " << turnCounter.turn << "'s turn!\n\n";

    cout << cardsPlayed[-1].toString() << "\n\n";  // Show the card on the top of the pile

    for (int x = 0; x < playerDecks[turnCounter.turn].size(); x++) {
      cout << playerDecks[turnCounter.turn][x].toString() << ", ";
    }

    while (true) {  // Enter command loop, will not break until the user enters a valid command
      string command_raw;

      cout << "\n\nEnter action > ";
      cin >> command_raw;

      vector<string> command = split(command_raw);

      if (command[0] == "take") {  // Take a card from the deck
        playerDecks[turnCounter.turn].push_back(deck[0]);
        deck.erase(0);
        turnCounter.nextTurn();
        break;

      } else if (command[0] == "play") {  // Play the card specified by command[1]
        if (canPlay(playerDecks[turnCounter.turn][stoi(command[1])])) {
          if (playerDecks[turnCounter.turn][stoi(command[1])].name == "+2") {  // Add two cards to the next player's deck
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])])
            playerDecks[turnCounter.turn].erase(stoi(command[1]));
            turnCounter.nextTurn();

            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "+4") {  // Add four cards to the next player's deck and choose a new colour
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])])
            playerDecks[turnCounter.turn].erase(stoi(command[1]));
            turnCounter.nextTurn();

            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);

            cardsPlayer[-1].colour = chooseColour();

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "switch") {  // Allow the player to choose a new colour
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])])
            playerDecks[turnCounter.turn].erase(stoi(command[1]));
            turnCounter.nextTurn();

            cardsPlayed[-1].colour = chooseColour();

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "reverse") {  // Reverse the direction of play
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])])
            playerDecks[turnCounter.turn].erase(stoi(command[1]));

            turnCounter.changeDirection();
            turnCounter.nextTurn();

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "skip") {  // Skip the next player's turn
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])])
            playerDecks[turnCounter.turn].erase(stoi(command[1]));

            turnCounter.nextTurn();
            turnCounter.nextTurn();

          } else {  // If it's any card, just add it to the top of the pile
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])])
            playerDecks[turnCounter.turn].erase(stoi(command[1]));
            turnCounter.nextTurn();

          }

          break;

        } else {
          cout << "\n\nYou can't play that card here!\n\n";
        }
      } else if (command[0] == "quit") {  // Quit the game
        exit(0);

      } else {  // Handle invalid commands
        cout << "\n\nInvalid command '" << command[0] << "'\n\n";

      }
    }

  }

  return 0;
}
