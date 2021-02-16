#ifndef PLAYER_H_
#define PLAYER_H_


#include "Hand.h"

#include <string>
#include <vector>
using namespace std;

class Chain;
class Player {
private:
	string name;
	int coins;

	vector<Chain*> chains;
	Hand* hand;

	bool boughtThirdChain;

public:
	// is a constructor that creates a Player with a given name.
	Player(std::string &name);

	// is a constructor which accepts an
	//istream and reconstruct the Player from file.
	Player(istream &in, const CardFactory *factory);
	void save(ostream &out);

	string getName() const;

	int getNumCoins() const;

	//add coins
	Player& operator+=(int coins);

	//returns either 2 or 3.
	int getMaxNumChains() const;

	//returns the number of non-zero chains
	int getNumChains() const;

	//returns the chain at position i.
	Chain& operator[](int i) const;

	Hand& getHand();

	void buildNewChain(string type);

	bool hasChain(string type);

	void sellChain(string type);

	/**
	 * adds an empty third chain to the player for three coins. The
	 functions reduces the coin count for the player by two. If the player does not have enough coins
	 then an exception NotEnoughCoins is thrown.
	 */
	void buyThirdChain(string type);

	void printHand(std::ostream&, bool all) const;

	void print(ostream &out, bool all) const;

	friend ostream& operator<<(ostream &out, const Player &player);
};

#endif /* PLAYER_H_ */
