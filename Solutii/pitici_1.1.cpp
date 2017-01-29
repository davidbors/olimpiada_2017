#include <fstream>

using namespace std;

int main()
{
    ifstream f("in.txt");
    ofstream g("out.txt");

    unsigned long k, pas, j;
    f >> k;
    pas = k;
    j = 1;

    while(pas > j)
    {
        pas -= j;
        ++j;
    }

    g << (j % 2 == 0 ? j - pas + 1 : pas);

    f.close();
    g.close();

    return 0;
}
