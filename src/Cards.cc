#include "Uno.h"

class Colours {  // Class to translate colour int into ANSI escape code for that colour
public :
  int BLUE = 0;
  int RED = 1;
  int YELLOW = 2;
  int GREEN = 3;
  int RESET = 4;

  string[] colours = {"\u001b[34m", "\u001b[31m", "\u001b[33m", "\u001b[32m", "\u001b[0m"};  // Blue, red, yellow, green, reset
};


class Card {  // Card parent class
public:
  int colour;  // The colour of this card represented by an int
  string name;  // The name of this card

  string toString() {  // Get a string for this card
    return Colours.colours[colour] + name + Colours.colours[-1];
  }

  string equalTo(Card other) {  // Check if the parameter other is the same as this card
    return (other.colour == colour) && (other.name == name)
  }
};


// Blue Cards

class B_0: public Card {
  public: B_0() {
    colour = Colours.BLUE;
    name = "0";
  }
};


class B_1: public Card {
  public: B_1() {
    colour = Colours.BLUE;
    name = "1";
  }
};


class B_2: public Card {
  public: B_2() {
    colour = Colours.BLUE;
    name = "2";
  }
};


class B_3: public Card {
  public: B_3() {
    colour = Colours.BLUE;
    name = "3";
  }
};


class B_4: public Card {
  public: B_4() {
    colour = Colours.BLUE;
    name = "4";
  }
};



class B_5: public Card {
  public: B_5() {
    colour = Colours.BLUE;
    name = "5";
  }
};



class B_6: public Card {
  public: B_6() {
    colour = Colours.BLUE;
    name = "6";
  }
};


class B_7: public Card {
  public: B_7() {
    colour = Colours.BLUE;
    name = "7";
  }
};


class B_8: public Card {
  public: B_8() {
    colour = Colours.BLUE;
    name = "8";
  }
};


class B_9: public Card {
  public: B_9() {
    colour = Colours.BLUE;
    name = "9";
  }
};


class B_add_2: public Card {
  public: B_add_2() {
    colour = Colours.BLUE;
    name = "+2";
  }
};


class B_reverse: public Card {
  public: B_reverse() {
    colour = Colours.BLUE;
    name = "reverse";
  }
};


class B_skip: public Card {
  public: B_skip() {
    colour = Colours.BLUE;
    name = "skip";
  }
};


// Red cards


class R_0: public Card {
  public: R_0() {
    colour = Colours.RED;
    name = "0";
  }
};


class R_1: public Card {
  public: R_1() {
    colour = Colours.RED;
    name = "1";
  }
};


class R_2: public Card {
  public: R_2() {
    colour = Colours.RED;
    name = "2";
  }
};


class R_3: public Card {
  public: R_3() {
    colour = Colours.RED;
    name = "3";
  }
};


class R_4: public Card {
  public: R_4() {
    colour = Colours.RED;
    name = "4";
  }
};



class R_5: public Card {
  public: R_5() {
    colour = Colours.RED;
    name = "5";
  }
};



class R_6: public Card {
  public: R_6() {
    colour = Colours.RED;
    name = "6";
  }
};


class R_7: public Card {
  public: R_7() {
    colour = Colours.RED;
    name = "7";
  }
};


class R_8: public Card {
  public: R_8() {
    colour = Colours.RED;
    name = "8";
  }
};


class R_9: public Card {
  public: R_9() {
    colour = Colours.RED;
    name = "9";
  }
};


class R_add_2: public Card {
  public: R_add_2() {
    colour = Colours.RED;
    name = "+2";
  }
};


class R_reverse: public Card {
  public: R_reverse() {
    colour = Colours.RED;
    name = "reverse";
  }
};


class R_skip: public Card {
  public: R_skip() {
    colour = Colours.RED;
    name = "skip";
  }
};


// Green Cards

class G_0: public Card {
  public: G_0() {
    colour = Colours.GREEN;
    name = "0";
  }
};


class G_1: public Card {
  public: G_1() {
    colour = Colours.GREEN;
    name = "1";
  }
};


