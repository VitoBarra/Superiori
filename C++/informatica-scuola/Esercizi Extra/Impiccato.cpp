

#include <cstdlib>
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;



string str, hStr;
char ch;
char s;
int life;

bool Victory();
void setup();
void StrHidder();
bool StrShow(char);
void Impiccato(int);

int main()
{
	do
	{
		life = 6;
		hStr = "";
		str = "";
		setup();
		StrHidder();
		while (true)
		{


			system("cls");

			Impiccato(life);

			cout << hStr;

			cout << "\n\ndammi una lettera: ";
			cin >> ch;



			if (!StrShow(ch))
			{
				if (ch == '0')
				{
					cout << "LA PROSSIMA VOLTA COMPLETA IL GIOCO GAY";
					break;
				}
				else
				{
					cout << "la lettera e' sbaglaita\nvite rimanenti: " << --life << endl;
					system("pause>nul");
				}

			}

			if (Victory())
			{
				system("cls");
				Impiccato(life);

				cout << "\nParola completa: " << str;

				cout << "\nCONGRATULAZIONI HAI VINTO";
				break;
			}




			if (life <= 0)
			{
				system("cls");
				cout << "HAI PERSO\n";
				Impiccato(life);
				cout << "\nParola esatta: " << str;
				system("pause>nul");
				break;

			}

		}

		cout << "\n\n\nvoi rigiocare(s/n):";
		cin >> s;
	} while (s == 's' || s == 'S');
	return 0;
}


void setup()
{
	system("cls");
	cout << "-----------------SETUP-----------------\n";
	cout << "Parola: ";
	cin.get();
	getline(cin, str);
	cout << "\n-----------------SETUP-----------------\n";
	system("cls");
}

void StrHidder()
{
	hStr = str;
	for (int j = 0; j < hStr.length(); j++)
	{
		if (hStr[j] != ' ')
			hStr[j] = '_';
		else
			hStr[j] = ' ';
	}
}

bool StrShow(char ch)
{
	bool theriIs = false;
	for (int j = 0; j < hStr.length(); j++)
	{
		if (str[j] == ch)
		{
			hStr[j] = str[j];
			theriIs = true;
		}
	}
	return theriIs;
}


bool Victory()
{
	if (hStr == str)
		return true;
	else
		return false;
}

void Impiccato(int e)
{
	switch (e)
	{
	case 0:
		cout << " O " << endl;
		cout << "-|-" << endl;
		cout << "/ \\ " << endl;
		break;

	case 1:
		cout << " O " << endl;
		cout << "-| " << endl;
		cout << "/ \\ " << endl;
		break;

	case 2:
		cout << " O " << endl;
		cout << " | " << endl;
		cout << "/ \\ " << endl;
		break;

	case 3:
		cout << " O " << endl;
		cout << " | " << endl;
		cout << "/  " << endl;
		break;

	case 4:
		cout << " O " << endl;
		cout << " | " << endl;
		cout << "   " << endl;
		break;

	case 5:
		cout << " O " << endl;
		cout << "   " << endl;
		cout << "   " << endl;
		break;

	default:
		cout << endl << endl << endl;
		break;
	}
}

