#include "iostream"

using namespace std;

struct Tiempo
{
	int horas;		
	int minutos;
	int segundos;


};
	bool esPosterior(Tiempo &p, Tiempo &s){ 		//p es primer instante y s segundo instante
		bool sol = false;

		if(p.horas < s.horas)
			sol = true;
		else{
			if (p.horas == s.horas)
			{
				if (p.minutos < s.minutos)
					sol = true;
				else{
					if (p.minutos == s.minutos)
					{
						if (p.segundos < s.segundos)
							sol = true;
					}
				}
			}
		}
	return sol;
	
	}
	
	int convertirASegundos (Tiempo &a){

		int segundos=0;

		segundos += (a.horas*3600)+(a.minutos*60)+(a.segundos);

		return segundos;
	}

	Tiempo obtenerNuevoTiempo(Tiempo &T, int &S){
		Tiempo T2;
		int segundos = S%60;
		int minutos = S / 60 ;


		T2.minutos = minutos + T.minutos;
		T2.horas= (T2.minutos/60) + T.horas;


		if (T2.minutos > 60)
		{
			T2.minutos = T2.minutos%60;
		}
		if (T2.horas > 24)
		{
			T2.horas = T2.horas%24;
		}

		return T2;
	}

int main(int argc, char const *argv[])
{
	Tiempo t1, t2;
	int segundos;

	do{
		cout << "Inserta las horas" << endl;

		cin>> t1.horas;


	} while (t1.horas > 24);	

	do{
		cout << "Inserta los minutos" << endl;

		cin>> t1.minutos;


	} while (t1.minutos > 60);

	do{
		cout << "Inserta los segundos" << endl;

		cin>> t1.segundos;


	} while (t1.segundos > 60);


	cout << "T1 = " << t1.horas << " h " << t1.minutos<< " ' " << t1.segundos<< " '' "<< endl;

	segundos = 23452;

	
	t2 = obtenerNuevoTiempo(t1,segundos);

	cout << "T2 = " << t2.horas << " h " << t2.minutos<< " ' " << t2.segundos<< " '' "<< endl;


	cout << " T1 es " << convertirASegundos(t1) << " '' " << endl;

	cout<< " T2 es mayor a T1 ? " << esPosterior(t1,t2) << endl;


	return 0;
}