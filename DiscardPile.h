#ifndef DISCARDPILE_H_
#define DISCARDPILE_H_

#include "Card.h"

#include <vector>
using namespace std;

class CardFactory;

class DiscardPile {
private:
	vector<Card*> cards;

public:

	DiscardPile();

	/*
	 * is a constructor which accepts an
	istream and reconstructs the DiscardPile from file.
	 */
	DiscardPile(istream&, const CardFactory *factory);
	void save(ostream &out);

	//discards the card to the pile.
	DiscardPile& operator+=(Card *card);

	//returns and removes the top card from the discard pile.
	Card* pickUp();

	//returns but does not remove the top card from the discard pile.
	Card* top() const;

	//to insert all the cards in the DiscardPile to an ostream.
	void print(std::ostream &out) const;

	friend ostream& operator<<(ostream &out, const DiscardPile &pile);
};

#endif /* DISCARDPILE_H_ */
