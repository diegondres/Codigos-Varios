#include "MapH_LP_B.h"
#include <bits/stdc++.h>
using namespace std;

int hash4(string str,int _maxsize){
    int val = (int)str[0];
    val = val%_maxsize;
    return(val);
}

MapH_LP_B::MapH_LP_B(int maxsize){
    _size=0;
    _maxsize=maxsize;
    pair<string,int> aux = make_pair("0",0);
    _vec.resize(_maxsize,aux);
}

MapH_LP_B::~MapH_LP_B(){
  _vec.clear();
}
int MapH_LP_B::get(string str){ //search sobre arreglo circular, aritmetica modular etc etc
    int pos=hash4(str,_maxsize);

    for(int p=0;p<_maxsize;p++){
        if(_vec[pos].first=="0" && _vec[pos].second==0) return -1;
        else if(_vec[pos].first == str) return _vec[pos].second;
        else pos=(pos+1)%_maxsize;
    }
    return -1;
}

void MapH_LP_B::put(pair<string,int> par){
    if((_size+1)/_maxsize > 1/2){
        return;
    }
    if(this->get(par.first)!=-1){
    	return;
    }
    int pos=hash4(par.first,_maxsize);
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

int MapH_LP_B::remove(string str){
    int pos=hash4(str,_maxsize);
    int aux;
    for(int p=0;p<_maxsize;p++){
        if(_vec[pos].first==str) {
            aux=_vec[pos].second;
            _vec[pos].first="AVAILIBLE";
            _vec[pos].second=-1;
            _size--;
            return aux;                            
            }
        else if(_vec[pos].first=="0" && _vec[pos].second==0) return -1;
        else{
            pos=(pos+1)%_maxsize;
        }
    }
    return -1;
}

bool MapH_LP_B::isEmpty(){
    return _size==0;
}

int MapH_LP_B::size(){
    return _size;
}
