#ifndef HAND_H_
#define HAND_H_

#include "Card.h"

#include <vector>
using namespace std;

class CardFactory;

class Hand {
private:
	vector<Card*> cards;
public:
	Hand();

	Hand(istream &in, const CardFactory *factory);
	void save(ostream &out);

	Hand& operator+=(Card *card);

	//returns and removes the top card from the player's hand.
	Card* play();

	//returns but does not remove the top card from the player's hand.
	Card* top() const;

	//returns and removes the Card at a given index.
	Card* operator[](int index) const;

	int size() const;

	Card* removeCard(string cardName);

	void print(ostream& out, bool all) const;

	friend ostream& operator<<(ostream &out, const Hand &hand);
};

#endif /* HAND_H_ */
