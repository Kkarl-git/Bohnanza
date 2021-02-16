#include "CardFactory.h"
#include "Deck.h"
#include "Card.h"

#include <algorithm>
#include <ctime>
#include <random> // std::default_random_engine

CardFactory *CardFactory::factory = NULL;

CardFactory* CardFactory::getFactory() {
	if (factory == NULL) {
		factory = new CardFactory();
	}
	return factory;
}

Card* CardFactory::getCard(string cardName) const{
	if (cardName == "Blue") {
		return new Blue();
	}
	if (cardName == "Chili") {
		return new Chili();
	}
	if (cardName == "Stink") {
		return new Stink();
	}
	if (cardName == "Green") {
		return new Green();
	}
	if (cardName == "soy") {
		return new Soy();
	}
	if (cardName == "black") {
		return new Black();
	}
	if (cardName == "Red") {
		return new Red();
	}
	if (cardName == "garden") {
		return new Garden();
	}

	return NULL;
}

Deck* CardFactory::getDeck() const {
	Deck *deck = new Deck();

	/*
	 Blue 20
	 Chili 18
	 Stink 16
	 Green 14
	 soy 12
	 black 10
	 Red 8
	 garden 6
	 */

	for (int i = 0; i < 20; i++) {
		deck->push_back(new Blue());
	}
	for (int i = 0; i < 18; i++) {
		deck->push_back(new Chili());
	}
	for (int i = 0; i < 16; i++) {
		deck->push_back(new Stink());
	}
	for (int i = 0; i < 14; i++) {
		deck->push_back(new Green());
	}
	for (int i = 0; i < 12; i++) {
		deck->push_back(new Soy());
	}
	for (int i = 0; i < 10; i++) {
		deck->push_back(new Black());
	}
	for (int i = 0; i < 8; i++) {
		deck->push_back(new Red());
	}
	for (int i = 0; i < 6; i++) {
		deck->push_back(new Garden());
	}

	std::shuffle(deck->begin(), deck->end(),
			std::default_random_engine(time(NULL)));
	return deck;
}
