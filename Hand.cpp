#include "Hand.h"
#include "CardFactory.h"

Hand::Hand(istream &in, const CardFactory *factory) {
	int numCards;
	in >> numCards;
	for (int i = 0; i < numCards; i++) {
		string cardName;
		in >> cardName;
		cards.push_back(factory->getCard(cardName));
	}
}

void Hand::save(ostream &out) {
	out << cards.size() << " ";
	for (size_t i = 0; i < cards.size(); i++) {
		out << cards[i]->getName() << " ";
	}
	out << endl;
}

Hand::Hand() {

}

Hand& Hand::operator+=(Card *card) {
	cards.push_back(card);
	return *this;
}

//returns and removes the top card from the player's hand.
Card* Hand::play() {
	Card *top = cards[0];
	cards.erase(cards.begin());
	return top;
}

//returns but does not remove the top card from the player's hand.
Card* Hand::top() const {
	Card *t = cards[0];
	return t;
}

//returns and removes the Card at a given index.
Card* Hand::operator[](int index) const {
	return cards[index];
}

int Hand::size() const {
	return cards.size();
}

Card* Hand::removeCard(string cardName) {
	for (size_t i = 0; i < cards.size(); i++) {
		if (cards[i]->getName()[0] == cardName[0]) {
			Card *card = cards[i];
			cards.erase(cards.begin() + i);
			return card;
		}
	}
	return NULL;
}

void Hand::print(ostream &out, bool all) const {
	for (size_t i = 0; i < cards.size(); i++) {
		if (i == 0) {
			cards[i]->print(out);
		} else {
			if (all) {
				cards[i]->print(out);
			} else {
				out << "*";
			}
		}

		if (i != cards.size() - 1) {
			out << " ";
		}
	}
}

ostream& operator<<(ostream &out, const Hand &hand) {
	for (size_t i = 0; i < hand.cards.size(); i++) {
		hand.cards[i]->print(out);
		if (i != hand.cards.size() - 1) {
			out << " ";
		}
	}
	return out;
}
