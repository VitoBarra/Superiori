//Vito Barra
//esercizio 10
///Scrivere una funzione per trovare il minimo fra due numeri e usarla per trovare il minimo fra tre numeri
#include <iostream>

using namespace std;

int min(int, int);

int main()
{
	int N1, N2, N3, MIN;
	cout << "dammi 3 numeri:\t";
	cin >> N1; cin >> N2; cin >> N3;

	MIN = min(min(N1, N2), N3);
	cout << "\nil numero piu piccolo e' " << MIN;
	system("pause > nul");
	return 0;
}

int min(int A, int B)
{
	int min = 0;
	if (A < B)
		min = A;
	else
		min = B;
	return min;
}
