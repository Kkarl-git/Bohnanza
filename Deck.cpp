#include "Deck.h"
#include "CardFactory.h"


Deck::~Deck() {
	for (size_t i = 0; i < size(); i++) {
		delete (this->operator[](i));
	}
}

Deck::Deck(){

}

Deck::Deck(istream &in, const CardFactory *factory) {
	int numCards;
	in >> numCards;
	for (int i = 0; i < numCards; i++) {
		string cardName;
		in >> cardName;
		push_back(factory->getCard(cardName));
	}
}

void Deck::save(ostream &out) {
	out << size() << " ";
	for (size_t i = 0; i < size(); i++) {
		out << (*this)[i]->getName() << " ";
	}
	out << endl;
}

Card* Deck::draw() {
	if (size() > 0) {
		Card *card = this->operator [](0);
		erase(begin());
		return card;
	}
	return NULL;
}

ostream& operator<<(ostream &out, const Deck &deck) {
	for (size_t i = 0; i < deck.size(); i++) {
		out << *deck[i];
		if (i != deck.size() - 1) {
			out << " ";
		}
	}
	return out;
}
