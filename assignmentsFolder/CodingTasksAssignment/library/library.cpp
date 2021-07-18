#include "library.h"

void BookDB::addBook(int isbn, std::string title, std::string author,int year, double price, int pages)
{
    books.push_back(Book(isbn, title, author, year, price, pages));
}

void BookDB::addBook(const Book &ref)
{
    books.push_back(ref);
}

void BookDB::removeBook(int key)
{
    std::list<Book>::iterator iter;
    for (iter = books.begin(); iter != books.end(); ++iter)
        if (key == iter->getISBN())
        {
            books.erase(iter);
            return;
        }
}

void BookDB::displayAll()
{
    std::cout << "Id"
              << "\t"
              << "Title"
              << "\t"
              << "Author"
              << "\t"
              << "Year"
              << "\t"
              << "Price"
              << "\t"
              << "Pages"
              << std::endl;

    std::list<Book>::iterator iter;
    for(iter=books.begin(); iter!=books.end(); ++iter)
    {
      iter->display();
    }
}

bool BookDB::isBookFoundByISBN(int key)
{
    for (Book &ref : books)
        if (key == ref.getISBN())
            return true;
    return false;
}

std::list<Book> BookDB::findBooksbyAuthor(std::string author) {
  std::list<Book> match;   //  std::list<Book*> match;
  std::list<Book>::iterator iter;
  for(iter=books.begin(); iter!=books.end(); ++iter)
      if(author==iter->getAuthor())
         match.push_back(*iter);  //match.push_back(&(*iter));
  return match; 
}

double BookDB::findAveragePrice()
{
    double total = 0;
    std::list<Book>::iterator iter;
    for (iter = books.begin(); iter != books.end(); ++iter)
        total += iter->getPrice();
    return total / books.size();
}

int BookDB::findMaxPages()
{
    int max = -1;
    for (Book &ref : books)
        if (max < ref.getPages())
            max = ref.getPages();
    return max;
}


Book BookDB::findBookByISBN(int key)
{
    std::list<Book>::iterator iter;
    for(iter=books.begin();iter!=books.end();iter++)
    {
        if(key==iter->getISBN())
        {
            break;
        }
    }
    return(*iter);

}



int BookDB::booksWithinRange(double price1, double price2)
{
    int num = 0;
    for (Book &ref : books)
        if (price1 < ref.getPrice() && ref.getPrice() < price2)
            num += 1;
    return num;
}

int BookDB::booksAbovePriceByAuthor(std::string author, double price)
{
    int num = 0;
    for (Book &ref : books)
        if (author == ref.getAuthor())
            if (ref.getPrice() > price)
                num += 1;
    return num;
}

std::string BookDB::getTitleFromId(int key)
{
    for (Book &ref : books)
        if (key == ref.getISBN())
            return ref.getTitle();
    return NULL;
}

std::string BookDB::getAuthorFromId(int key)
{
    for (Book &ref : books)
        if (key == ref.getISBN())
            return ref.getAuthor();
    return NULL;
}



int BookDB::getYearFromId(int key)
{
    for (Book &ref : books)
        if (key == ref.getISBN())
            return ref.getYear();
    return -1;
}

double BookDB::getPriceFromId(int key)
{
    for (Book &ref : books)
        if (key == ref.getISBN())
            return ref.getPrice();
    return -1;
}

int BookDB::getPagesFromId(int key)
{
    for (Book &ref : books)
        if (key == ref.getISBN())
            return ref.getPages();
    return -1;
}

bool comparePrice(Book&  r1,Book&  r2) {
  return r1.getPrice() < r2.getPrice();
}

Book& BookDB::findBookWithMaxPrice() {
  double maxPrice=0;
  std::list<Book>::iterator maxIter;
  maxIter = std::max_element(books.begin(), books.end(), comparePrice);
  return *maxIter;
}

double BookDB::findMaxPrice() {
  std::list<Book>::iterator maxIter;
  maxIter = std::max_element(books.begin(), books.end(), comparePrice);
  return maxIter->getPrice();
}

bool comparePages(Book& r1,Book& r2) {
  return r1.getPages() < r2.getPages();
}

Book& BookDB::findBookWithMinPages() {
  std::list<Book>::iterator minIter;
  minIter = std::min_element(books.begin(),books.end(),comparePages);
  return *minIter;
}

double BookDB::findAveragePriceByYear(int yy)
{
    double mean;
    std::list<Book>::iterator iter;
    std::list<double> prices;
    for(iter=books.begin();iter!=books.end();iter++)
    {
        if(yy==iter->getYear())
        {
            prices.push_back(iter->getPrice());
        }
    }
    mean = std::accumulate(prices.begin(),prices.end(),0.0)/prices.size();
    return mean;
}

bool compareTitle(Book&  r1,Book& r2) {
  return r1.getTitle() < r2.getTitle();
}
void BookDB::sortBooksByTitle() {
  //std::sort(books.begin(), books.end());
  books.sort(compareTitle);   
}
void BookDB::sortBooksByPrice() {
  //std::sort(books.begin(), books.end(),comparePrice);
  books.sort(comparePrice);
}
BookDB::~BookDB()
{}

