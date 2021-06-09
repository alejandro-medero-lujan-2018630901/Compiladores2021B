/*
	Autor: Medero Lujan Alejandro
	Descripcion: Analisis sintactico por descenso recursivo

	A->BCDEa
	B->bCD
	C->cA
	D->d
	E->e
	C->f
	B->a

	BCDEa
	bCDCDEa
	bfdfdea

	BCDEa
	bCDCDEa
	bcADCDEa
	bcBCDEaDCDEa
	bcafdeadfdea
*/
#include <iostream>
#include <string>
using namespace std;

bool A(string &);
bool B(string &);
bool C(string &);
bool D(string &);
bool E(string &);
bool consumir(string &, char);

int i = 0;

int main(void){
	string s; 
	cout<<"Palabra: ";
	cin>>s;

	if(A(s) and i==s.size()){
		cout << "Pertenece" << endl;
	}else{
		cout << "No pertenece" << endl;
	}

	return 0;
}

bool A(string &s){
	if(B(s) and C(s) and D(s) and E(s)){
		return consumir(s,'a');
	}

	return 0;
}

bool B(string &s){
	if(consumir(s,'b') and C(s)){
			return D(s);
	}
	
	return consumir(s,'a');
}

bool C(string &s){
	if(consumir(s,'c')){
		return A(s);
	}
		
	return consumir(s,'f');
}

bool D(string &s){
	return consumir(s,'d');
}

bool E(string &s){
	return consumir(s,'e');
}

bool consumir(string &s, char letra){
	if(s[i] == letra){
		i++;
		return 1;
	}else{
		return 0;
	}
}