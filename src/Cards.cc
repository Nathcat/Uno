#include "Uno.h"


class Card {  // Card parent class
  public:
    string colour;
    string name;

    string toString() {
      return (colour + name + RESET);
    }

    bool isEqual(Card other) {
      return (other.colour == colour) && (other.name == name);
    }
};


// Blue cards

class B_0: public Card {
  public: B_0() {
    colour = BLU;
    name = "0";
  }
};


class B_1: public Card {
  public: B_1() {
    colour = BLU;
    name = "1";
  }
};


class B_2: public Card {
  public: B_2() {
    colour = BLU;
    name = "2";
  }
};


class B_3: public Card {
  public: B_3() {
    colour = BLU;
    name = "3";
  }
};


class B_4: public Card {
  public: B_4() {
    colour = BLU;
    name = "4";
  }
};


class B_5: public Card {
  public: B_5() {
    colour = BLU;
    name = "5";
  }
};


class B_6: public Card {
  public: B_6() {
    colour = BLU;
    name = "6";
  }
};


class B_7: public Card {
  public: B_7() {
    colour = BLU;
    name = "7";
  }
};


class B_8: public Card {
  public: B_8() {
    colour = BLU;
    name = "8";
  }
};


class B_9: public Card {
  public: B_9() {
    colour = BLU;
    name = "9";
  }
};


class B_add_2: public Card {
  public: B_add_2() {
    colour = BLU;
    name = "+2";
  }
};


class B_skip: public Card {
  public: B_skip() {
    colour = BLU;
    name = "skip";
  }
};


class B_reverse: public Card {
  public: B_reverse() {
    colour = BLU;
    name = "reverse";
  }
};


// Red cards

class R_0: public Card {
  public: R_0() {
    colour = RED;
    name = "0";
  }
};


class R_1: public Card {
  public: R_1() {
    colour = RED;
    name = "1";
  }
};


class R_2: public Card {
  public: R_2() {
    colour = RED;
    name = "2";
  }
};


class R_3: public Card {
  public: R_3() {
    colour = RED;
    name = "3";
  }
};


class R_4: public Card {
  public: R_4() {
    colour = RED;
    name = "4";
  }
};


class R_5: public Card {
  public: R_5() {
    colour = RED;
    name = "5";
  }
};


class R_6: public Card {
  public: R_6() {
    colour = RED;
    name = "6";
  }
};


class R_7: public Card {
  public: R_7() {
    colour = RED;
    name = "7";
  }
};


class R_8: public Card {
  public: R_8() {
    colour = RED;
    name = "8";
  }
};


class R_9: public Card {
  public: R_9() {
    colour = RED;
    name = "9";
  }
};


class R_add_2: public Card {
  public: R_add_2() {
    colour = RED;
    name = "+2";
  }
};


class R_skip: public Card {
  public: R_skip() {
    colour = RED;
    name = "skip";
  }
};


class R_reverse: public Card {
  public: R_reverse() {
    colour = RED;
    name = "reverse";
  }
};


// Green cards

class G_0: public Card {
  public: G_0() {
    colour = GRN;
    name = "0";
  }
};


class G_1: public Card {
  public: G_1() {
    colour = GRN;
    name = "1";
  }
};


class G_2: public Card {
  public: G_2() {
    colour = GRN;
    name = "2";
  }
};


class G_3: public Card {
  public: G_3() {
    colour = GRN;
    name = "3";
  }
};


class G_4: public Card {
  public: G_4() {
    colour = GRN;
    name = "4";
  }
};


class G_5: public Card {
  public: G_5() {
    colour = GRN;
    name = "5";
  }
};


class G_6: public Card {
  public: G_6() {
    colour = GRN;
    name = "6";
  }
};


class G_7: public Card {
  public: G_7() {
    colour = GRN;
    name = "7";
  }
};


class G_8: public Card {
  public: G_8() {
    colour = GRN;
    name = "8";
  }
};


class G_9: public Card {
  public: G_9() {
    colour = GRN;
    name = "9";
  }
};


class G_add_2: public Card {
  public: G_add_2() {
    colour = GRN;
    name = "+2";
  }
};


class G_skip: public Card {
  public: G_skip() {
    colour = GRN;
    name = "skip";
  }
};


class G_reverse: public Card {
  public: G_reverse() {
    colour = GRN;
    name = "reverse";
  }
};


