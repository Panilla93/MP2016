#include <fstream>
#include <iostream>
#include <imagen.h>

using namespace std;

int main(int argc, char **argv){
    char grises[];

    char arteASCII[4501]; // 4500 + el \0
       
     if(argc < 3) {
        fprintf(stderr,"\nLo has escrito bien ./arteASCII [rutaimagen] [rutacaracteres] \n");
        exit(-1);
     }

    ifstream fe(argv[2]);

    while(!fe.eof()) {
      fe.getline(grises,250);
    }

    fe.close();

    Imagen origen;

    // Leer la imagen gio.pgm
    if (!origen.leerImagen(argv[1])){
       cerr << "error leyendo \n";
       return 1;
    }
    
    cout << "\nLa imagen en arte ASCII es:\n";
    if(origen.aArteASCII(grises, arteASCII, 4500))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;  
    
    cout << "Ahora Forzamos que no quepa. Debe aparecer un mensaje de error\n";
    if(origen.aArteASCII(grises, arteASCII, 4199))
        cout << arteASCII;
    else
        cout << "La conversión no ha sido posible" << endl;
}