#ifndef TRADEAREA_H_
#define TRADEAREA_H_

#include "Card.h"

#include <list>
using namespace std;

class CardFactory;
class TradeArea {
private:
	list<Card*> cards;
public:
	TradeArea();

	TradeArea(istream &in, const CardFactory *factory);
	void save(ostream &out);

	/*
	 * adds the card to the trade area but it does not check if it
	 is legal to place the card.
	 */
	TradeArea& operator+=(Card *card);

	//returns true if the card can be legally added to the TradeArea
	bool legal(Card *card);

	//removes a card of the corresponding bean name from the trade area.
	Card* trade(string cardName);

	//returns the number of cards currently in the trade area.
	int numCards();

	friend ostream& operator<<(ostream &out, const TradeArea &area);
};

#endif /* TRADEAREA_H_ */
