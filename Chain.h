#ifndef CHAIN_H_
#define CHAIN_H_

#include "Card.h"
#include <vector>
#include <iomanip>

#include "Exceptions.h"
using namespace std;

class CardFactory;
class Chain {
	string type;

	vector<Card*> cards;
public:
	Chain(string type);

	/**
	 * constructor which accepts an
	 istream and reconstructs the chain from file when a game is resumed.
	 */
	Chain(istream &in, const CardFactory *factory);
	void save(ostream &out);

	/*
	 * adds a card to the Chain
	 * If the run-time type does not
	 match the template type of the chain and exception of
	 type IllegalType needs to be raised.
	 */
	Chain& operator+=(Card *card);

	//counts the number cards in the current chain and returns the number coins
	int sell();

	void print(ostream &out) const;

	int size() const;

	friend ostream& operator<<(ostream &out, const Chain &chain);
	const string& getType() const;
};


#endif /* CHAIN_H_ */
