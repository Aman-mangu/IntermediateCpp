#ifndef __BOOK_H_
#define __BOOK_H_

#include <iostream>

class Book
{
    int m_isbn;
    std::string m_title, m_author;
    int m_year;
    double m_price;
    int m_pages;

public:
    Book(int id, std::string title, std::string author,int year, double price, int pages);
    int getISBN();
    std::string getTitle();
    std::string getAuthor();
    int getYear();
    double getPrice();
    int getPages();
    void display();
    ~Book();
};

#endif // #ifndef __BOOK_H_