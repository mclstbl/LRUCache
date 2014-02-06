CC = g++
DEBUG = -g
CXXFLAGS = -o

lrucache : 
	$(CC) main.cpp LRUCache.cpp $(CXXFLAGS) lrucache

lrucache.o : LRUCache.h LRUCache.cpp main.cpp
	$(CC) main.cpp LRUCache.cpp

clean:
	\rm lrucache

tar:
	tar cfv lrucache.tar LRUCache.h LRUCache.cpp main.cpp
