#include <fstream>

using namespace std;

ifstream f("numar.in");
ofstream g("numar.out");
int put(int x)
{   int z;
    z = 1;
    while(x)
    {
        z *= 3;
        x--;
    }
    return z;
}
int n,i,exp,u;
int main()
{
    f>>n;
    if(n == 1)
        u = 3;
    else if(n >= 2)
        u = 12;
    for(i=3;i<=n;i++)
    {
        exp += 3;
        u += put(exp) ;
    }
   // u += ( exp > 0 ? put(exp+1) : 0 ) ;
    g<<u%10;
    f.close(); g.close();
    return 0;
}
