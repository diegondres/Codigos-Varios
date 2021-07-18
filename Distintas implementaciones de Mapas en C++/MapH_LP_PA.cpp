#include "MapH_LP_PA.h"
#include <bits/stdc++.h>
using namespace std;

int hash1(string str,int _maxsize){
	int val=0;
	for(int i=str.size()-1;i>0;i--){
		val+=(int)str[i];
		val = val*11;
	}
	val+=(int)str[0];
	val=val%_maxsize;
	return(val);
}


MapH_LP_PA::MapH_LP_PA(int maxsize){
    _size=0;
    _maxsize=maxsize;
    pair<string,int> aux = make_pair("0",0);
    _vec.resize(_maxsize,aux);
}

MapH_LP_PA::~MapH_LP_PA(){
	_vec.clear();
}
int MapH_LP_PA::get(string str){ //search sobre arreglo circular, aritmetica modular etc etc
    int pos=hash1(str,_maxsize);

    for(int p=0;p<_maxsize;p++){
        if(_vec[pos].first=="0" && _vec[pos].second==0) return -1;
        else if(_vec[pos].first == str) return _vec[pos].second;
        else pos=(pos+1)%_maxsize;
    }
    return -1;
}

void MapH_LP_PA::put(pair<string,int> par){
    if((_size+1)/_maxsize > 1/2){
        return;
    }
    if(this->get(par.first)!=-1){
    	return;
    }
    int pos=hash1(par.first,_maxsize);

    for(int p=0;p<_maxsize;p++){
        if((_vec[pos].first=="0" && _vec[pos].second==0) || (_vec[pos].first=="AVAILIBLE" && _vec[pos].second==-1) ){
            _vec[pos]=par;
            _size++;
            return;
        }
        else {
            pos=(pos+1)%_maxsize;
        }
    }
    return;
}

int MapH_LP_PA::remove(string str){
 int pos=hash1(str,_maxsize);
 int aux;
    for(int p=0;p<_maxsize;p++){
        if(_vec[pos].first==str) {
            aux=_vec[pos].second;
            _vec[pos].first="AVAILIBLE";
            _vec[pos].second=-1;
            _size--;
            return aux;                            
            }
        else if(_vec[pos].first=="0" && _vec[pos].second==0) return aux;
        else{
            pos=(pos+1)%_maxsize;
        }
    }
    return aux;
}

bool MapH_LP_PA::isEmpty(){
    return _size==0;
}

int MapH_LP_PA::size(){
    return _size;
}
