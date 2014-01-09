//
//  main.cpp
//  LRUCache
//
//  Created by Micaela Estabillo on 2014-01-04.
//  Copyright (c) 2014 Micaela Estabillo. All rights reserved.
//


#include <iostream>
#include <string>
#include "LRUCache.h"
using namespace std;

int main () {
    
	int num;
	cin >> num;

	string *operations = new string[num];
    
	for (int i = 0; i < num; i ++){
		cin >> operations[i];
	}
    
	for (int i = 0; i < num; i ++){
		if (isElem ("BOUND",operations[i])) {
			int intPos = (int) operations[i].find(' ') + 1;
			int limit = atoi (operations[i].substr(intPos,string::npos).c_str());
			bound(limit);
		}
		else if (isElem ("SET",operations[i])) {
			int keyPos = 4; //operations[i].find(' ') + 1;
			char key = operations[i][keyPos];
			string value = operations[i].substr(keyPos + 2,string::npos);
			set(key,value);
		}
        
		else if (isElem ("GET",operations[i])) {
			int keyPos = (int) operations[i].find(' ') + 1;
			char key = operations[i][keyPos];
			get(key);
		}
		else if (isElem ("PEEK",operations[i])) {
			int keyPos = (int) operations[i].find(' ') + 1;
			char key = operations[i][keyPos];
			peek(key);
            
		}
		else if (isElem ("DUMP", operations[i])) {
			dump();
		}
	}

	return 0;
}





