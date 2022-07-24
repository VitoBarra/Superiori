#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

fstream f;


int calcolatrice()
{
	int a3 = 0, b3 = 0, Nvolte = 0;
	string lallero;
	
	size_t pos = 0;

	long long int s, m, h;
	int a = 0, b = 1, c, d = 0, x, resto, n, n1, n2 = 1, n3, u = 0, med, a1[2], esci;
	char i, k, o, deposito/*, scarico*/;
	//float z;
	string frase;

	do
	{
		esci = 0;
		system("cls");

		cout << "queto e'cio che puo fare questo programma:\n+) somma\n-) sotrazione \n*) moltiplicazione\n/) divisione intera\n^) elevamento a potenza\nF) fibonacci\nN) spelling\nR) numeri random\nC) convertitore di tempo\nI) nome al contrario\nM) numero medio\nT) cronometro\nB) Capslocka la parola\nL) cerca il vito\nscegli cosa fare:\t";
		cin >> i;
		i = toupper(i);
		cout << endl;
		switch (i)
		{
		case '+':
			cout << "stai per eseguire una addizione...\ninserisci il primo numero: ";
			cin >> a;
			cout << "inserisci il secondo numero:\t";
			cin >> b;
			x = a + b;
			cout << "\nla somma e': " << x << "\n";
			esci = 1;
			break;
			/*
			a = primo numero
			b = secondo numero
			x = somma
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case '-':
			cout << "stai per eseguire una sottrazione...\n";
			cout << "inserisci il primo numero: ";
			cin >> a;
			cout << "inserisci il secondo numero: ";
			do
			{
				if (b > a)
					cout << "il valore e' errato, inseriscine un altro:\t";
				cin >> b;
			} while (b > a);
			x = a - b;
			cout << "\nla differenza e': " << x << endl;
			esci = 1;
			break;
			/*
			a = primo numero
			b = secondo numero
			x = differenza
			note: con il ciclo do-while evitiamo che la differenza sia negativa
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case '*':
			cout << "stai per eseguire una moltiplicazione...\ninserisci il primo numero:\t";
			cin >> a;
			cout << "inserisci il secondo numero: ";
			cin >> b;
			x = a * b;
			cout << "\nil prodotto e': " << x << "\n";
			esci = 1;
			break;
			/*
			a = primo numero
			b = secondo numero
			x = prodotto
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case '/':
			cout << "stai per eseguire una divisione INTERA...\ninserisci il primo numero:\t";
			cin >> a;
			cout << "inserisci il secondo numero:\t";
			cin >> b;
			while (b > a)
			{
				cout << "non puoi dividere un numero per un altro numero piu'grande, inseriscine un altro:\t ";
				cin >> b;
			}
			try
			{
				x = a / b;
				resto = a % b;
			}
			catch (...)
			{
				cout << "\nil quoziente e':  infinito\n";
			}
			cout << "\nil quoziente intero e':\t\t" << x << "\nil resto e':\t\t\t" << resto << endl;
			esci = 1;
			break;
			/*
			a = primo numero
			b = secondo numero
			x = quoziente intero
			x1 = quoziente decimale
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case '^':
			cout << "stai per eseguire un elevamento a potenza...\n";
			do
			{
				cout << "qull' e'la base? ";
				cin >> a1[1];
			} while (a1[1] < 2);
			a1[1] = a1[0];
			cout << "qull' e' l'esponente? ";
			cin >> b;
			cout << "\nle potenze di " << a1[1] << " fino alla " << b << " potenza sono:";
			cout << "\n\n1";
			for (n = 1; n <= b - 1; n = n + 1)
			{
				x = a1[0] * a1[1];
				a1[1] = x;
				cout << "," << x;
			}
			esci = 1;
			break;
			/*
			a1 = base
			b = esponente
			x= potenza
			n = contatore
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'F':
			n3 = 0;
			n2 = 1;
			n1 = 0;
			cout << "stai per eseguire la sequenza di fibonacci...\n";
			do
			{
				cout << "quante volte la sequenza si ripetera? ";
				cin >> u;
			} while (u < 3);
			cout << "\nla sequenza e': \n0, 1";
			for (u = u - 2; u != 0; u = u - 1)
			{
				n3 = n1 + n2;
				cout << ", " << n3;
				n1 = n2;
				n2 = n3;
			}
			cout << endl;
			esci = 1;
			break;

			/*
			u = nummero delle volte che la sequenza si deve ripetere
			n = contatore
			n1,n2,n3 = primo , secondo e terzo numero della sequenza
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'N':
			cout << "stai per contare il numero dei caratteri del tuo input e ne farai lo spelling...\ndigita i caratteri da numerare:\n";
			cin >> frase;
			a = frase.length();//nella variabbile c la val lunghezza della stringa
			c = a;
			cout << "\n ";
			do
			{
				cout << frase[d] << " ";
				d++;
				c--;
			} while (c != 0);
			cout << endl;
			for (b = 1; b <= a; b = b + 1)
			{
				cout << " " << b;
			}
			esci = 1;
			break;
			/*
			b = contatore
			a = numero di caratteri
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'R':
			cout << "stai per generare dei numeri randomici...\n";
			cout << "quanti numeri randomici vuoi?\t";
			cin >> n;
			cout << "da 0 a quanti numeri vuoi che siano compresi?\t";
			cin >> b;
			cout << "\n";
			c = 0;
			do
			{
				a = rand() % b;
				c = c + 1;
				cout << "il " << c << " numero randomico e': " << a << "\n";
			} while (c < n);
			esci = 1;
			break;
			/*
			n = numero di numeri randomici (esecuzione del cilco)
			b = numero fra cui è compreso il numero random quindi compreso tra 0 e b ( numero per cui si dive il numero random)
			c = contatore dei numeri random e quindi del ciclo
			a = variabbile ceh contiene il resto del numero randomico ovvero il numero randomico contenuto nel reing indicato
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'C':
			cout << "stai per fare una conversione di tempo...\n\n";
			cout << "cosa vuoi convertire?\nS)secondi in minuti e ore\nM)minuti in ore \nK)minuti in secondi\nO)ore in secondi\nP)ore in minuti\nCosa vuoi fare: \t";
			cin >> k;
			k = toupper(k);
			switch (k)
			{
			case 'S':
				cout << "\nquanti secendi vuoi convertire:\t";
				cin >> c;
				b = c / 60;
				c = c - (b * 60);
				while (b >= 60)
				{
					a = b / 60;
					b = b - (a * 60);
				}
				cout << "\nore: " << a << "\nminuti: " << b << "\nsecondi: " << c << "\n";
				break;

			case'M':
				cout << "\nquanti minuti: \t";
				cin >> b;
				a = b / 60;
				b = b % 60;
				cout << "\nore: " << a << "\nminuti: " << b << "\n";
				break;

			case 'K':
				cout << "\nquanti minuti: \t";
				cin >> b;
				c = b * 60;
				cout << "\ni secondi sono: " << c << "\n";
				break;

			case 'O':
				cout << "\nquante ore: \t";
				cin >> a;
				c = a * 360;
				cout << "\ni secondi sono: " << c << "\n";
				break;

			case'P':
				cout << "\nquante ore:\t";
				cin >> a;
				b = a / 60;
				cout << "\ni minuti sono: " << b << "\n";
				break;
			}
			c = 0;
			b = 0;
			a = 0;
			esci = 1;
			break;
			/*
			a = ore
			b = minuti
			c = secondi
			*/
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'I':
			cout << "stai per invertire le lettere del tuo nome...\nqual e' il tuo nome?\n";
			cin >> frase;
			c = frase.length();
			a = 0;
			b = c - 1;
			while (a < b)
			{
				deposito = frase[a];
				frase[a] = frase[b];
				frase[b] = deposito;
				a++;
				b--;
			}
			cout << "\nil tuo nome al contrario e':\t" << frase;
			esci = 1;
			break;
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'M':
			cout << "stai per trovare il numero medio fra 3 numeri: \n\t";
			cin >> a;
			cout << "\t";
			cin >> b;
			cout << "\t";
			cin >> c;
			cout << "\n";


			if (a > b)
				if (b > c) med = b;
				else
					if (a > c) med = c;
					else med = a;
			else
				if (a > c) med = a;
				else
					if (c > b) med = b;
					else med = c;


					cout << "il numero medio e': " << med;
					esci = 1;
					break;
					/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'T':
			system("cls");
			s = 0;
			m = 0;
			h = 0;

			do
			{
				do
				{
					do
					{

						cout << h << "h " << m << "m " << s << "s";
						Sleep(1000);
						s = s + 1;
						system("cls");

					} while (s < 60);

					s = s - 60;
					m = m + 1;
					cout << h << "h " << m << "m " << s << "s";
					system("cls");

				} while (m < 60);

				m = m - 60;
				h = h + 1;
				cout << h << "h " << m << "m " << s << "s";
				system("cls");

			} while (h < 24);
			esci = 1;
			break;
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'B':
			cout << "\ndammi una frase da cApSlOkArE:\t";
			cin >> frase;
			c = frase.length();
			cout << "\nla frase capsolokata e':\n";
			do
			{
				b = a % 2;
				if (b == 0)
					frase[d] = toupper(frase[d]);
				else
					d = d + 2;
				cout << frase[a];
				a++;
				c--;
			} while (c != 0);
			system("pause>nul");
			esci = 1;

			break;
			/*_______________________________________________________________________________________________________________________________________________________________________________________________*/
		case 'L':
			cout << "\nquante volte la parola 'vito' compare nel file\n";
			
			f.open("nome gentaccia.txt");
			if (f.is_open())
			{
				cout << "\ne il contenuto del file e':\n\n";
				getline(f, lallero);
				cout << lallero << endl << endl;
				f.close(); f.clear(); //funzioni 1) chiusura del file  2) pulizia bit di f
			}
			else
				cout << "mancu pu caz";

			cout << "vito e'stato trovato alle/a posizione: ";
			while ((pos = lallero.find("vito",pos)) != string::npos)
			{
				pos++;
				Nvolte++; 
				cout << pos - 1 << ", ";
			}

			cout << "\n\n'vito' e' stato trovato: " << Nvolte << " volte in totale";
			system("pause> nul");

			esci = 1;
			break;
		case'V':
			int vettore[25];
			int MAX = 0, MIN = 0;
			int MAXposA = 0, MINposA = 0;
			int CONT = 0;


			for (int NUM = 0; NUM <= 25; NUM++)
			{
				cout << "dammi un numero nella " << NUM + 1 << " posizione:\t";
				cin >> vettore[NUM];

				if (vettore[MAXposA] < vettore[MAXposA + 1])
				{
					MAX = vettore[MAXposA + 1];
					MAXposA++;
				}

				if (vettore[MINposA] > vettore[MINposA + 1])
				{
					MIN = vettore[MINposA + 1];
					MINposA++;
				}
				NUM++;


			}
			cout << "il massimo e': " << MAX << "il minimo e':" << MIN;
			system("pause>nul");


		} while (esci == 0);

		cout << "\n\nvuoi continuare?(S|N)------> ";
		cin >> o;
		o = toupper(o);
	} while (o == 'S');

	return 0;

}