//Vito Barra
//esercizio 9
///MCD col metodo di euclide
#include <iostream>

using namespace std;

int MCD(int A, int B)
{
	while (A != B)
	{
		if (A > B)
			A = A - B;
		else
			B = B - A;
	}
}
	
	
int main()
{
	int N1, N2, RIS;
	cout << "dammi il primo numero:\t";
	cin >> N1;
	cout << "dammi il 2 numerop:\t";
	cin >> N2;
	RIS = MCD(N1, N2);
	cout << "\nil massimo comun divisore e':\t" << RIS;


	system("pause>nul");
	return 0;
}
