#include "bloqueLed.h"

using namespace std;

void on (bloqueLed &b, int pos){

	bloqueLed mask= 1;

	mask = 1 << pos;
	b = mask | b;

}

void off(bloqueLed &b, int pos){

	bloqueLed mask= 1;

	mask = 1 << pos;

	mask= ~mask;

	b = mask & b;

}

bool get(bloqueLed b, int pos){

	bool estado = false;
	bloqueLed mask = 1;
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

string bloqueLedToString(bloqueLed b){

	string resultado;

	for (int i = 0; i < 8; ++i)
	{
		if( get(b,7-i) == true)
			resultado+= "1 ";
		else
			resultado+="0 ";
	}

	return resultado;
}

void encender(bloqueLed &b){

	b = 0b11111111;
}

void apagar(bloqueLed &b){
	b = 0;
}

void asignar(bloqueLed &b , const bool v[]){

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

void volcar (bloqueLed b, bool v[]){

	for (int i = 0; i < 8; ++i)
	{
		if(get(b,i) == false){
			v[7-i]=false;
		}
		else{
			v[7-i]=true;
		}
	}
}

void encendidos (bloqueLed b , int posic[], int &cuantos){
	cuantos =0;
	for (int i = 0; i < 8; ++i)
	{
		if (get(b,i) == true)
		{
			posic[cuantos]= i;
			cuantos++;
		}
	}
}