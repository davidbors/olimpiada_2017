/* Ştiind că litrul de motorină costă X euro, să se afle:
a)	Care este cea mai lungă succesiune de oraşe prin care poate trece Fănel fără oprire, după logica lui?
b)	Câţi euro costă toată motorina, până ajunge la destinaţie?
c)	Câţi litri de motorină mai are în rezervor când ajunge în oraşul n?
*/

#include <iostream>
#include <fstream>

using namespace std;
ifstream f("tir.in");
ofstream g("tir.out");
int v[100000],x,a,n,i,maxi,ax,scs,pm,nrp,l,z;
int main()
{
    f>>x; //pretul benzinei
    f>>a; //capacitatea rezervorului
    f>>n; //nr de orase
    ax=a; //auxiliar al lui a
    for(i=1; i<n; i++) //distantele intre orase
        f>>v[i];
    for(i=1; i<n; i++)
    {
        if(v[i]<ax)
        {
            scs++; //nr de orase succesive parcurse fara alimentare
            ax-=v[i];
        }
        else
        {
            if(scs>maxi)
                maxi=scs;
            scs=0;
            z=a-ax;
            l+=z;
            ax=a;
        }


    }
    g<<maxi<<" ";
    g<<z*a*x<<" "; ///nr de litri pusi * pretul motorinei
    g<<ax;
    f.close();
    g.close();
    return 0;
}
