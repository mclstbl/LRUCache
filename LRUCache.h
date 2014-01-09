//
//  LRUCache.h
//  LRUCache
//
//  Created by Micaela Estabillo on 2014-01-04.
//  Copyright (c) 2014 Micaela Estabillo. All rights reserved.
//

#ifndef LRUCACHE_H
#define LRUCACHE_H

#include <string>
#include <iostream>

struct CacheEntry {
	char key;
	std::string value;
	int lastAccess;
};

struct LRUCache {
	CacheEntry *entry;
}myCache;

void bound (int limit);
void set (char key, std::string value);
void trimCache ();
void del (int pos);
void get (char key);
void peek (char key);
void dump ();
void sort (LRUCache myCache);
bool isInCache (char key);
int seek (char key);
bool isElem (std::string op, std::string line);

int currentPosition = 0;
int currentAccess = 0;
int cacheLength = 0;

#endif
