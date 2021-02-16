#include "Player.h"
#include "Chain.h"

#include <iomanip>

// is a constructor that creates a Player with a given name.
Player::Player(std::string &name) {
	this->name = name;
	coins = 0;
	boughtThirdChain = false;
	hand = new Hand();
}

// is a constructor which accepts an
//istream and reconstruct the Player from file.
Player::Player(istream &in, const CardFactory *factory) {
	boughtThirdChain = false;
	coins = 0;

	in >> name >> coins >> boughtThirdChain;
	int numChains;
	in >> numChains;
	for(int i=0;i<numChains;i++){
		chains.push_back(new Chain(in, factory));
	}
	hand = new Hand(in, factory);
}

void Player::save(ostream &out){
	out << name << " " << coins << " " << boughtThirdChain << endl;
	out << chains.size() << endl;
	for(size_t i=0;i<chains.size();i++){
		chains[i]->save(out);
	}
	hand->save(out);
}

string Player::getName() const {
	return name;
}

int Player::getNumCoins() const {
	return coins;
}

//add coins
Player& Player::operator+=(int coins) {
	this->coins += coins;
	return *this;
}

//returns either 2 or 3.
int Player::getMaxNumChains() const {
	if (boughtThirdChain) {
		return 3;
	} else {
		return 2;
	}
}

//returns the number of non-zero chains
int Player::getNumChains() const {
	return chains.size();
}

Hand& Player::getHand() {
	return *hand;
}

//returns the chain at position i.
Chain& Player::operator[](int i) const {
	return *chains[i];
}

void Player::buildNewChain(string type) {
	chains.push_back(new Chain(type));
}

bool Player::hasChain(string type) {
	for (int i = 0; i < getNumChains(); i++) {
		if (chains[i]->getType() == type) {
			return true;
		}
	}
	return false;
}

void Player::sellChain(string type) {
	int index = -1;
	for (int i = 0; i < getNumChains(); i++) {
		if (chains[i]->getType() == type) {
			index = i;
		}
	}

	if (index != -1) {
		coins += chains[index]->sell();
		chains.erase(chains.begin() + index);
	}
}

/**
 * adds an empty third chain to the player for three coins. The
 functions reduces the coin count for the player by two. If the player does not have enough coins
 then an exception NotEnoughCoins is thrown.
 */
void Player::buyThirdChain(string type) {
	if (coins >= 3) {
		coins -= 3;
		boughtThirdChain = true;
	} else {
		throw NotEnoughCoins();
	}
}

void Player::printHand(std::ostream &out, bool all) const {
	if (hand->size() > 0) {
		hand->print(out, all);
	} else {
		out << "No cards in hand.";
	}
}

void Player::print(ostream &out, bool all) const{
	out << getName() << "  ";
	out << coins << " coins" << endl;
	out << "Hand: ";
	printHand(out, all);

	int i = 0;
	for (i = 0; i < getNumChains(); i++) {
		out << endl;
		out << "Chain " << i + 1 << ": ";
		chains[i]->print(out);
	}
	for (; i < getMaxNumChains(); i++) {
		out << endl;
		out << "Chain " << i + 1 << ": ";
	}
}

ostream& operator<<(ostream &out, const Player &player) {
	out << player.getName() << "  ";
	out << player.coins << " coins" << endl;
	out << "Hand: ";
	player.printHand(out, false);

	int i = 0;
	for (i = 0; i < player.getNumChains(); i++) {
		out << endl;
		out << "Chain " << i + 1 << ": ";
		player.chains[i]->print(out);
	}
	for (; i < player.getMaxNumChains(); i++) {
		out << endl;
		out << "Chain " << i + 1 << ": ";
	}

	return out;
}
