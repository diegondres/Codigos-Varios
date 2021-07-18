#include <bits/stdc++.h>
#include "MapSV.h"

using namespace std;

MapSV::MapSV(){

}
MapSV::~MapSV(){
	_map.clear();
}
int MapSV::size(){
	return(_map.size());
}
bool MapSV::isEmpty(){
	return(_map.empty());
}
int MapSV::get(string str){ //search sobre vector con busqueda binaria
	if(_map.empty()){
		return -1;
	}
	int l=0,r=_map.size();
	int m;
	while(l<=r){
		m=(l+r)/2;
		if(str.compare(_map[m].first)==0){
			return _map[m].second;
		}
		else if (str.compare(_map[m].first)<0){
			r=m-1;
		}
		else if(str.compare(_map[m].first)>0){
			l=m+1;
		}
	}
	return -1;
}
void MapSV::put(pair<string,int> par){
	if(_map.empty()){
		_map.push_back(par);
		return;
	}
	else{
		for(int i=0;i<_map.size();i++){
			if(_map[i].first.compare(par.first)==0){
				return;
			}
			else if(_map[i].first.compare(par.first)>0){
				_map.insert(_map.begin()+i,par);
				return;
			}
		}		
	_map.push_back(par);

	}
}
int MapSV::remove(string str){
	if(_map.empty()){
		return -1;
	}
	int l=0,r=_map.size();
	int m,aux;

	while(l<=r){
		m=(l+r)/2;
		if(str.compare(_map[m].first)==0){
			aux=_map[m].second;
			_map.erase(_map.begin()+m);
			return aux;
		}
		else if (str.compare(_map[m].first)<0){
			r=m-1;
		}
		else if(str.compare(_map[m].first)>0){
			l=m+1;
		}
	}
	return -1;
}