// Yellow cards

class Y_0: public Card {
  public: Y_0() {
    colour = YEL;
    name = "0";
  }
};


class Y_1: public Card {
  public: Y_1() {
    colour = YEL;
    name = "1";
  }
};


class Y_2: public Card {
  public: Y_2() {
    colour = YEL;
    name = "2";
  }
};


class Y_3: public Card {
  public: Y_3() {
    colour = YEL;
    name = "3";
  }
};


class Y_4: public Card {
  public: Y_4() {
    colour = YEL;
    name = "4";
  }
};


class Y_5: public Card {
  public: Y_5() {
    colour = YEL;
    name = "5";
  }
};


class Y_6: public Card {
  public: Y_6() {
    colour = YEL;
    name = "6";
  }
};


class Y_7: public Card {
  public: Y_7() {
    colour = YEL;
    name = "7";
  }
};


class Y_8: public Card {
  public: Y_8() {
    colour = YEL;
    name = "8";
  }
};


class Y_9: public Card {
  public: Y_9() {
    colour = YEL;
    name = "9";
  }
};


class Y_add_2: public Card {
  public: Y_add_2() {
    colour = YEL;
    name = "+2";
  }
};


class Y_skip: public Card {
  public: Y_skip() {
    colour = YEL;
    name = "skip";
  }
};


class Y_reverse: public Card {
  public: Y_reverse() {
    colour = YEL;
    name = "reverse";
  }
};


// Special cards

class add_4: public Card {
  public: add_4() {
    colour = RESET;
    name = "+4";
  }
};


class switch_colour: public Card {
  public: switch_colour() {
    colour = RESET;
    name = "switch";
  }
};


// Methods

vector<Card> generateDeck() {  // Generate a full Uno game deck
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
  deck.push_back(switch_colour());
  deck.push_back(switch_colour());

  return deck;
};


vector<Card> generatePlayerDeck(vector<Card>* deck) {  // Generate a deck for the player and update the game deck accordingly
  vector<Card> player;

  while (player.size() != 7) {
    int index = rand() % (deck->size());

    player.push_back((*deck)[index]);

    deck->erase(deck->begin() + index);
  }

  return player;
};


void displayDeck(vector<Card> deck) {  // Display a given deck of cards (deck)
  for (int x = 0; x < deck.size(); x++) {
    cout << deck[x].toString() << ", ";
  }

  cout << endl;
};


class TurnCounter {  // Object to track which player's turn it is
  private:
    int direction = 1;
    int numberOfPlayers;

  public:
    int turn = 0;

    TurnCounter(int number_of_players) {
      numberOfPlayers = number_of_players - 1;
    }

    void nextTurn() {  // Move to the next player's turn
      turn += direction;

      if (turn > numberOfPlayers) {
        turn = 0;
      } else if (turn < 0) {
        turn = numberOfPlayers;
      }
    }

    void changeDirection() {  // Toggle direction
      if (direction == 1) {
        direction = -1;
      } else {
        direction = 1;
      }
    }
};


string chooseColour() {  // Allow the player to choose a new colour
  cout << endl << endl << "Choose a new colour:" << endl << "1. Blue" << endl << "2. Red" << endl << "3. Green" << endl << "4. Yellow" << endl << endl;

  int choice;

  while (true) {
    cout << "Enter the number corresponding to your choice > ";
    cin >> choice;

    if (choice == 1) {
      return BLU;
    } else if (choice == 2) {
      return RED;
    } else if (choice == 3) {
      return GRN;
    } else if (choice == 4) {
      return YEL;
    } else {
      cout << endl << endl << "Invalid choice, please choose 1, 2, 3, or 4" << endl << endl;
    }
  }
};


bool canPlay(vector<Card> cardsPlayed, Card card) {  // Check if the given card (card) can be played
  Card topCard = cardsPlayed[cardsPlayed.size() - 1];

  bool colour = topCard.colour == card.colour;
  bool name = topCard.name == card.name;
  bool isReset = card.colour == RESET;

  return colour || name || isReset;
}


vector<Card> shuffle(vector<Card> deck) {  // Shuffle the deck
  vector<Card> newDeck;

  while (deck.size() != 0) {
    int index = rand() % deck.size();
    newDeck.push_back(deck[index]);

    deck.erase(deck.begin() + index);
  }

  return newDeck;
}
