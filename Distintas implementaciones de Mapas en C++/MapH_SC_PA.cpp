#include "MapH_SC_PA.h"
#include <bits/stdc++.h>
using namespace std;

int hash3(string str,int _maxsize){
	int val=0;
	for(int i=str.size()-1;i>0;i--){
		val+=(int)str[i];
		val = val*11;
	}
	val+=(int)str[0];
	val=val%_maxsize;
	return(val);
}


MapH_SC_PA::MapH_SC_PA(int maxsize){
    _size=0;
    _maxsize=maxsize;
    pair<string,int> aux = make_pair("0",0);
    _vec.resize(_maxsize);
}


MapH_SC_PA::~MapH_SC_PA(){
	_vec.clear();  
}
int MapH_SC_PA::get(string str){
    int pos=hash3(str,_maxsize);

    if(_vec[pos].empty()){
        return -1;
    }
    else{
        for(int i=0;i<_vec[pos].size();i++){
            if(_vec[pos][i].first == str){
                return _vec[pos][i].second;
            }
        }
        
    }
    return -1;

}

void MapH_SC_PA::put(pair<string,int> par){
	if((_size+1)/_maxsize > 3/4){
        return;
    }
    int pos=hash3(par.first,_maxsize);
    if(_vec[pos].empty()){
        _vec[pos].push_back(par);
        _size++;
        return;
    }
    else{
        for(int i=0;i<_vec[pos].size();i++){
            if(_vec[pos][i].first==par.first){
                return;
            }
        }
        _vec[pos].push_back(par);
        _size++;
        return;
    }
}

int MapH_SC_PA::remove(string str){
 int pos=hash3(str,_maxsize);
 int aux;
 if(_vec[pos].empty()){
        printf("Map esta vacio\n");
        return -1;
    }
    else{
        for(int i=0;i<_vec[pos].size();i++){
            if(_vec[pos][i].first==str){
            	aux=_vec[pos][i].second;
                _vec[pos].erase(_vec[pos].begin()+i);
                _size--;
                return aux;
            }
        }
        return -1;
    }
}

bool MapH_SC_PA::isEmpty(){
    return _size==0;
}

int MapH_SC_PA::size(){
    return _size;
}
