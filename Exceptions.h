#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include <exception>
using namespace std;

class IllegalType: public exception {
};



class NotEnoughCoins: public exception {
};

#endif /* EXCEPTIONS_H_ */
