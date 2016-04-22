#include "punto.h"

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