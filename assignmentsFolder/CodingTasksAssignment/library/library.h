#ifndef __LIBRARY_H_
#define __LIBRARY_H_

#include "book.h"
#include <list>
#include <vector>
#include<algorithm>
#include <bits/stdc++.h>
#include<numeric>

class BookDB
{
   std::list<Book> books;

public:
   void addBook(int id, std::string title, std::string author,int year, double price, int pages);
   void addBook(const Book &ref);
   void removeBook(int key);
   void displayAll();
   bool isBookFoundByISBN(int key);
   Book findBookByISBN(int key);  //Book*, Book& com
   std::list<Book> findBooksbyAuthor(std::string author); //com
   double findAveragePrice();
   int findMaxPages();
   int booksWithinRange(double price1, double price2);
   int booksAbovePriceByAuthor(std::string author, double price);
   std::string getTitleFromId(int key);
   std::string getAuthorFromId(int key);
   int getYearFromId(int key);
   double getPriceFromId(int key);
   int getPagesFromId(int key);
   Book& findBookWithMaxPrice(); //com
   double findMaxPrice(); //com
   Book& findBookWithMinPages(); //com
   double findAveragePriceByYear(int); //com
   void sortBooksByTitle();
   void sortBooksByPrice();
   ~BookDB();
};

#endif // #ifndef __LIBRARY_H_