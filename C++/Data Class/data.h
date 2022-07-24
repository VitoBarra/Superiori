#pragma once
class data
{
public:

	data(int& _gg, int& _mm, int& _aaaa);
	data(int _gg, int _mm);
	data(int _gg);
	data();





	void stampa();




	~data();
private:

	bool bifestile(int);
	bool giorni30(int);
	bool giorni31(int);


	int gg = 6, mm = 9, aaaa = 1470;
};