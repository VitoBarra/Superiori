//esercizio 20
#include <iostream>
using namespace std;
 main()
 {
 int A,B,C,MAX;
 cout<<"dammi 3 numeri:\t";
 cin>>A;
 cout<<endl;
 cin>>B;
 cout<<endl;
 cin>>C;
 if(A>B)
 if(A>C)
 MAX=A;
 else
 MAX=C;
 else
 if(B>C)
 MAX=B;
 else
 MAX=C;
 cout<<"\nil massimo e'\t"<<MAX;
 system("pause>nul");
 return 0;
 }
