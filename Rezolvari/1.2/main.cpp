#include <iostream>
#include <fstream>

using namespace std;

int inv(int x)
{
    int inve =0;
    while(x)
    {
        inve = inve * 10 + x % 10;
        x /= 10;
    }
    return inve;
}
int ToBase(int x,int b) //algoritmul meu de transf nu e conform cu cel din pb
{
    int n = 0;
    while(x)
    {
        n = n * 10 + x % b;
        x /= b;
    }
    return inv(n);
}
int SumToBase(int x,int y,int b)
{   int cx=0,cy=0,z=0,rez=0;
    int aux=0;
    if(x < y)
    {
        aux = x; x = y; y = aux;
    }
    while(x)
    {
        cx = x % 10;
        cy = y % 10;
        if(cx + cy >= b)
        {
            z = cx + cy;
            z = ToBase(z,b);
            rez = rez * 10 + z;
        }
        else{
            z = cx + cy;
            rez = rez * 10 + z;
        }
        x /= 10;
        y /= 10;
    }
    return rez;
}

ifstream f("date.in");
ofstream g("date.out");
int b,k,n,ok,pal;
int main()
{
    f>>b;
    f>>k;
    f>>n;
    while(k&&!ok)
    {
        pal = SumToBase(n,inv(n),b);
        if(pal == inv(pal))
           {
             ok=1;
             n = SumToBase(n,inv(n),b);
           }
        else{
            k--;
            n = SumToBase(n,inv(n),b);
            g<<k<<" ";
            g<<n<<" ";
            g<<inv(n)<<" ";
            g<<SumToBase(n,inv(n),b)<<endl;
        }
    }
    if(ok)
        g<<n;
    else
        g<<"Esec";
    return 0;
}
