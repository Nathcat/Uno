#include "Uno.h"
#include "Cards.cc"


vector<Card> generateDeck() {  // Create a full Uno deck
  vector<Card> deck;

  deck.push_back(B_0());
  deck.push_back(B_1());
  deck.push_back(B_2());
  deck.push_back(B_3());
  deck.push_back(B_4());
  deck.push_back(B_5());
  deck.push_back(B_6());
  deck.push_back(B_7());
  deck.push_back(B_8());
  deck.push_back(B_9());
  deck.push_back(B_add_2());
  deck.push_back(B_skip());
  deck.push_back(B_reverse());

  deck.push_back(R_0());
  deck.push_back(R_1());
  deck.push_back(R_2());
  deck.push_back(R_3());
  deck.push_back(R_4());
  deck.push_back(R_5());
  deck.push_back(R_6());
  deck.push_back(R_7());
  deck.push_back(R_8());
  deck.push_back(R_9());
  deck.push_back(R_add_2());
  deck.push_back(R_skip());
  deck.push_back(R_reverse());

  deck.push_back(G_0());
  deck.push_back(G_1());
  deck.push_back(G_2());
  deck.push_back(G_3());
  deck.push_back(G_4());
  deck.push_back(G_5());
  deck.push_back(G_6());
  deck.push_back(G_7());
  deck.push_back(G_8());
  deck.push_back(G_9());
  deck.push_back(G_add_2());
  deck.push_back(G_skip());
  deck.push_back(G_reverse());

  deck.push_back(Y_0());
  deck.push_back(Y_1());
  deck.push_back(Y_2());
  deck.push_back(Y_3());
  deck.push_back(Y_4());
  deck.push_back(Y_5());
  deck.push_back(Y_6());
  deck.push_back(Y_7());
  deck.push_back(Y_8());
  deck.push_back(Y_9());
  deck.push_back(Y_add_2());
  deck.push_back(Y_skip());
  deck.push_back(Y_reverse());

  deck.push_back(add_4());
  deck.push_back(add_4());
  deck.push_back(switch());
  deck.push_back(switch());
};


vector<Card> generatePlayerDeck(vector<Card>* deck) {  // Generate a player's deck from a given deck, removing the used cards from the deck
  vector<Card> player;

  while (player.size() != 7) {
    Card choice = NULL;
    int index = NULL;

    while (choice == NULL || count(player.begin(), player.end(), choice)) {
      index = rand() % (deck->size());
      choice = (deck->[index]);
    }

    player.push_back(choice);
    deck->erase(index);

    return player;
  }
};


bool canPlay(Card card, vector<Card> cardsPlayed) {  // Check if card can be played
  Card topCard = cardsPlayed[-1];

  if (card.colour == RESET) {
    return true;
  } else {
    return (topCard.colour == card.colour) || (topCard.name == card.name);
  }
};


int chooseColour() {  // Choose a colour and return it's integer value
  int choice;

  while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
    cout << "\n\nChoose a new colour:\n1. Blue\n2. Red\n3. Yellow\n4. Green\n\n > ";

    cin >> choice;
  }

  return choice - 1;

};


void checkForWin(vector< vector<Card> > playerDecks) {  // Check if a player has won
  for (int x = 0; x < playerDecks.size(); x++) {
    if (playerDecks.size() == 0) {
      cout << "\n\n\n\n\nPlayer " << x << " has won! Congrats!\n";
      exit(0);
    }
  }
};


vector<string> split(string s) {
  vector<string> splitString;

  stringstream ss(s);
  string word;

  while (ss >> word) {
    splitString.push_back(word);
  }

  return splitString;
};


int main() {
  vector<Card> deck = generateDeck();  // Generate a new deck

  // Get the number of playes
  int numberOfPlayers;

  cout << "How many players? > ";
  cin >> numberOfPlayers;

  // Generate the player decks
  vector< vector<Card> > playerDecks;

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
    checkForWin();  // Check if a player has won

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
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])]);
            playerDecks[turnCounter.turn].erase(stoi(command[1]));
            turnCounter.nextTurn();

            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);
            playerDecks[turnCounter.turn].push_back(deck[0]);
            deck.erase(0);

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "+4") {  // Add four cards to the next player's deck and choose a new colour
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])]);
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
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])]);
            playerDecks[turnCounter.turn].erase(stoi(command[1]));
            turnCounter.nextTurn();

            cardsPlayed[-1].colour = chooseColour();

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "reverse") {  // Reverse the direction of play
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])]);
            playerDecks[turnCounter.turn].erase(stoi(command[1]));

            turnCounter.changeDirection();
            turnCounter.nextTurn();

          } else if (playerDecks[turnCounter.turn][stoi(command[1])].name == "skip") {  // Skip the next player's turn
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])]);
            playerDecks[turnCounter.turn].erase(stoi(command[1]));

            turnCounter.nextTurn();
            turnCounter.nextTurn();

          } else {  // If it's any card, just add it to the top of the pile
            cardsPlayed.push_back(playerDecks[turnCounter.turn][stoi(command[1])]);
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
