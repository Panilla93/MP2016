#include "byte.h"

using namespace std;

void on (byte &b, int pos){

	byte mask= 1;

	mask = 1 << pos;
	b = mask | b;

}

void off(byte &b, int pos){

	byte mask= 1;

	mask = 1 << pos;

	mask= ~mask;

	b = mask & b;

}

bool getbit(byte b, int pos){

	bool estado = false;
	byte mask = 1;
	unsigned char aux = 0;

	mask = 1 << pos;

	aux = mask & b;

	if(aux == 0){
		estado  = false;
	}
	else{
		estado = true;
	}

	return estado;
}

string bloqueLedToString(byte b){

	string resultado;

	for (int i = 0; i < 8; ++i)
	{
		if( getbit(b,7-i) == true)
			resultado+= "1 ";
		else
			resultado+="0 ";
	}

	return resultado;
}

void encender(byte &b){

	b = 0b11111111;
}

void apagar(byte &b){
	b = 0;
}

void asignar(byte &b , const bool v[]){

	for (int i = 0; i < 8; ++i)
	{
		if(v[i] == false){
			off(b,i);			
		}
		else{

			on(b,i);
		}

	}
}

void volcar (byte b, bool v[]){

	for (int i = 0; i < 8; ++i)
	{
		if(getbit(b,i) == false){
			v[7-i]=false;
		}
		else{
			v[7-i]=true;
		}
	}
}

void encendidos (byte b , int posic[], int &cuantos){
	cuantos =0;
	for (int i = 0; i < 8; ++i)
	{
		if (getbit(b,i) == true)
		{
			posic[cuantos]= i;
			cuantos++;
		}
	}
}