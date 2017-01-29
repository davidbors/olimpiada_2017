/*

*/
#include <fstream>
int x,a,n,dist[100],aux,j,s,maxi,i;
using namespace std;
ifstream f ("date.in");
ofstream g ("date.out");
int main()
{
    f>>x;
    f>>a;
    f>>n;
    for(i=0; i<n-1; i++)
        f>>dist[i];
    aux = a;
    for(i=0; i<n-1; i++)
    {

        for(j=i; j<n-1; j++)
        {
            if(aux-dist[j]<=0)
            {
                j=n;
                i += s;
                if(maxi<s)
                    maxi = s;
                s = 0;
            }
            else
            {
                aux -= dist[j];
                s++;
            }

        }
    }
    g<<maxi;
    f.close();
    g.close();
    return 0;
}
