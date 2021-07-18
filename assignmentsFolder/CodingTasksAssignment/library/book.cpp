#include "book.h"

Book::Book(int isbn, std::string title, std::string author,int year, double price, int pages) : m_isbn(isbn), m_title(title), m_author(author),m_year(year), m_price(price), m_pages(pages)
{}

int Book::getISBN()
{
    return m_isbn;
}

std::string Book::getTitle()
{
    return m_title;
}

std::string Book::getAuthor()
{
    return m_author;
}


int Book::getYear()
{
    return m_year;
}

double Book::getPrice()
{
    return m_price;
}

int Book::getPages()
{
    return m_pages;
}

void Book::display()
{
    std::cout << m_isbn
              << "\t"
              << m_title
              << "\t"
              << m_author
              << "\t"
              << m_year
              << "\t"
              << m_price
              << "\t"
              << m_pages
              << std::endl;
}

Book::~Book()
{}
