//esercizio 9
#include <iostream>
using namespace std;
 main()
 {
 float prezzo, sconto;
 cout<<"dammiil prezzo iniziale:\t";
 cin>>prezzo;
 cout<<"\na quanto e'scontato:\t";
 cin>>sconto;
 prezzo=prezzo-(prezzo*sconto/100);
 cout<<"\nil prezzo scontato e ':\t"<<prezzo;
 system("pause>nul");
 return 0;
 }
