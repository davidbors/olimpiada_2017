#include<cstdio>
using namespace std;
FILE *f,*g;
int B,a[1000],b[1000],nc,K;
void citire()
{fscanf(f,"%d%d",&B,&K);
long int nr,N=0;
fscanf(f,"%ld",&nr);
nc=0;
while(nr)
{N=N*10+nr%10;
nr/=10;nc++;
}
a[0]=nc;
for(int i=1;i<=nc;i++)
	{a[i]=N%10;
	N/=10;}
}
void aduna()
{int t=0;
int j=nc,s;
for(int i=1;i<=nc;i++)
{s=t+a[i]+a[j];
 b[j]=s%B;
 t=s/B;
 j--;
}
int k=1;
if(t)
	{b[0]=t; nc++;k=0;}
a[0]=nc;

for(int i=1;i<=a[0];i++)
{a[i]=b[k];k++;}
}

int palindrom()
{int i,j=a[0];
for(i=1;i<=a[0]/2;i++)
	if(a[i]!=a[j]) return 0;
    else j--;
return 1;
}

void scrie()
{for(int i=1;i<=a[0];i++)
	fprintf(g,"%d",a[i]);
}
int main()
{
f=fopen("3-joc.in","r");
g=fopen("3-joc.ok","w");
citire();
int l;
if(palindrom())
	scrie();
else
{int ok=0;
 for(l=1;l<=K && ok==0;l++)
 {for(int i=1;i<=a[0];i++)
	fprintf(g,"%d",a[i]);
  fprintf(g,"+");
  for(int i=a[0];i>=1;i--)
	  fprintf(g,"%d",a[i]);
  fprintf(g,"=");
  aduna();
  scrie();
  fprintf(g,"\n");
  ok=palindrom();
  
 }
 if(ok)
	 {scrie();fprintf(g,"\n%d",l);}
 else
	 fprintf(g,"Esec");
}
fclose(f);
fclose(g);
return 0;
}

