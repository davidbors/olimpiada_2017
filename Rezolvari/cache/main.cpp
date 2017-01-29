/* Ştiind că litrul de motorină costă X euro, să se afle:
a)	Care este cea mai lungă succesiune de oraşe prin care poate trece Fănel fără oprire, după logica lui?
b)	Câţi euro costă toată motorina, până ajunge la destinaţie?
c)	Câţi litri de motorină mai are în rezervor când ajunge în oraşul n?
*/

#include <iostream>
#include <fstream>

using namespace std;

int v[100000],x,a,n,i,maxi,ax,scs;
int main()
{
    cin>>x; //pretul benzinei
    cin>>a; //capacitatea rezervorului
    cin>>n; //nr de orase
    ax=a; //auxiliar al lui a
    for(i=1; i<n; i++) //distantele intre orase
        cin>>v[i];
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
            ax=a;
        }

    }
    cout<<maxi;
    return 0;
}
