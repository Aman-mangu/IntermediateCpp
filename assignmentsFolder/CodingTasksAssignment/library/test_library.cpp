#include "library.h"
#include <gtest/gtest.h>

TEST(Library, ParameterizedConstructor)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);

    ASSERT_EQ(1, 1);
    ASSERT_EQ("First one", library.getTitleFromId(1));
    ASSERT_EQ("First author", library.getAuthorFromId(1));
    ASSERT_EQ(2019, library.getYearFromId(1));
    ASSERT_DOUBLE_EQ(20.5, library.getPriceFromId(1));
    ASSERT_EQ(400, library.getPagesFromId(1));
}

TEST(Library, CopyConstructor)
{
    Book sample(1, "First one", "First author", 2019, 20.5, 400);
    BookDB library;
    library.addBook(sample);

    ASSERT_EQ(1, 1);
    ASSERT_EQ("First one", library.getTitleFromId(1));
    ASSERT_EQ("First author", library.getAuthorFromId(1));
    ASSERT_EQ(2019, library.getYearFromId(1));
    ASSERT_EQ(20.5, library.getPriceFromId(1));
    ASSERT_EQ(400, library.getPagesFromId(1));
}

TEST(Library, removeBook_isBookFoundById)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.removeBook(2);

    ASSERT_EQ(false, library.isBookFoundByISBN(2));
    ASSERT_EQ(true, library.isBookFoundByISBN(1));
}

TEST(Library, findBookbyAuthor)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);
    std::list<Book> found = library.findBooksbyAuthor("First author");
    ASSERT_EQ(2, found.size());
    
}

TEST(Library, findAveragePrice)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);

    ASSERT_DOUBLE_EQ(45.5, library.findAveragePrice());
}

TEST(Library, findMaxPages)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);

    ASSERT_EQ(500, library.findMaxPages());
}

TEST(Library, booksWithinRange)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);

    ASSERT_EQ(2, library.booksWithinRange(50,70));
}

TEST(Library, booksAbovePriceByAuthor)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);

    ASSERT_EQ(1, library.booksAbovePriceByAuthor("First author", 40));
}


TEST(Library, Display)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);
    library.sortBooksByTitle();
    library.displayAll();
}

TEST(Library, bookwithmaxprice)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);
    Book b1=library.findBookWithMaxPrice();

    ASSERT_EQ(3,b1.getISBN());

}

TEST(Library, maxprice)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);
    ASSERT_DOUBLE_EQ(65.5,library.findMaxPrice());

}

TEST(Library, bookwithminpages)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);
    Book b1=library.findBookWithMinPages();
    ASSERT_EQ(3,b1.getISBN());
}

TEST(Library, averagepricebyyear)
{
    BookDB library;
    library.addBook(1, "First one", "First author", 2019, 20.5, 400);
    library.addBook(2, "Second one", "Second author", 2020, 50.5, 500);
    library.addBook(3, "Third one", "First author", 2020, 65.5, 200);
    library.sortBooksByPrice();
    library.displayAll();

    ASSERT_EQ(20.5,library.findAveragePriceByYear(2019));
    ASSERT_EQ(58,library.findAveragePriceByYear(2020));

}



int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
