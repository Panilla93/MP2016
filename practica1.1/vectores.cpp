#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	bool fin= false;
	const int MAX = 10000;
	int a=0;
	int b=0;
	int v1[MAX];
	int v1usado=0;
	int v2[MAX];
	int v2usado=0;
	int v3[MAX];
 	

 	do{
		cout<<"Introduce valor del vector 1 (para salir -1)"<< endl;
		cin >> a;

		if(a != -1){
			v1[v1usado]=a;
			v1usado++;
		}
		else
			fin = true;
	
	}while(!fin || v1usado == MAX);

	fin=false;

	do{
		cout<<"Introduce valor del vector 2(para salir -1)"<< endl;
		cin >> b;
		
		if(b != -1){
			v2[v2usado]=b;
			v2usado++;
		}
		else
			fin = true;

	}while(!fin || v2usado == MAX );

	cout <<

	int aux;
	for (int i = 0; i < v1usado; i++){	
		for (int j = 0; j < v1usado; j++)
		{
			if (v1[i]>v1[j])
			{
				aux=v1[i];
				v1[i]=v1[j];
				v1[j]=v1[i];
			}
		}
	}

	cout << "sale bucle 1 y entra bucle 2";
	for (int i = 0; i < v2usado; i++){	
		for (int j = 0; j < v2usado; ++i)
		{
			if (v2[i]>v2[j])
			{
				aux=v2[i];
				v2[i]=v2[j];
				v2[j]=v2[i];
			}
		}
	}
	cout << "sale bucle 2 ";

	int i=0;
	int j=0;
	int k=0;

	if(	(v2usado+v1usado) < 10000){

		while (j < v2usado || i < v1usado ){

			if (v1[i] < v2[j]){
				v3[k]=v1[i];
				i++;
			}
			else{
				v3[k]=v2[j];
				j++;
			}
			k++;
		}
		while(j >= v2usado && i < v1usado){
			v3[k]=v1[i];
			i++;
			k++;
		}

		while(i >= v1usado && j > v2usado ){
			v3[k]=v2[j];
			j++;
			k++;
		}
	

		for (int i = 0; i < k; i++)
		{
			cout << v3[i] << " ";
		}
		cout<<endl;
	}
	else
		cout<<"Los vectores son muy grandes"<< endl;

	return 0;
}