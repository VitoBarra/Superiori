#include <iostream>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int Summ(int);
int Summ1(int);
int AnniPassati(int);

int cou=0;

int main()
{
	long long int x = 0;
	while (Summ(x) - Summ1(x) < 60000000)
	{
		x++;
		cou++;
	}
	cout << "\nportatori di geni: " << Summ(x) - Summ1(x);
	cout << "\nsiamo alla generazione: " << x;
	cout << "\nsono passati: " << AnniPassati(x)<<" anni";



	system("pause>nul");
	return 0;

}


int AnniPassati(int x)
{
	int s = 0;
	for (int i = 0; i<x; i++)
		s += 25;
	return s;
}


int Summ(int x)
{
	cout << "\n\n THE SERIES IS UNDER : \n\n\n";

	int sum = 0;
	for (int i = 0; i <= x; i++)
	{
		cout << "(4*2^" << i << ")\n";
		sum += 4 * pow(2, i);
	}
	if(cou<2)
		sum += 4;
	cout << "\n\n\n THE SUMMATION IS " << sum << endl;

	return sum;
}

int Summ1(int x)
{
	cout << "\n\n THE SERIES IS UNDER : \n\n\n";

	int sum = 0;
	if (cou >= 2)
	{
		for (int i = 2; i <= x; i++)
		{
			cout << "(4*2^(" << i << "-2)\n";
			sum += 4 * pow(2, i - 2);
		}
	}
	if (cou > 3)
		sum += 4;
	cout << "\n\n\n THE SUMMATION IS " << sum << endl;

	return sum;
}