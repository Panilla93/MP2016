/* Programa que calcula un c�rculo con centro en medio de dos c�rculos y radio la mitad de la distancia. 
   Tambi�n calcula su �rea.
   
   Author: MP
   M�dulo no definitivo (creado para ser modificado)

   Un ejemplo de ejecuci�n es:
     Introduzca un circulo en formato radio-(x,y): 3-(0,0)
     Introduzca otro circulo: 4-(5,0)
     El c�rculo que pasa por los dos centros es: 2.5-(2.5,0)
	 Su area es: 19.63
**/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Definici�n de las estructuras
struct Punto {
    double x; 
    double y; 
};

struct Circulo {
    Punto centro; 
    double radio; 
};

// Prototipos de las funciones
void EscribirPunto(const Punto &p); 
Punto LeerPunto(); 
double DistanciaPuntos(const Punto &p1, const Punto &p2);
Punto PuntoMedio(const Punto &p1, const Punto &p2);

void EscribirCirculo(const Circulo &c); 
Circulo LeerCirculo(); 
double AreaCirculo(const Circulo &c);

// Programa principal
int main()
{
    Circulo c1,c2, c3;

    do {
        cout << "Introduzca un circulo en formato radio-(x,y): ";
        c1 = LeerCirculo();
        
        cout << "Introduzca otro circulo: ";
        c2 = LeerCirculo();
    
    } while ( DistanciaPuntos (c1.centro,c2.centro) == 0 );

    c3.centro = PuntoMedio( c1.centro, c2.centro );
    
    c3.radio = DistanciaPuntos( c1.centro, c2.centro ) / 2;
	
    cout << "El circulo que pasa por los dos centros es: ";
	EscribirCirculo( c3 );
    cout << endl << "Su area es: " << AreaCirculo( c3 ) << endl;
}

// Implementaci�n de las funciones
void EscribirPunto(const Punto &p)
{
    cout<<"("<<p.x << " , "<< p.y << ")"<< endl;
}

Punto LeerPunto()
{
    Punto p;
    cin.get();
    cin >> p.x;
    cin.get();
    cin >> p.y;
    cin.get();

    return p;

}

double DistanciaPuntos(const Punto &p1, const Punto &p2)
{
    double a;

    a= sqrt( pow((p2.x-p1.x),2) + pow((p2.y-p1.y),2) );

    return a;
}

Punto PuntoMedio(const Punto &p1, const Punto &p2)
{
    Punto aux;

    aux.x = (p1.x + p2.x)/2;
    aux.y = (p1.y + p2.y)/2;

    return aux;
}

void EscribirCirculo(const Circulo &p)
{
    cout << p.radio << "-" << "("<<p.centro.x<<","<<p.centro.y<< ")"<<endl; 
}

Circulo LeerCirculo()
{
    Circulo c;

    cin >> c.radio;
    cin.get();
    cin.get();
    cin >> c.centro.x;
    cin.get();
    cin >> c.centro.y;
    cin.get();

    return c;
}

double AreaCirculo(const Circulo &c)
{

    return 3,141594 * c.radio;
}
/* Fin: circulomedio.cpp */
 
