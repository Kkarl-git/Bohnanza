#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <string>
using namespace std;

class Card {
private:

public:
	virtual ~Card();

protected:
	int getCardsPerCoin(int coins, int cards1Coin, int cards2Coin, int cards3Coin, int cards4Coin) const;
public:
	//get how many cards are necessary to receive the corresponding number of coins.
	virtual int getCardsPerCoin(int coins) const = 0;

	//get the full name of the card
	virtual string getName() const = 0;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	virtual void print(ostream &out) const = 0;

	//overload insertion operator
	friend ostream& operator<<(ostream &out, const Card &card);
};

class Blue : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Chili : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Stink : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Green : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Soy : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Black : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Red : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

class Garden : public Card{

public:
	//get how many cards are necessary to receive the corresponding number of coins.
	int getCardsPerCoin(int coins) const;

	//get the full name of the card
	string getName() const;

	//inserts the first character for the card into the
	//output stream supplied as argument.
	void print(ostream &out) const;
};

#endif /* CARD_H_ */
