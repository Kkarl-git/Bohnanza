#include "TradeArea.h"
#include "CardFactory.h"

TradeArea::TradeArea(istream &in, const CardFactory *factory) {
	int numCards;
	in >> numCards;
	for (int i = 0; i < numCards; i++) {
		string cardName;
		in >> cardName;
		cards.push_back(factory->getCard(cardName));
	}
}

void TradeArea::save(ostream &out) {
	out << cards.size() << " ";

	list<Card*>::iterator it = cards.begin();
	while (it != cards.end()) {
		out << (*it)->getName() << " ";
		it++;
	}

	out << endl;
}

TradeArea::TradeArea(){

}

/*
 * adds the card to the trade area but it does not check if it
 is legal to place the card.
 */
TradeArea& TradeArea::operator+=(Card *card) {
	cards.push_back(card);
	return *this;
}

//returns true if the card can be legally added to the TradeArea
bool TradeArea::legal(Card *card) {
	list<Card*>::iterator it = cards.begin();
	while (it != cards.end()) {
		if ((*it)->getName() == card->getName()) {
			return true;
		}
		it++;
	}
	return false;
}

//removes a card of the corresponding bean name from the trade area.
Card* TradeArea::trade(string cardName) {
	list<Card*>::iterator it = cards.begin();
	while (it != cards.end()) {
		if ((*it)->getName()[0] == cardName[0]) {
			Card *card = *it;
			cards.erase(it);
			return card;
		}
		it++;
	}
	return NULL;
}

//returns the number of cards currently in the trade area.
int TradeArea::numCards() {
	return cards.size();
}

ostream& operator<<(ostream &out, const TradeArea &area) {
	auto it = area.cards.begin();
	while (it != area.cards.end()) {
		Card *card = *it;
		card->print(out);
		it++;
		if (it != area.cards.end()) {
			out << " ";
		}
	}
	return out;
}
