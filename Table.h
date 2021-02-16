#ifndef TABLE_H_
#define TABLE_H_

#include "Player.h"
#include "Deck.h"
#include "DiscardPile.h"
#include "TradeArea.h"
#include "Chain.h"

class Table {
private:
	vector<Player*> players;
	int curPlayer;

	Deck *deck;
	DiscardPile *pile;
	TradeArea *area;
public:
	Table(string namePlayer1, string namePlayer2);

	Table(istream &in, const CardFactory *factory);
	void save(ostream &out);

	bool win(std::string &name) const;

	Player* getCurrentPlayer() const;

	void toNextPlayer();

	void printHand(bool all) const;

	friend ostream& operator<<(ostream &out, const Table &table);

	TradeArea* getArea();
	int getCurPlayer();
	Deck* getDeck();
	DiscardPile* getPile();
};

#endif /* TABLE_H_ */
