//Vito Barra
//esercizio 34
///Data una frase scritta nel file input.txt contare le vocali e scrivere il risultato in output.txt
#include <iostream>
#include <fstream>

using namespace std;

fstream F, F1;

void leggi();

int main()
{
	leggi();

	system("pause>nul");
	return 0;

}



void leggi()
{
	F.open("input.txt", ios::in);
	F1.open("output.txt", ios::out | ios::trunc);

	if (F.is_open())
	{
		char linea[256];
		F.getline(linea, 256);

		for (int j = 0; j < 256; j++)
		{
			switch (linea[j])
			{
			case'a':
				F1 << linea[j] << " ";
				break;
			case'e':
				F1 << linea[j] << " ";
				break;
			case'i':
				F1 << linea[j] << " ";
				break;
			case'o':
				F1 << linea[j] << " ";
				break;
			case'u':
				F1 << linea[j] << " ";
				break;
			case 'A':
				F1 << linea[j] << " ";
				break;
			case'E':
				F1 << linea[j] << " ";
				break;
			case'I':
				F1 << linea[j] << " ";
				break;
			case'O':
				F1 << linea[j] << " ";
				break;
			case'U':
				F1 << linea[j] << " ";
				break;
			}
		}
		cout << "SALVATAGGIO DATI ESEGUITA CON SUCESSO";

		F1.clear();
		F1.close();
	}
	else
		cout << "file di input non trovato";

	F.clear();
	F.close();
}

