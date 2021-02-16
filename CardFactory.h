#ifndef CARDFACTORY_H_
#define CARDFACTORY_H_

#include <string>
using namespace std;

class Deck;
class Card;

class CardFactory {
private:
	static CardFactory* factory;

public:
	//returns a pointer to the only instance of	CardFactory.
	static CardFactory* getFactory();

	//returns a deck with all 104 bean cards.
	Deck* getDeck() const;

	Card* getCard(string cardName) const;
};

#endif /* CARDFACTORY_H_ */
