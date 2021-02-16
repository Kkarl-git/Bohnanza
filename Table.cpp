#include "Table.h"
#include "CardFactory.h"

#include <fstream>

Table::Table(string namePlayer1, string namePlayer2) {
	players.push_back(new Player(namePlayer1));
	players.push_back(new Player(namePlayer2));
	curPlayer = 0;

	//Initialize the Deck and draw 5 cards for the Hand of each Player
	deck = CardFactory::getFactory()->getDeck();
	for (int i = 0; i < 5; i++) {
		players[0]->getHand() += (deck->draw());
		players[1]->getHand() += (deck->draw());
	}

	area = new TradeArea();
	pile = new DiscardPile();
}

Table::Table(istream &in, const CardFactory *factory) {
	curPlayer = 0;

	in >> curPlayer;

	players.push_back(new Player(in, factory));
	players.push_back(new Player(in, factory));

	deck = new Deck(in, factory);
	area = new TradeArea(in, factory);
	pile = new DiscardPile(in, factory);
}

void Table::save(ostream &out) {
	out << curPlayer << endl;
	players[0]->save(out);
	players[1]->save(out);
	deck->save(out);
	pile->save(out);
	area->save(out);
}

Player* Table::getCurrentPlayer() const{
	return players[curPlayer];
}

void Table::toNextPlayer() {
	curPlayer++;
	curPlayer %= 2;
}

bool Table::win(std::string &name) const {
	if (deck->size() == 0) {
		if (players[0]->getNumCoins() > players[1]->getNumCoins()) {
			name = players[0]->getName();
		} else {
			name = players[1]->getName();
		}
		return true;
	} else {
		return false;
	}
}

void Table::printHand(bool all) const {
	players[0]->printHand(cout, all);
	players[1]->printHand(cout, all);
}

 TradeArea* Table::getArea()  {
	return area;
}

int Table::getCurPlayer()  {
	return curPlayer;
}

 Deck* Table::getDeck()  {
	return deck;
}

 DiscardPile* Table::getPile()  {
	return pile;
}

ostream& operator<<(ostream &out, const Table &table) {
	out << "Table: " << endl;
	out << *table.players[0] << endl;
	out << *table.players[1] << endl;
	out << "Trade Area: " << *table.area << endl;
	out << "Discard Pile: " << *table.pile << endl;

	return out;
}

