#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");
unsigned long long X,A,n,v[9999999],scs,aux,maxi,i,alim,pret,prett;
int main()
{
    f>>X;
    f>>A;
    f>>n;
    for(i=1; i<n;i++)
        f>>v[i];
    aux = A;
    for(i=1; i<n; i++)
        if(aux >= v[i]&& i!=1)
        {
            aux -= v[i];
            scs++; //orase consec prin care a fst fara oprire
        }
        else {
            if(scs > maxi)
                maxi = scs; //nr maxim de scsiuni consec
            alim = A - aux; // ? l alimenteaza
            pret = alim * X;
            prett += pret;
            scs=0;
            aux = A;
            aux -= v[i];
        }
    if (scs > maxi )
        maxi = scs;
    g<<maxi<<endl;
    g<<prett<<endl;
    g<<aux<<endl;
    f.close();g.close();
    return 0;
}
