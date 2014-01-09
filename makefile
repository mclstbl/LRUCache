CC = g++
DEBUG = -g

lrucache : 
	$(CC) main.cpp LRUCache.cpp -o lrucache

lrucache.o : LRUCache.h LRUCache.cpp main.cpp
	$(CC) main.cpp LRUCache.cpp

clean:
	\rm *.o *~ lrucache

tar:
	tar cfv lrucache.tar LRUCache.h LRUCache.cpp main.cpp
