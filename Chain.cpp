#include "Chain.h"
#include "CardFactory.h"
#include <iomanip>

Chain::Chain(string type) {
	this->type = type;
}

Chain::Chain(istream &in, const CardFactory *factory) {
	int numCards;
	in >> type >> numCards;
	for (int i = 0; i < numCards; i++) {
		string cardName;
		in >> cardName;
		cards.push_back(factory->getCard(cardName));
	}
}

void Chain::save(ostream &out) {
	out << type << " " << cards.size() << " ";
	for (size_t i = 0; i < cards.size(); i++) {
		out << cards[i]->getName() << " ";
	}
	out << endl;
}

Chain& Chain::operator +=(Card *card) {
	if (card->getName() == type) {
		cards.push_back(card);
	} else {
		throw IllegalType();
	}
	return *this;
}

int Chain::sell() {
	if (cards.size() == 0) {
		return 0;
	}

	int price = 0;

	Card *card = cards[0];
	int coins = 0;
	while (true) {
		int numCards = card->getCardsPerCoin(coins);
		if (numCards <= (int) cards.size()) {
			price = coins;
		} else {
			break;
		}
		coins++;
	}
	return price;
}

void Chain::print(ostream &out) const {
	if (cards.size() > 0) {
		Card *card = cards[0];

		out.setf(ios::left);
		out << setw(12) << card->getName();
		out.unsetf(ios::left);
		for (size_t i = 0; i < cards.size(); i++) {
			card->print(out);
			if (i != cards.size() - 1) {
				out << " ";
			}
		}
	}
}

int Chain::size() const {
	return cards.size();
}

const string& Chain::getType() const {
	return type;
}

ostream& operator<<(ostream &out, const Chain &chain) {
	if (chain.cards.size() > 0) {
		Card *card = chain.cards[0];

		out.setf(ios::left);
		out << setw(12) << card->getName();
		out.unsetf(ios::left);
		for (size_t i = 0; i < chain.cards.size(); i++) {
			card->print(out);
			if (i != chain.cards.size() - 1) {
				out << " ";
			}
		}
	}
	return out;
}
