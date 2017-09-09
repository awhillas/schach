CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -O3
LINK = -Wall
INCLUDES =

LIBHEADERS = board.h fen.h move.h pieces.h side.h split.h square.h
LIBSOURCES = board.cpp fen.cpp move.cpp pieces.cpp split.cpp square.cpp

all : schach

schach : $(LIBHEADERS) $(LIBSOURCES) schach.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(LIBSOURCES) schach.cpp -o schach

clean :
	rm -f *.o schach

