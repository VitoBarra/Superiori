#include <iostream>
#include "data.h"


using namespace std;

//costruttori
data::data(int& _gg, int& _mm, int& _aaaa)
{
	aaaa = _aaaa;

	if (_mm > 12)
	{
		cout << "mese non acettabile, valode di default 1\n";
		mm = 1;
	}
	else mm = _mm;

	if (data::giorni31(_mm))
	{
		if (_gg > 31)
		{
			cout << "giorno non acettabile, valode di default 1\n";
			gg = 1;
		}
		else gg = _gg;
	}
	else if (data::giorni30(_mm))
	{

		if (_gg > 30)
		{

			cout << "giorno non acettabile, valode di default 1\n";
			gg = 1;
		}
		else gg = _gg;
	}
	else if (data::bifestile(_aaaa))
	{

		if (_gg > 29)
		{
			cout << "giorno non acettabile, valode di default 1\n";
			gg = 1;
		}
		else
			gg = _gg;
	}
	else if (_gg > 28)
	{
		cout << "giorno non acettabile, valode di default 1\n";
		gg = 1;
	}
	else gg = _gg;

}



//costruttori deleganti
data::data(int _gg, int _mm) : data::data { _gg, _mm, aaaa } {}
data::data(int _gg) : data::data{ _gg,mm,aaaa }{}
data::data() : data::data{ gg,mm,aaaa }{}



//metodi
void data::stampa()
{
	cout <<"data: "<< gg << "/" << mm << "/" << aaaa;
}


bool data::giorni31(int _gg) { return _gg == 1 || _gg == 3 || _gg == 5 || _gg == 7 || _gg == 8 || _gg == 10 || _gg == 12; }
bool data::giorni30(int _gg) { return _gg == 4 || _gg == 6 || _gg == 9 || _gg == 11; }
bool data::bifestile(int _aaaa) { return _aaaa % 4 == 0; }




//distruttori
data::~data(){}
