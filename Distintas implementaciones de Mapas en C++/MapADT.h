#ifndef MAP_H
#define MAP_H

#include <bits/stdc++.h>

using namespace std;
class MapADT{

public:
	virtual void put(pair<string,int>) = 0;
	virtual int get(string) = 0;
	virtual bool isEmpty() =0 ;
	virtual int size()= 0 ;
	virtual int remove(string) = 0;
}; 
#endif
