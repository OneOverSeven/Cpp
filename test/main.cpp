#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
#define PI 3.14159
#define NEWLINE '\n'



double f_distance(double *p1, double *p2)
{
	double d=0;
	for(int i=0; i<3; i++)
	{
		double a=*p1;
		double b=*p2;
		d = d +((a-b)*(a-b)); //le carré de la différence des composantes.

		if(i<2) //Car lorsque i=1, lespinteur aurons déjà été déplacés à la case 2.
		{
			p1++;
			p2++;
		}

	}
	double racine;
	racine = (double) sqrt(d);
	return racine;
}

int main()
{
    double position[9]={0,0,0,1,1,1,2,2,2};
    double distance[3];
	double *p_distance = &distance[0]; // pointeur du vecteur distance
	double *p_position = &position[0]; // pointeur du vecteur position


	for(int i = 0; i<3; i++)
		{
		    p_distance[i] = f_distance(p_position[0], p_position[6]);
			cout << distance[i] << endl;
		}
}
