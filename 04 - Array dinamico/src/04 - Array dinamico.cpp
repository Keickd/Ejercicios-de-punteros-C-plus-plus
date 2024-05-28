//============================================================================
// Name        : Array.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>

using namespace std;


int numNotas, *notas;

void pedirNotas();
void mostrarNotas();

int main() {

	pedirNotas();
	mostrarNotas();

	delete[] notas;

	return 0;
}

void pedirNotas(){
	cout<<"Introduce el numero de notas: ";
	cin>>numNotas;

	notas = new int[numNotas];

	for(int i = 0; i < numNotas; i++){
		cout<<"Introduce una nota en la pos "<<i<<": ";
		cin>>notas[i];
		cout<<endl;
	}
}

void mostrarNotas(){

	cout<<"Mostrando notas:"<<endl;

	for(int i = 0; i < numNotas; i++){
		cout<<notas[i]<<endl;
	}
}
