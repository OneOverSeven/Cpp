#include <iostream>
using namespace std;

inline void initNombre()
{
	for (int h = 0; h < 200; h++)
	{
		nombre[h] = 0;
		nombre[2]=1;
	}
}

inline void zeroLigneTemp()
{
	for(int s = 0; s<=199; s++)
	{
		ligneTemp[s]=0;
	}
}

inline void zeroTabTemp()
{
	for (int m = 0; m < 199; m++)
	{
		for (int n = 0; n < 199; n++)
		{
			tabtemp[m][n]=0;
		}
	}
}

inline void multiply()
{
	//k est la position dans le tableau qui représente le nombre que je souhaite mmultiplier.
	for (int k = 199; k > 1; k--)
			{
				if (j == 1)
				{
					memoryTemp = mult[i][j]*nombre[k];
					if (memoryTemp>=10)
					{
						tabtemp[k][k] = (memoryTemp%10);
						tabtemp[k][k-1] = (memoryTemp - (memoryTemp%10))/10;
					}
					else
					{
						tabtemp[k][k] = memoryTemp;
					}
				}

				if(j == 0)
				{
					memoryTemp = mult[i][j]*nombre[k];
					if (memoryTemp>=10)
					{
						tabtemp[k-1][k-1] = (memoryTemp%10);
						tabtemp[k-1][k-2] = (memoryTemp - (memoryTemp%10))/10;
					}
					else
					{
						tabtemp[k-1][k-1] = memoryTemp;
					}
				}
				else
				{
					cout << "il y a un soucis" << endl;
				}
				
			}
}

inline void matrixSum()
{
	for (int p = 0; p <= 199; p++)
	{
		for (int q = 199; q>0; q--)
		{
			var1 = tabtemp[2*p][q]+tabtemp[2*p+1][q];
			if (var1>=10)
			{
				ligneTemp[q] = ligneTemp[q]+(var1 % 10);
				ligneTemp[q-1]++;
			}
			else
			{
				ligneTemp[q] = ligneTemp[q]+var1;
			}
		}
	}
}

inline void refreshNombre()
{
	for (int r = 0; r < 200; r++)
	{
		nombre[r] = tabtemp[r];
	}
}

inline sumNumber()
{
	for (int t = 0; i < 200; t++)
	{
		sum = sum + number[t];		
	}
}

int main()
{
	int nombre[200] = {};
	int mult[99][2] = {};
	int memoryTemp = 0;
	int tabtemp[200][200];
	int ligneTemp[200];
	int var1 = 0;
	int sum = 0;

	initNombre();
	zeroLigneTemp();
	//i est la ligne du tableau contenant les multiplicateurs. 
	//j est l'entier qui multiplie 10^j du multiplicateur.
	for (int i = 0; i < 100; i++)
	{
		for (int j = 1; j >= 0; j--)
		{
			zeroTabTemp();
			zeroLigneTemp();
			multiply();
			matrixSum();
			refreshNombre();
		}
	}
	sumNumber();
	cout << "La somme est: " << sum << endl;

return 0;
}
