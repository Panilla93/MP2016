#include "circulo.h"

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