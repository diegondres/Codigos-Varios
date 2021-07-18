#include "MapADT.h"
#include <bits/stdc++.h>
using namespace std;

class MapSV: public MapADT {
private:
	vector< pair<string,int> > _map;
	int _size;
public:
	MapSV();
	~MapSV();
	int size();
	bool isEmpty();
	int get(string str);
	void put(pair<string,int> str);
	int remove(string str);
};
