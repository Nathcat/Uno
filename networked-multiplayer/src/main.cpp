#include "Uno.h"
#include "Cards.cc"


int main() {
  // Seed the random generator
  srand(time(NULL));

  // Create a server socket
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "Hello from server";

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FALIURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit (EXIT_FALIURE);
  }

  // Listen for a connection
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FALIURE);
  }

  // Accept the connection
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
    perror("accept");
    exit(EXIT_FALIURE);
  }

  // Create a new deck for the game and shuffle it
  vector<Card> deck;
  deck = generateDeck();
  deck = shuffle(deck);

  // Networked multiplayer currently only supports 2 players
  int numberOfPlayers = 2;

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

    if (turnCounter.turn != 1) {
      cout << endl << endl << endl << endl << endl;
      cout << "--------------------" << endl;
      cout << "It's player " << turnCounter.turn << "'s turn!" << endl << endl;

      cout << cardsPlayed[cardsPlayed.size() - 1].toString() << endl << endl;

      cout << displayDeck(playerDecks[turnCounter.turn]) << endl;

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

    } else {
      // Network player's turn
      // Get the turn string
      string turnString;
      turnString += endl + endl + endl + endl + endl;
      turnString += "--------------------" + endl;
      turnString += "It's player " + turnCounter.turn + "'s turn!" + endl + endl;

      turnString += cardsPlayed[cardsPlayed.size() - 1].toString() + endl + endl;

      turnString += displayDeck(playerDecks[turnCounter.turn]) + endl;

      // Send the turnString to the network player
    }

  }

  return 0;
}
