#include "DiscardPile.h"
#include "CardFactory.h"

DiscardPile::DiscardPile(istream &in, const CardFactory *factory) {
	int numCards;
	in >> numCards;
	for (int i = 0; i < numCards; i++) {
		string cardName;
		in >> cardName;
		cards.push_back(factory->getCard(cardName));
	}
}

void DiscardPile::save(ostream &out) {
	out << cards.size() << " ";
	for (size_t i = 0; i < cards.size(); i++) {
		out << cards[i]->getName() << " ";
	}
	out << endl;
}

DiscardPile::DiscardPile() {

}

DiscardPile& DiscardPile::operator +=(Card *card) {
	cards.insert(cards.begin(), card);
	return *this;
}

Card* DiscardPile::pickUp() {
	Card *card = cards[cards.size() - 1];
	cards.erase(cards.begin() + cards.size() - 1);
	return card;
}

Card* DiscardPile::top() const {
	if(cards.size() == 0){
		return NULL;
	}

	Card *card = cards[cards.size() - 1];
	return card;
}

void DiscardPile::print(std::ostream &out) const {
	for (size_t i = 0; i < cards.size(); i++) {
		if (i == 0) {
			cards[i]->print(out);
		} else {
			out << "*";
		}
		if (i != cards.size() - 1) {
			out << " ";
		}
	}
}

ostream& operator<<(ostream &out, const DiscardPile &pile) {
	pile.print(out);
	return out;
}
