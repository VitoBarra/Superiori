//esercizio 23
#include <iostream>
using namespace std;
 main()
 {
 int N=0,LNB,VB;
 cout<<"dammi la lunghrezza del numero binario:\t";
 cin>>LNB;
 do
 {
 cout<<"\ndammi il valore della "<<LNB<<" posizione:\t";
 cin>>VB;
 N=N*2+VB;
 LNB=LNB-1;
 }while(LNB!=0);
 cout<<"\nil numero binario in binario e ':\t"<<N;
 system("pause>nul");
 return 0;
 }
