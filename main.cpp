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
/*
void printtableau (unsigned int *p1, unsigned int n)
{
    for (int i = 0; i < (n-1); i++)
    {
        cout << p1[i] << endl;
    }
}

*/

bool testprimalite(unsigned int *p4, unsigned int n)
{
    unsigned int compteur1=0;
    /*
    Dans la boucle for, il faut mettre "n-3" car i
    est l'indice de la position dans le tableau p4[i],
    cette position commence à 0, la dimension du tableau
    est n-1 et je m'arrete à l'avant derniere case car
    mon test consiste à compter le nombre d'éléments
    dans ce tableau (qui contient tous les restes
    des divisions euclidienne des nombre inferieur à au
    nombre n dont je souhaite connaitre la primalité)
    qui sont different de zero. Si tous les éléments de ce tableau
    sont different de zero jusqu'à l'avant dernier,
    c'est que le nombre n est premier.
    */
    for (unsigned int i=0; i<=(n-3); i++)
    {
        if (p4[i]!=0)
        {
            compteur1++;
            //cout << "le compteur1: " << compteur1 << endl;
        }
    }
    if (compteur1 == (n-2))
    {
        //cout << "n est premier" << endl;
        return true;
    }
    else
    {
        //cout << "n n'est pas premier" << endl;
        return false;
    }
}

void printtestprimalite(bool x)
{
    if (x == 1)
        cout << "n est premier" << endl;
    else
        cout << "n n'est pas premier" << endl;

}

void remplirtableau (unsigned int n)
{
    unsigned int position=0;
    unsigned int quotient1=0;
    unsigned int reste1=0;
    //int tableau_diviseur[n-1];
    //int tableau_quotient[n-1];
    unsigned int tableau_reste[n-1];
    for (unsigned int i = 2; i <= n; i++)
    {
        position = i-2;
        quotient1 = calc_quotient_euclid(n, i);
        reste1 = calc_reste_euclid(n,i, quotient1);
        //tableau_diviseur[position]=i;
        //tableau_quotient[position]=quotient1;
        tableau_reste[position]=reste1;
    }
    //printtableau (tableau_diviseur, tableau_quotient, tableau_reste, n);
    bool x = testprimalite(tableau_reste, n);
    cout << "n = " << n << endl;
    printtestprimalite(x);

}

int main()
{
    //Pour n> 520572 ca ne fonctionne plus...
    unsigned int n=520572;
    remplirtableau (n);
    return 0;
}
