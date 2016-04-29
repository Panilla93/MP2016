#include <iostream>
#include "imagen.h"
#include <string.h>

using namespace std;

int main(int argc, char **argv){
    
    char grises[500]="";   
    char ruta[300] = "imagenes/";
    char ima[100] = "";
    Imagen origen;

    cout<<"Diga el nombre de la imagen con la extension"<< endl;
    cin >> ima;

    strcat(ruta,ima);

    if (!origen.leerImagen(ruta)){
       cerr << "error leyendo "<< ruta << "\n";
       return 1;
    }
    int tama = (origen.filas()*origen.columnas())+1;

    char arteASCII[tama];

    cout<<"Inserta los caracteres: "<< endl;
    cin >> grises;

    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, tama))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;  

}