/*
	Autor: Medero Lujan Alejandro
	Descripcion: Analisis sintactico por descenso recursivo
*/

#include <iostream>
#include <string>
using namespace std;

bool A(string &);
bool B(string &);
bool consumir(string &, char);

int i = 0;

int main(){
	string s; 
	cout<<"Palabra: ";
	cin>>s;

	if(A(s)){
		cout << "Pertenece" << endl;
	}else cout << "No pertenece" << endl;

	return 0;
}

bool A(string &s){
	if(!consumir(s,'a')){
		return 0;
	}

	if(B(s)){
		return consumir(s,'a');
	}

}

bool B(string &s){
	if(consumir(s,'c')){
		return 1;
	}else if(!consumir(s,'b')){
		return 0;
	}

	if(A(s)){
		return consumir(s,'b');
	}
}

bool consumir(string &s, char letra){
	if(s[i] == letra){
		i++;
		return 1;
	}else return 0;
}