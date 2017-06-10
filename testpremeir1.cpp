#include <iostream>

using namespace std;

int calc_quotient_euclid (unsigned int dividende , unsigned int diviseur)
{
    unsigned int quotient = 0;
    /*
    Attention au "<=" dans for(...)!!! Prendre par exemple 6 comme dividende et 2 comme diviseur.
    Si on ne met pas le "=" le compteur s'arrete à 2 car 3*2 = 6 et 6 n'est pas strictement
    plus petit que 6...
    Si le compteur s'arrete à 2, quotient = 2 et losrqu'ensuite
    on calcul le reste, on obtient reste = dividende-(quotient*diviseur)) = 6-(2*2) = 2.
    Alors que le reste de la division de 6 par 2 est 0.
    */

    for (unsigned int compteur = 1; (compteur*diviseur) <= dividende; compteur++)
    {
        quotient = compteur;
    }
    return quotient;
}

int calc_reste_euclid (unsigned int dividende, unsigned int diviseur, unsigned int quotient)
{
    unsigned int reste = dividende-(quotient*diviseur);
    return reste;
}

bool testcompteur(unsigned int compteur2, int n)
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

void printresultat (bool x, unsigned int n)
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

void comptereste (unsigned int n)
{
    unsigned int quotient1=0;
    unsigned int reste1=0;
    unsigned int compteur2 = 0;
    bool variablebool=0;
    for (unsigned int i = 2; i < n; i++)
    {
        quotient1 = calc_quotient_euclid(n, i);
        reste1 = calc_reste_euclid(n,i, quotient1);
        if (reste1 != 0)
        {
            compteur2++;
        }
    }
    cout << compteur2 << endl;
    variablebool = testcompteur (compteur2, n);
    printresultat (variablebool, n);
}

int main()
{
    //Pour n> 520572 ca ne fonctionne plus...
    unsigned int n;
    cout << "entrez un nombre et je vous dirai s'il est premier" << endl;
    cin >> n;
    cout << "n = " << n << endl;
    comptereste (n);
    return 0;
}
