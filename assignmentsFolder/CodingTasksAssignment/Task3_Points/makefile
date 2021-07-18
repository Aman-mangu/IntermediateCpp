SRC = points.cpp collection.cpp test_collection.cpp

all: $(SRC)
	g++ $^ -lgtest -lgtest_main -lpthread -o all.out

run:all
	./all.out

coverage:$(SRC)
	g++ -fprofile-arcs -ftest-coverage $^ -lgtest -lgtest_main -lpthread -o all.out
	./all.out
	gcov -a points.cpp collection.cpp

analyze:all $(SRC)
	cppcheck --enable=all --suppress=missingIncludeSystem $(SRC)
	valgrind ./all.out

clean:
	rm -rf *.o *.out *.gcd* *.gcno* *.gcov*  