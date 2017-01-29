#include <iostream>
#include <fstream>

using namespace std;

ifstream f("date.in");
ofstream g("date.out");
int x,n,v[15],i,j,poz,k,dif;
int main()
{
    f>>x;
    f>>n;
    for(i=1; i<=n; i++)
        f>>v[i];
    for(i=1; i<=n; i++)
        if(v[i+1]>v[i]&&v[i+1]-v[i]<x)
        {
            dif = v[i+1]-v[i]-1;
            while(dif)
            {
                poz = i+1;
                n++;
                for(j=n; j>poz; j--)
                    v[j]=v[j-1];
                v[poz] = v[i+1]-dif;
                i++;
                dif--;
            }
        }
        else if(v[i+1]<v[i]&&v[i]-v[i+1]<x)
        {
            dif = v[i]-v[i+1]-1;
            while(dif)
            {
                poz = i+1;
                n++;
                for(j=n; j>poz; j--)
                    v[j]=v[j-1];
                v[poz] = v[i]-dif;
                i++;
                dif--;
            }
        }
    for(i=1; i<=n; i++)
        g<<v[i]<<" ";
    return 0;
}