class G_2: public Card {
  public: G_2() {
    colour = Colours.GREEN;
    name = "2";
  }
};


class G_3: public Card {
  public: G_3() {
    colour = Colours.GREEN;
    name = "3";
  }
};


class G_4: public Card {
  public: G_4() {
    colour = Colours.GREEN;
    name = "4";
  }
};



class G_5: public Card {
  public: G_5() {
    colour = Colours.GREEN;
    name = "5";
  }
};



class G_6: public Card {
  public: G_6() {
    colour = Colours.GREEN;
    name = "6";
  }
};


class G_7: public Card {
  public: G_7() {
    colour = Colours.GREEN;
    name = "7";
  }
};


class G_8: public Card {
  public: G_8() {
    colour = Colours.GREEN;
    name = "8";
  }
};


class G_9: public Card {
  public: G_9() {
    colour = Colours.GREEN;
    name = "9";
  }
};


class G_add_2: public Card {
  public: G_add_2() {
    colour = Colours.GREEN;
    name = "+2";
  }
};


class G_reverse: public Card {
  public: G_reverse() {
    colour = Colours.GREEN;
    name = "reverse";
  }
};


class G_skip: public Card {
  public: G_skip() {
    colour = Colours.GREEN;
    name = "skip";
  }
};


// Yellow cards


class Y_0: public Card {
  public: Y_0() {
    colour = Colours.YELLOW;
    name = "0";
  }
};


class Y_1: public Card {
  public: Y_1() {
    colour = Colours.YELLOW;
    name = "1";
  }
};


class Y_2: public Card {
  public: Y_2() {
    colour = Colours.YELLOW;
    name = "2";
  }
};


class Y_3: public Card {
  public: Y_3() {
    colour = Colours.YELLOW;
    name = "3";
  }
};


class Y_4: public Card {
  public: Y_4() {
    colour = Colours.YELLOW;
    name = "4";
  }
};



class Y_5: public Card {
  public: Y_5() {
    colour = Colours.YELLOW;
    name = "5";
  }
};



class Y_6: public Card {
  public: Y_6() {
    colour = Colours.YELLOW;
    name = "6";
  }
};


class Y_7: public Card {
  public: Y_7() {
    colour = Colours.YELLOW;
    name = "7";
  }
};


class Y_8: public Card {
  public: Y_8() {
    colour = Colours.YELLOW;
    name = "8";
  }
};


class Y_9: public Card {
  public: Y_9() {
    colour = Colours.YELLOW;
    name = "9";
  }
};


class Y_add_2: public Card {
  public: Y_add_2() {
    colour = Colours.YELLOW;
    name = "+2";
  }
};


class Y_reverse: public Card {
  public: Y_reverse() {
    colour = Colours.YELLOW;
    name = "reverse";
  }
};


class Y_skip: public Card {
  public: Y_skip() {
    colour = Colours.YELLOW;
    name = "skip";
  }
};


// Special Cards


class add_4: public Card {
  public: add_4() {
    colour = Colours.RESET;
    name = "+4";
  }
};


class switch: public Card {
  public: switch() {
    colour = Colours.RESET;
    name = "switch";
  }
}


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


class TurnCounter {  // Object to track which player's turn it is
  private:
    int direction = 1;  // Represents the direction of play
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

    void changeDirection() {  // Toggle the direction of play
      direction *= -1;
    }
};


vector<Card> generatePlayerDeck(vector<Card>* deck) {  // Generate a player's deck from a given deck, removing the used cards from the deck
  vector<Card> player;

  while (player.size() != 7) {
    Card choice = null;
    int index = null;

    while (choice == null || count(player.begin(), player.end(), choice)) {
      index = rand() % *deck.size();
      choice = *deck[index];
    }

    player.push_back(choice);
    *deck.erase(index);

    return player;
  }
};


bool canPlay(Card card, vector<Card> cardsPlayed) {  // Check if card can be played
  Card topCard = cardsPlayed[-1];

  if (card.colour == Colours.RESET) {
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


void checkForWin(vector<vector<Card>> playerDecks) {  // Check if a player has won
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
