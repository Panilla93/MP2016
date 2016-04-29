#include "imagen.h"
#include <string.h>
#include <iostream>


using namespace std;

Imagen::Imagen(){

	byte cero=0;
	nfilas = 0;
	ncolumnas = 0;
	datos[0]= cero;
}

Imagen::Imagen(int filas, int columnas) {

	byte negro=0;

	if (MAXPIXELS > filas*columnas)
	{
		ncolumnas = columnas;
		nfilas = filas;
		for (int i = 0; i < nfilas*ncolumnas; ++i)
		{
			datos[i] = negro;
		}
	}
}

void Imagen::crear(int filas, int columnas){

	nfilas=filas;
	ncolumnas=columnas;
	byte blanco =255;
	for (int i = 0; i < nfilas*ncolumnas; ++i)
	{
		datos[i]=blanco;
	}

}

int Imagen::filas(){
	return nfilas;
}

int Imagen::columnas(){
	return ncolumnas;
}

void Imagen::set(int y, int x, byte v){
	datos[y*ncolumnas + x] = v;
} 

byte Imagen::get(int y, int x){
	return datos[y*ncolumnas+x];
}

void Imagen::setPos(int i, byte v){
	if(i< ncolumnas*nfilas)
		datos[i]=v;
} 

byte Imagen::getPos(int i){
	if(i < ncolumnas*nfilas)
		return datos[i];
	else
		return '-1';
}

bool Imagen::leerImagen(const char nombreFichero[]){

	TipoImagen tipo;
	int fil = 0;
	int col = 0;

	tipo=infoPGM(nombreFichero,fil,col);

	if (tipo == IMG_PGM_BINARIO && fil*col < MAXPIXELS){
		return leerPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
	}
	return false;
}

bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){

	if(esBinario){
		return	escribirPGMBinario(nombreFichero,datos,nfilas,ncolumnas);
	}
	return false;

}

Imagen Imagen::plano(int k){

	Imagen plano=Imagen(this->filas(),this->columnas());
	byte b;
	bool bit;

	for (int i = 0; i < nfilas*ncolumnas; ++i)
	{
		b=this->getPos(i);
		bit = getbit(b,k);
		apagar(b);
		if(bit)
			on(b,7);
		else
		
		plano.setPos(i,b);
	}


	return plano;
}

bool Imagen::aArteASCII(const char grises[],char ArteASCII[], int maxlong){

	bool resultado;
	
	if((nfilas * ncolumnas) < maxlong){

		for (int i = 0; i < nfilas*ncolumnas; ++i){
				if (i % ncolumnas == 0){
					ArteASCII[i]='\n';	
				}
				else{
					ArteASCII[i]=grises[this->getPos(i)*strlen(grises)/256];
				}
		}
		resultado=true;	
	}
	else
		resultado=false;

	return resultado;
}