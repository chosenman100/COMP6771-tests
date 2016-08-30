TEST_FILES := $(wildcard *.cpp)
TEST_FILES := $(filter-out EuclideanVector.cpp, $(TEST_FILES))

all: EuclideanVectorTester

EuclideanVectorTester: EuclideanVectorTester.o EuclideanVector.o
	g++ -fsanitize=address EuclideanVectorTester.o EuclideanVector.o -o EuclideanVectorTester

EuclideanVectorTester.o: EuclideanVectorTester.cpp EuclideanVector.h
	g++ -std=c++14 -Wall -Werror -O2 -fsanitize=address -c $(TEST_FILES)

EuclideanVector.o: EuclideanVector.cpp EuclideanVector.h
	g++ -std=c++14 -Wall -Werror -O2 -fsanitize=address -c EuclideanVector.cpp

clean:
	rm *o EuclideanVectorTester
