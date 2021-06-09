/*
	Autor: Medero Lujan Alejandro
	Descripcion: Analisis sintactico por descenso recursivo
	S->abSA
	S->bA
	A->aA
	A->c

	baaaaaaac
	bA
	baA
	baaA
	baaaA
	baaaaA
	baaaaaA
	baaaaaaA
	baaaaaaaA
	baaaaaaaaA
	baaaaaaaac

	abbaaacc
	abSA
	abbAA
	abbaAA
	abbaaAA
	abbaaaAA
	abbaaacA
	abbaaacc
*/
#include <iostream>
#include <string>
using namespace std;

bool S(string &);
bool A(string &);
bool consumir(string &, char);

int i = 0;

int main(void){
	string s; 
	cout<<"Palabra: ";
	cin>>s;

	if(S(s) and i==s.size()){
		cout << "Pertenece" << endl;
	}else{
		cout << "No pertenece" << endl;
	}

	return 0;
}

bool S(string &s){
	if(consumir(s,'a')){
		if(consumir(s,'b')){
			if(S(s)){
				return A(s);
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}else if(consumir(s,'b')){
		return A(s);
	}

	return 0;
}

bool A(string &s){
	if(consumir(s,'a')){
		return A(s);
	}else if(consumir(s,'c')){
		return 1;
	}

	return 0;
}

bool consumir(string &s, char letra){
	if(s[i] == letra){
		i++;
		return 1;
	}else{
		return 0;
	}
}