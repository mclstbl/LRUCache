//
//  LRUCache.cpp
//  LRUCache
//
//  Created by Micaela Estabillo on 2014-01-04.
//  Copyright (c) 2014 Micaela Estabillo. All rights reserved.
//

#include "LRUCache.h"

void bound (int limit) {
	cacheLength = limit;
	if (cacheLength > limit) trimCache();
	else myCache.entry = new CacheEntry[limit];
}

void set (char key, std::string value) {
	trimCache();
	if (isInCache (key)) {
		int pos = seek (key);
		if (value.length() <= 10) myCache.entry[pos].value = value;
		else myCache.entry[pos].value = value.substr (0,10);
		myCache.entry[pos].lastAccess = currentAccess;
		currentAccess ++;
	}
	else {
		myCache.entry[currentPosition].key = key;
		if (value.length() <= 10) myCache.entry[currentPosition].value = value;
		else myCache.entry[currentPosition].value = value.substr (0,10);
		myCache.entry[currentPosition].lastAccess = currentAccess;
		currentPosition ++;
		currentAccess ++;
	}
}


void trimCache () {
	while (currentPosition >= cacheLength) {
		int lru;
		for (int i = 0; i < cacheLength - 1; i ++){
			if (myCache.entry[i].lastAccess < myCache.entry[i + 1].lastAccess){
				lru = i;
			}
		}
		del (lru);
	}
}

void del (int pos) {
	if (pos < cacheLength - 1){
		for (int i = pos; i < cacheLength - 1; i ++){
			myCache.entry[pos] = myCache.entry[pos + 1];
		}
		currentPosition --;
	}
	else currentPosition --;
}

void get (char key) {
	int pos = seek (key);
	if (pos == -1) std::cout << "NULL" << "\n";
	else{
		std::cout << myCache.entry[pos].value << "\n";
		myCache.entry[pos].lastAccess = currentAccess;
		currentAccess ++;
	}
}

void peek (char key) {
	int pos = seek (key);
	if (pos == -1) std::cout << "NULL" << "\n";
	else{
		std::cout << myCache.entry[pos].value << "\n";
	}
}

void dump () {
	sort (myCache);
	for (int i = 0; i < currentPosition; i ++){
		CacheEntry current = myCache.entry[i];
		std::cout << current.key << " " << current.value << "\n";
		current.key = '\0';
		current.value = "";
		current.lastAccess = 0;
	}
	currentAccess = 0;
	currentPosition = 0;
	myCache.entry = new CacheEntry[cacheLength];
}

void sort (LRUCache myCache) {
	CacheEntry temp;
	int pos = 0;
	for (int i = 97; i < 123; i ++){
		if (isInCache ((char) i)) {
			int found = seek ((char) i);
			temp = myCache.entry[found];
			myCache.entry[found] = myCache.entry[pos];
			myCache.entry[pos] = temp;
			pos ++;
		}
	}
}

bool isInCache (char key) {
	for (int i = 0; i < cacheLength; i ++){
		if (myCache.entry[i].key == key) return true;
	}
	return false;
}

int seek (char key) {
	for (int i = 0; i < cacheLength; i ++){
		if (myCache.entry[i].key == key) return i;
	}
	return -1;
}

bool isElem (std::string op, std::string line){
	int i = 0;
	if (op[i] == line[i]) return true;
	return false;
}