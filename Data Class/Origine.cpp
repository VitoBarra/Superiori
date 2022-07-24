#include <iostream>
#include "data.h"


using namespace std;



int main()
{

	int a = 24, b = 2, c = 2001;
	class data d1 { a, b, c }, d2{ a, b }, d3{ a }, d4{};
	cout << "d1) ";
	d1.stampa();
	cout << endl << "d2) ";
	d2.stampa();
	cout << endl << "d3) ";
	d3.stampa();
	cout << endl << "d4) ";
	d4.stampa();



	system("pause > nul");
	return 0;
}