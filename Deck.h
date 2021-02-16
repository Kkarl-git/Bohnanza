#ifndef DECK_H_
#define DECK_H_

#include "Card.h"


#include <vector>
using namespace std;

class CardFactory;

class Deck : public vector<Card*> {
public:
	Deck();
	~Deck();

	Deck(istream &in, const CardFactory *factory);
	void save(ostream &out);

	//returns and removes the top card from the deck.
	Card* draw();

	friend ostream& operator<<(ostream &out, const Deck &deck);
};

#endif /* DECK_H_ */
