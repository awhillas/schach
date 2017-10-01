CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O3
LINK = -Wall
LIB = /usr/local/Cellar/boost/1.65.1
#INCLUDES = -I $(LIB)/include
INCLUDES = 

LIBHEADERS = board.h fen.h move.h pieces.h side.h split.h square.h
LIBSOURCES = board.cpp fen.cpp move.cpp pieces.cpp split.cpp square.cpp

all : schach

schach : $(LIBHEADERS) $(LIBSOURCES) schach.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBSOURCES) schach.cpp -o schach

test : $(LIBHEADERS) $(LIBSOURCES) test_main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBSOURCES) -l boost_unit_test_framework test_main.cpp -o test

clean :
	rm -f *.o schach
