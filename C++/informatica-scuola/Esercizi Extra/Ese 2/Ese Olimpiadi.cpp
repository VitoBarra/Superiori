#include <iostream>
#include <fstream>

using namespace std;

fstream in;
fstream out;

int ncase, nbone, ossa[1000], ossatemp[1000], start, pas = 0;

bool Equal(int nbone)
{
	bool equal = false;
	for (int j = 0; j < nbone; j++)
	{
		if (ossa[j] == ossatemp[j])
			equal = true;
		else
		{
			equal = false;
			break;
		}
	}
	return !equal;

}

void vectorinit(int temp[])
{
	for (int j = 0; j < 1000; j++)
		temp[j] = 0;
}


int TestEsercizio()
{
	in.open("input.txt", ios::in);
	out.open("out.txt", ios::out);


	in >> ncase;
	for (int i = 0; i < ncase; i++)
	{
		vectorinit(ossa);
		vectorinit(ossatemp);
		in >> nbone;


		for (int j = 0; j < nbone; j++)
			in >> ossa[j];



		do
		{
			int ncons = 0;
			bool StartSer = false;

			for (int k = 0; k < nbone; k++)
			{
				if (ossatemp[k] < ossa[k])
				{
					ncons++;
					if (!StartSer)
						start = k;
					StartSer = true;
				}
				else if (StartSer)
				{
					StartSer = false;
					break;
				}
			}




			for (int j = start; j < start + ncons; j++)
				ossatemp[j]++;

			pas++;

		} while (Equal(nbone));

		out << "case #" << i + 1 << ":" << pas << endl;
		pas = 0;
	}
	return 0;
}