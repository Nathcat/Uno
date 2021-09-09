#include "Uno.h"
#include "Cards.cc"


int main() {
  // Seed the random generator
  srand(time(NULL));
  
  // Create a new deck for the game and shuffle it
  vector<Card> deck;
  deck = generateDeck();
  deck = shuffle(deck);

  // Get the number of players
  int numberOfPlayers;
  cout << "Enter the number of players > ";
  cin >> numberOfPlayers;

  cout << endl << endl;

  // Generate player decks
  vector< vector<Card> > playerDecks;

  for (int x = 0; x < numberOfPlayers; x++) {
    playerDecks.push_back(generatePlayerDeck(&deck));
  }

  // Create a turn counter
  TurnCounter turnCounter (numberOfPlayers);

  // Create the cards played list
  vector<Card> cardsPlayed;
  cardsPlayed.push_back(deck[0]);
  deck.erase(deck.begin());

  if (cardsPlayed[cardsPlayed.size() - 1].colour == RESET) {
    cout << endl << "The first card is a black card" << endl;

    string newColour = chooseColour();

    cardsPlayed[cardsPlayed.size() - 1].colour = newColour;
  }

  while (true) {  // Main game loop

    // Check if a player has won
    for (int x = 0; x < playerDecks.size(); x++) {
      if (playerDecks[x].size() == 0) {
        cout << endl << endl << "Player " << x << " has won! Congrats :)" << endl;

        exit(0);
      }
    }

    cout << endl << endl << endl << endl << endl;
    cout << "--------------------" << endl;
    cout << "It's player " << turnCounter.turn << "'s turn!" << endl << endl;
    
    cout << cardsPlayed[cardsPlayed.size() - 1].toString() << endl << endl;

    displayDeck(playerDecks[turnCounter.turn]);

    while (true) {  // Enter command loop
      // Enter command and split by spaces
      cout << endl << "Enter action > ";
      string command;
      cin >> command;


      if (command == "take") {
        // Take a card
        playerDecks[turnCounter.turn].push_back(deck[0]);
        deck.erase(deck.begin());

        turnCounter.nextTurn();

        break;

      } else if (command == "play") {
        int cardIndex;
        cin >> cardIndex;

        bool playable = canPlay(cardsPlayed, playerDecks[turnCounter.turn][cardIndex]);

        if (playable) {
          if (playerDecks[turnCounter.turn][cardIndex].name == "+2") {  // Add two cards to the next player's deck
            cardsPlayed.push_back(playerDecks[turnCounter.turn][cardIndex]);
            playerDecks[turnCounter.turn].erase(playerDecks[turnCounter.turn].begin() + cardIndex);

            turnCounter.nextTurn();

            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(deck.begin());
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(deck.begin());

          } else if (playerDecks[turnCounter.turn][cardIndex].name == "skip") {  // Skip the next player's turn
            cardsPlayed.push_back(playerDecks[turnCounter.turn][cardIndex]);
            playerDecks[turnCounter.turn].erase(playerDecks[turnCounter.turn].begin() + cardIndex);

            turnCounter.nextTurn();
            turnCounter.nextTurn();

          } else if (playerDecks[turnCounter.turn][cardIndex].name == "reverse") {  // Change the direction of play
            cardsPlayed.push_back(playerDecks[turnCounter.turn][cardIndex]);
            playerDecks[turnCounter.turn].erase(playerDecks[turnCounter.turn].begin() + cardIndex);

            turnCounter.changeDirection();
            turnCounter.nextTurn();

          } else if (playerDecks[turnCounter.turn][cardIndex].name == "+4") {  // Add four cards to the next player's deck and allow the player to choose a new colour
            cardsPlayed.push_back(playerDecks[turnCounter.turn][cardIndex]);
            playerDecks[turnCounter.turn].erase(playerDecks[turnCounter.turn].begin() + cardIndex);

            string newColour = chooseColour();
            
            cardsPlayed[cardsPlayed.size() - 1].colour = newColour;

            turnCounter.nextTurn();

            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(deck.begin());
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(deck.begin());
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(deck.begin());
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(deck.begin());

          } else if (playerDecks[turnCounter.turn][cardIndex].name == "switch")  {  // Allow the player to change the colour
            cardsPlayed.push_back(playerDecks[turnCounter.turn][cardIndex]);
            playerDecks[turnCounter.turn].erase(playerDecks[turnCounter.turn].begin() + cardIndex);

            string newColour = chooseColour();

            cardsPlayed[cardsPlayed.size() - 1].colour = newColour;

            turnCounter.nextTurn();

          } else {  // Play the card and make no other action
            cardsPlayed.push_back(playerDecks[turnCounter.turn][cardIndex]);
            playerDecks[turnCounter.turn].erase(playerDecks[turnCounter.turn].begin() + cardIndex);

            turnCounter.nextTurn();
          }

          break;

        } else {
          cout << endl << endl << "You can't play that card here!" << endl;
        }

      } else if (command == "quit") {
        exit(0);
      } else {
        cout << endl << endl << "Invalid command" << endl;
      }
    }

  }

  return 0;
}