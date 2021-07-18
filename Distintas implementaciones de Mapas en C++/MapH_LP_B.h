#include "MapADT.h"
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

class MapH_LP_B : public MapADT {
private:
	vector<pair<string,int> > _vec;
    int _size;
    int _maxsize;

public:
	MapH_LP_B(int n);
	~MapH_LP_B();
	bool isEmpty();
	int get(string str);
	void put(pair<string,int> str);
	int remove(string str);
	int size();
};
