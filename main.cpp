#include <iostream>
#include <fstream>
using namespace std;

#include "Table.h"
#include "CardFactory.h"


/**
 * Return true if card can be add to one of the player chains
 */
bool addToChain(Player *player, Card *card) {
	bool added = false;
	for (int i = 0; i < player->getNumChains(); i++) {
		Chain &chain = (*player)[i];

		try {
			chain += card;
			added = true;
		} catch (IllegalType &e) {

		}
	}
	return added;
}

/**
 * For all cards in the trade area, player may pick it or not.
 */
void playTradeArea(Table *table, Player *player) {
	string option;
	string cardName;

	while (table->getArea()->numCards() > 0) {
		//trade area is not empty
		cout << "\nTrade Area: " << *table->getArea() << endl;
		player->print(cout, true);
		cout << endl;
		cout << "\npick cards from trade area?(y/n): ";

		cin >> option;

		if (option == "y" || option == "Y") {
			//Add bean cards from the TradeArea to chains
			cout << "\nenter the card to pick: ";
			cin >> cardName;

			Card *card = table->getArea()->trade(cardName);
			if (card == NULL) {
				cout << "\nno card named " << cardName << " in trade area"
						<< endl;
			} else {
				//add to chain
				bool added = addToChain(player, card);
				if (!added) {
					cout << "\nfailed to add " << cardName << " to your chains"
							<< endl;
				}
			}
		} else {
			//discard them
			break;
		}
	}
}

void play(Table *table) {
	string option;
	string cardName;

	string winner;
	while (!table->win(winner)) {

		//if pause
		cout << "\npause and exit?(y/n): ";
		cin >> option;

		if (option == "y" || option == "Y") {
			cout << "enter the path of file: ";
			string path;
			cin >> path;

			ofstream ofs(path);
			table->save(ofs);
			ofs.close();
			return;
		}

		Player *player = table->getCurrentPlayer();

		//for each player

		//Display Table
		cout << *table;

		cout << "\nNow, it's " << player->getName() << " 's round." << endl;

		//Player draws top card from Deck
		player->getHand() += table->getDeck()->draw();

		//check trade area
		playTradeArea(table, player);

		//play top card
		cout << "\nplay the top card" << endl;
		while (player->getHand().size() > 0) {
			Card *top = player->getHand().top();
			if (addToChain(player, top)) {

				player->getHand().play();
				cout << "\ntop card added to chains" << endl;
				player->print(cout, true);
				cout << endl;
			} else {
				//no chain to insert
				if (player->getNumChains() >= player->getMaxNumChains()) {
					//sell a chain
					cout
							<< "\nyou must sell a chain, enter the chain to sell: ";
					string chainName;
					cin >> chainName;

					while (!player->hasChain(chainName)) {
						cout
								<< "you must sell a chain, enter the chain to sell: ";
						cin >> chainName;
					}

					player->sellChain(chainName);
				}

				//start a new chain
				player->buildNewChain(top->getName());
				addToChain(player, top);

				player->getHand().play();
				cout << "\ntop card added to chains" << endl;
				player->print(cout, true);
				cout << endl;
			}

			cout << "\ncontinue to play top card?(y/n): ";
			cin >> option;

			if (option != "y" && option != "Y") {
				break;
			}
		}

		/*
		 * 4. Then, the player has the option of discarding one arbitrary card (in any order) from his/her hand
		 on the discard pile face up.
		 */
		if (player->getHand().size() > 0) {
			cout << "\n" << player->getName() << "'s Hand: ";
			player->printHand(cout, true);

			cout << "\nremove one of your card to discard pile?(y/n): ";
			cin >> option;

			if (option == "y" || option == "Y") {
				cout << "\nenter the card to remove: ";
				cin >> cardName;
				Card *card = player->getHand().removeCard(cardName);
				while (card == NULL) {
					cout << "enter the card to remove: ";
					cin >> cardName;
					card = player->getHand().removeCard(cardName);
				}

				cout << "card '" << card->getName()
						<< "' removed to discard pile" << endl;
				(*table->getPile()) += card;
			}
		}

		//The player draws three cards from the draw deck and places them in the trade area.
		cout << "\ndraw 3 cards from deck to trade area: ";
		for (int i = 0; i < 3; i++) {
			if (table->getDeck()->size() > 0) {
				Card *card = table->getDeck()->draw();
				(*table->getArea()) += card;
				card->print(cout);
				cout << " ";
			}
		}
		cout << endl;
		cout << "Trade Area: " << *table->getArea() << endl;

		/*Next, the player draws cards from the discard pile as long as
		 * the card matches one of the beans in the trade area.
		 */
		cout << "\nDiscard Pile: " << *table->getPile() << endl;
		cout << "draw cards from discard pile: ";
		while (table->getPile()->top() != NULL) {
			if (addToChain(player, table->getPile()->top())) {
				Card *card = table->getPile()->pickUp();
				card->print(cout);
				cout << " ";
			} else {
				break;
			}
		}
		cout << endl;

		playTradeArea(table, player);

		//Draw two cards from Deck and add the cards to the player's hand (at the back).'
		cout << "\ndraw 2 cards from deck to hand: ";
		for (int i = 0; i < 2; i++) {
			if (table->getDeck()->size() > 0) {
				Card *card = table->getDeck()->draw();
				(*table->getArea()) += card;
				card->print(cout);
				cout << " ";
			}
		}
		cout << endl;

		table->toNextPlayer();
	}

	cout << winner << " win!" << endl;

}


void startNewGame() {

	//Input the names of 2 players.
	string name1, name2;
	cout << "Enter the name of player 1: ";
	cin >> name1;
	cout << "Enter the name of player 2: ";
	cin >> name2;

	Table *table = new Table(name1, name2);
	play(table);
	delete table;
}

void loadPausedGame() {
	cout << "Enter data file path: ";
	string path;
	cin >> path;

	ifstream ifs(path);
	if (ifs.is_open()) {
		Table *table = new Table(ifs, CardFactory::getFactory());
		play(table);
		delete table;
	} else {
		cout << "failed to open " << path << endl;
	}
}

int main() {

	while (true) {
		cout << "1. start new game." << endl;
		cout << "2. load paused game from file." << endl;
		cout << "0. quit" << endl;

		string option;
		cin >> option;

		if (option == "1") {
			startNewGame();
		} else if (option == "2") {
			loadPausedGame();
		} else if (option == "0") {
			return 0;
		}
	}

	return 0;
}
