#include "Card.h"

//overload insertion operator
ostream& operator<<(ostream &out, const Card &card) {
	card.print(out);
	return out;
}

Card::~Card() {
}

int Card::getCardsPerCoin(int coins, int cards1Coin, int cards2Coin,
		int cards3Coin, int cards4Coin) const {
	int sum = 0;
	while (coins >= 4) {
		sum += cards4Coin;
		coins -= 4;
	}
	while (coins >= 3) {
		sum += cards3Coin;
		coins -= 3;
	}
	while (coins >= 2) {
		sum += cards2Coin;
		coins -= 2;
	}
	while (coins >= 1) {
		sum += cards1Coin;
		coins -= 1;
	}
	return sum;
}

int Blue::getCardsPerCoin(int coins) const {
	//4 6 8 10
	return Card::getCardsPerCoin(coins, 4, 6, 8, 10);
}

string Blue::getName() const {
	return "Blue";
}

void Blue::print(ostream &out) const {
	out << "B";
}

int Chili::getCardsPerCoin(int coins) const {
	//3 6 8 9
	return Card::getCardsPerCoin(coins, 3, 6, 8, 9);
}

string Chili::getName() const {
	return "Chili";
}

void Chili::print(ostream &out) const {
	out << "C";
}

int Stink::getCardsPerCoin(int coins) const {
	//3 5 7 8
	return Card::getCardsPerCoin(coins, 3, 5, 7, 8);
}

string Stink::getName() const {
	return "Stink";
}

void Stink::print(ostream &out) const {
	out << "S";
}

int Green::getCardsPerCoin(int coins) const {
	//3 5 6 7
	return Card::getCardsPerCoin(coins, 3, 5, 6, 7);
}

string Green::getName() const {
	return "Green";
}

void Green::print(ostream &out) const {
	out << "G";
}

int Soy::getCardsPerCoin(int coins) const {
	//2 4 6 7
	return Card::getCardsPerCoin(coins, 2, 4, 6, 7);
}

string Soy::getName() const {
	return "soy";
}

void Soy::print(ostream &out) const {
	out << "s";
}

int Black::getCardsPerCoin(int coins) const {
	//2 4 5 6
	return Card::getCardsPerCoin(coins, 2, 4, 5, 6);
}

string Black::getName() const {
	return "black";
}

void Black::print(ostream &out) const {
	out << "b";
}

int Red::getCardsPerCoin(int coins) const {
	//2 3 4 5
	return Card::getCardsPerCoin(coins, 2, 3, 4, 5);
}

string Red::getName() const {
	return "Red";
}

void Red::print(ostream &out) const {
	out << "R";
}

int Garden::getCardsPerCoin(int coins) const {
	//2 3
	int sum = 0;
	while (coins >= 3) {
		sum += 3;
		coins -= 3;
	}
	while (coins >= 2) {
		sum += 2;
		coins -= 2;
	}
	return sum;
}

string Garden::getName() const {
	return "garden";
}

void Garden::print(ostream &out) const {
	out << "g";
}
