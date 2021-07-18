#include <iostream>
#include <bits/stdc++.h>
#include "MapH_LP_B.h"
#include "MapH_LP_PA.h"
#include "MapH_SC_B.h"
#include "MapH_SC_PA.h"
#include "MapSV.h"
#include <random>

using namespace std;

string RandomString(int len)
{

   random_device r;
   string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
   string newstr;
   uniform_int_distribution<int> dist(1,str.size()-1);
   int pos;
   while(newstr.size() <= len) {
    pos = dist(r);
    newstr += str.substr(pos,1);
   }
   return newstr;
}

int main(){
	int n;
	random_device r;
	cout<<"Ingrese numero de elementos a ingresar:"<<endl;
	cin>>n;
	pair<string,int> p=make_pair("0",0);
	vector<pair<string,int> > par(n,p);
	uniform_int_distribution<int> dist(2,6);
	uniform_int_distribution<int> d(1,1000);

	for(int i=0;i<n;i++){
		par[i].first=RandomString(dist(r));
		par[i].second=d(r);

	}
	MapADT *mapaLPB = new MapH_LP_B(87500);
    MapADT *mapaLPPA = new MapH_LP_PA(87009);
    MapADT *mapaSCB = new MapH_SC_B(58333);
    MapADT *mapaSCPA = new MapH_SC_PA(58337);
    MapADT *mapaSV = new MapSV();
	clock_t start,end;
	start=clock(); 
	for(int i=0;i<n;i++){
		mapaLPB->put(par[i]);
	}
	end=clock();
	cout <<"MapaLPB put tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;
	
	start=clock();
	for(int i=0;i<n;i++){
		mapaLPPA->put(par[i]);
	}
	end=clock();
	cout <<"MapaLPPA put tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;
	
	start=clock();
	for(int i=0;i<n;i++){
		mapaSCB->put(par[i]);
	}
	end=clock();
	cout <<"MapaSCB put tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;

	start=clock();
	for(int i=0;i<n;i++){
		mapaSCPA->put(par[i]);	
	}
	end=clock();
	cout <<"MapaSCPA put tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;

	start=clock();
	for(int i=0;i<n;i++){
		mapaSV->put(par[i]);
	}
	end=clock();
	cout <<"MapaSV put tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;	
	start=clock();
	for(int i=0;i<n;i++){
		mapaSV->get(par[i].first);
	}
	end=clock();
	cout <<"MapaSV get tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;
	
	start=clock();
	for(int i=0;i<n;i++){
		mapaSCPA->get(par[i].first);
	}
	end=clock();
	cout <<"MapaSCPA get tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;
	start=clock();
	for(int i=0;i<n;i++){
		mapaSCB->get(par[i].first);
	}
	end=clock();
	cout <<"MapaSCB get tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;
	
	start=clock();
	for(int i=0;i<n;i++){
		mapaLPPA->get(par[i].first);
	}
	end=clock();
	cout <<"MapaLPPA get tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;

	start=clock();
	for(int i=0;i<n;i++){
		mapaLPB->get(par[i].first);
	}
	end=clock();
	cout <<"MapaLPB get tiempo: "<< (((double)(end-start))/CLOCKS_PER_SEC)/n << endl;

	return 0;
}
