#include<iostream>
#include<fstream>
using namespace std;
ifstream f("tir.in");
ofstream g("tir.out");
unsigned long long dist,nr,i,pret,cost,rest,rez,dif,REZ,lung,lungmax,n;
int ok=1;

int main()
{
    f>>pret>>rez>>n;
    REZ=rez;
    for(i=1; i<=n-1; i++)
    {
        f>>dist;
        if(dist>REZ)
        {
            ok=0;
            i=n;
        }
        if(dist>rez)//trebuie sa alimenteze in statia i+1
        {
            cost+=REZ-rez;
            if(lung>lungmax) lungmax=lung;
            lung=0;
            rez=REZ-dist;
        }
        else //nu alimenteaza in statia i+1
        {
            if(i!=1) lung++; //numar orasul i in care nu alimentez
            rez-=dist;
        }
    }
//daca secventa de lungime maxima e la sfarsit
    if(lung>lungmax && lung>1) lungmax=lung;

    if(ok)
        g<<lungmax<<' '<<cost*pret<<' '<<rez;
    else
        g<<"IMPOSIBIL";
    return 0;
}
