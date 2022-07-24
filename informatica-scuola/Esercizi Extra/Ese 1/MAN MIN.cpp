#include<iostream>


using namespace std;

int main()
{
	const int NV = 5;
	int vettore[] = { 2,1,4,3,1 };
	int MASP = 0, MINP = 0;
	int MAS = vettore[MASP], MIN = vettore[MINP];
	int Pmas[NV], Pmin[NV];
	int N = 0, N1 = 0;
	

//RICERCA
	for (int NUM = 1; NUM < NV; NUM++)
	{
		if (vettore[MASP] < vettore[NUM])
		{
			MAS = vettore[NUM];
			MASP = NUM;
		}
		if (vettore[MINP] > vettore[NUM])
		{
			MIN = vettore[NUM];
			MINP = NUM;
		}

		cout << "massimo attuale " << MAS << " minimo attuale " << MIN << endl;

	}

//VOLTE MAS/MIN

	for (int NUM = 0; NUM < NV; NUM++)
	{

		if (MAS == vettore[NUM])
		{
			Pmas[N] = NUM;
			N++;
		}
		if (MIN == vettore[NUM])
		{
			Pmin[N1] = NUM;
			N1++;
		}
	}

	N--; N1--;


//STAMPA
	int V = 0;
	while (N >= 0)
	{

		if (N == 0 && !(N > 0))
		{
			if (V == 0)
			{
				cout << "\nil massimo e' nella posizione: ";
				V++;
			}
			cout << Pmas[0];
			break;
		}

		if (V == 0)	
		{			
			cout << endl << "i massimi sono nelle posizioni: ";
			V++;
		}

		cout << Pmas[N] << " ";
		N--;
	}




	V = 0;
	while (N1 >= 0)
	{

		if (N1 == 0 && !(N1 > 0))
		{
			if (V == 0)
			{
				cout << "\nil minimo e' nella posizione: ";
				V++;
			}
			cout << Pmin[0];
			break;
		}

		if (V == 0)
		{
			cout << endl << "i minimi sono nelle posizioni: ";
			V++;
		}
			
		cout << Pmin[N1] << " ";
		N1--;
	}

	system("pause>nul");
	return 0;
}