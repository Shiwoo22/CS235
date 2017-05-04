/***********************************************************************
 * Header:
 *    STOCK
 * Summary:
 *    This will contain just the prototype for stocksBuySell(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef STOCK_H
#define STOCK_H

#include "dollars.h"   // for Dollars defined in StockTransaction
#include "queue.h"     // for QUEUE
#include <iostream>    // for ISTREAM and OSTREAM

// the interactive stock buy/sell function
void stocksBuySell();

template <class T>
class Stock
{
public:
   
private:
   int quantity;
   double buy, sell;
};

// Menu structure
enum eMenu
{
   BUY,
   SELL,
   DISPLAY,
   QUIT,
   MAX_VAL
};

//Menu Function
eMenu string2enum(string word );

#endif // STOCK_H
