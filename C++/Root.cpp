#include <iostream>

using namespace std;


void Primi(int [],  int);
void Root(int[],  int,  int );

int RootFunctionTest()
{
	int V[100000];
	int n, RootI;

	wcout << "radicando(\u221A): "; cin >> n;
	cout << "indice: "; cin >> RootI;

	Primi(V, n);
	Root(V, n, RootI);

	system("pause>nul");
	return 0;
}


void Primi(int V[],  int n)
{
	for (int j = 1; j < n; j++)
		V[j] = j + 1;

	int k = 2, Mu = 2, N=0;
	bool loop;

	do
	{
		Mu = 2;
		loop = false;
		do
		{
			N = k * Mu;
			V[N-1] = 0;
			Mu++;
		} while (N < n);


		for (int j = k-1; j < n; j++)
			if (V[j] > k)
			{
				loop = true;
				k = V[j];			
				break;
			}

	} while (loop);


}
void Root(int V[], int n, int i)
{
	int temp, Ntemp = n, multp = 1;

	for (int j = n - 1; j >= 0; j--)
	{
		if (V[j] > 0)
		{
			temp = V[j];

			for (int k = 0; k < i; k++)
			{
				if (Ntemp%temp == 0)
				{
					Ntemp = Ntemp / temp;
				}
				else
				{
					Ntemp = n;
					break;
				}

				if (k == (i - 1))
				{
					n = n / (temp*i);
					multp = multp * temp;
				}
			}

		}

	}
	if (Ntemp == 1)
		cout << "risultato: " << multp;
	else if (multp == 1)
		cout << "risultato: " << i << "^root(" << Ntemp << ")";
	else
		cout << "risultato: " << multp << " x " << i << "^root(" << Ntemp << ")";
}