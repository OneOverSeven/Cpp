#include <iostream>
using namespace std;

void printresultat (bool x, long long unsigned int n)
{
    if (x != 0)
    {
        cout << n <<" est premier" << endl;
    }
    else
    {
        cout << n << " n'est pas premier" << endl;
    }
}

bool testcompteur(int compteur2, int n)
{
    if (compteur2 == (n-2))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool comptereste (int n)
{
    int compteur2 = 0;
    for (int i = 2; i < n; i++)
    {
        if ((n%i) != 0)
        {
            compteur2++;
        }
    }
    return testcompteur(compteur2, n);
}

int main()
{
    unsigned long long u=0;
    for (int n = 2; n < 200000; n++)
    {
        if (comptereste(n))
                {
                    u=u+(static_cast<unsigned long long>(n));
                }

    }
    cout << "La somme est: " << u << endl;
return 0;
}

