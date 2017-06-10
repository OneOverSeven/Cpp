#include <iostream>

using namespace std;
bool testcompteur(unsigned long compteur2, unsigned long n)
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

bool comptereste (unsigned long n)
{
    unsigned long compteur2 = 0;
    bool variablebool=0;
    for (unsigned long i = 2; i <= n; i++)
    {
        if ((n%i) != 0)
        {
            compteur2++;
        }
    }
    //cout << "compteur2 = " << compteur2 << endl;
    variablebool = testcompteur(compteur2, n);
    //printresultat(variablebool, n);
    return variablebool;
}

void checkpremiercompte ()
{

}

int main()
{
    int compteur3 = 0;
    unsigned long u=0;
    unsigned long pif = 0;
    for (unsigned long n = 2; n < 9999999999; n++)
    {
        if ((comptereste (n))!=0)
                {
                    u=u+n;
                    //compteur3++;
                    if (n>11)
                    {
                        cout << "u est: " << u << endl;
                    }
                }
    }
return 0;
}

