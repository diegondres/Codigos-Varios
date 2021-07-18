#include "MapADT.h"
#include <bits/stdc++.h>

using namespace std;

class MapH_SC_B : public MapADT {
private:
	vector<vector<pair<string,int> > > _vec;
	int _size;
	int _maxsize;

public:
	MapH_SC_B(int n);
	~MapH_SC_B();
	bool isEmpty();
	int get(string str);
	void put(pair<string,int> str);
	int remove(string str);
    int size();
};
