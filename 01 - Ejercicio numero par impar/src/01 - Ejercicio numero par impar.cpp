//============================================================================
// Name        : Ejercicio.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	int numero, *dir;

	cout<<"Introduce un numero: ";;
	cin>>numero;



	dir = &numero;


	if(*dir % 2 == 0){
		cout<<"El numero "<<*dir<<" es par"<<endl;
	}else{
		cout<<"El numero "<<*dir<<" es impar"<<endl;
	}

	cout<<"La posicion de memoria es "<<dir<<endl;
	return 0;
}
