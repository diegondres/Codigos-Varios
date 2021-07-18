/*
	No recuerdo exactamente que es lo que se pedía, pero la resolución se realizó utilizando un merge sort iterativo. Basandome en un codigo similar 
	pero que estaba en C
*/


#include<bits/stdc++.h>
using namespace std;
//para el algoritmo de complejidad nLogn es necesario ocupar un algoritmo de ordenamiento de esa complejidad
//es por ello que he realizado un codigo de un merge sort iterativo.

void merge(vector<int> &arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
      while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}
void mergeSort(vector<int> &arr, int n) 
{ 
   int curr_size;   
   int left_start; 
  
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) 
   { 
       for (left_start=0; left_start<n-1; left_start += 2*curr_size) 
       { 
           int mid = min(left_start + curr_size - 1, n-1); 
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
           merge(arr, left_start, mid, right_end); 
       } 
   } 
} 


void Cuadratico(vector<int> &entrantes, vector<int> &salientes){
	int temp,jtemp1, jtemp2, mayorS = salientes[0], cuentaLuz = 0, cabezalE = 0, cabezalS =0, genteDentro =0;
	for(int i =0;i<entrantes.size();i++){ //en el mismo loop se trabaja con ambos vectores ya que necesariamente tienen que ser de mismo tamaño
		jtemp1 = i;
		jtemp2 = i;
		if(salientes[i]>mayorS) mayorS = salientes[i];
		for(int j = i;j<entrantes.size();j++){
			if(entrantes[j]<entrantes[jtemp1]){ jtemp1 = j;}
			if(salientes[j]<salientes[jtemp2]){ jtemp2 = j;}
		}
		temp = entrantes[i];
		entrantes[i] = entrantes[jtemp1];
		entrantes[jtemp1]=temp;
		temp = salientes[i];
		salientes[i] = salientes[jtemp2];
		salientes[jtemp2]=temp;
	}

	for(int i = 0; i<=mayorS;i++){
		while(salientes[cabezalS]== i) {
			genteDentro--;
			cabezalS++;
			//alguien va a salir en este turno, apagar la luz si es necesario
		}
		while(entrantes[cabezalE]== i){
			if(genteDentro == 0) cuentaLuz++;
			genteDentro++;
			cabezalE++;
			//alguien va a entrar en este turno, prender la luz si es necesario
		}
	}
	cout<<"Para Cuadratico la cuenta queda en: "<<cuentaLuz<<endl;
}

void nLogaritmico(vector<int> &entrantes, vector<int> &salientes){
	mergeSort(entrantes,entrantes.size());
	mergeSort(salientes,salientes.size());
	int mayorS = salientes[salientes.size()-1], cuentaLuz = 0, cabezalE = 0, cabezalS = 0, genteDentro =0;

	for(int i = 0; i<=mayorS;i++){
		while(salientes[cabezalS]== i) {
			genteDentro--;
			cabezalS++;
			//alguien va a salir en este turno, apagar la luz si es necesario
		}
		while(entrantes[cabezalE]== i){
			if(genteDentro == 0) cuentaLuz++;
			genteDentro++;
			cabezalE++;
			//alguien va a entrar en este turno, prender la luz si es necesario
		}
	}
	cout<<"Para nLogaritmico la cuenta queda en: "<<cuentaLuz<<endl;
}

int main(){

	vector<int> entra;
	vector<int> sale;

	int Tentra, TSale, eleccion;
	cout<<"Para ingresar manualmente presiones 1, automatico 2"<<endl;
	cin>>eleccion;
	if(eleccion==1){
	cout<<"Ingresar pares de valores separados, ingrese 0 en el segundo valor para detener insercion"<<endl;
	while(TSale!=0){
	cin>> Tentra >> TSale;
	entra.push_back(Tentra);
	sale.push_back(TSale);
	}
	entra.pop_back();
	sale.pop_back();
	}
	else{
		srand(time(NULL));
		cout<<"Indica la cantidad de tuplas que quieres: ";
		cin>>eleccion;
		Tentra = eleccion;
		for(int i =0; i<eleccion;i++){
			entra.push_back(rand()%Tentra);
			sale.push_back(entra[i] + rand()%(7) + 1); //se suma 1 para asegurar que sea mayor la salida, y se deja un rango pequeño
														//para que se vacie seguido la sala.
		}
	
	}
	auto start = chrono::high_resolution_clock::now();
	Cuadratico(entra, sale);
	auto finish = chrono::high_resolution_clock::now();
	auto d = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	cout <<"Tiempo Cuadratico "<< d << " [microseg]" <<endl;
	start = chrono::high_resolution_clock::now();
	nLogaritmico(entra, sale);	
	finish = chrono::high_resolution_clock::now();
	d = chrono::duration_cast<chrono::microseconds> (finish - start).count();
	cout <<"Tiempo Cuadratico "<< d << " [microseg]" <<endl;

	return 0;
}

