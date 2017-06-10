#include <iostream>
using namespace std;
int main()
{
	int nombre[200];
	int mult[99][2] = {{0,1},
{0,2},
{0,3},
{0,4},
{0,5},
{0,6},
{0,7},
{0,8},
{0,9},
{1,0},
{1,1},
{1,2},
{1,3},
{1,4},
{1,5},
{1,6},
{1,7},
{1,8},
{1,9},
{2,0},
{2,1},
{2,2},
{2,3},
{2,4},
{2,5},
{2,6},
{2,7},
{2,8},
{2,9},
{3,0},
{3,1},
{3,2},
{3,3},
{3,4},
{3,5},
{3,6},
{3,7},
{3,8},
{3,9},
{4,0},
{4,1},
{4,2},
{4,3},
{4,4},
{4,5},
{4,6},
{4,7},
{4,8},
{4,9},
{5,0},
{5,1},
{5,2},
{5,3},
{5,4},
{5,5},
{5,6},
{5,7},
{5,8},
{5,9},
{6,0},
{6,1},
{6,2},
{6,3},
{6,4},
{6,5},
{6,6},
{6,7},
{6,8},
{6,9},
{7,0},
{7,1},
{7,2},
{7,3},
{7,4},
{7,5},
{7,6},
{7,7},
{7,8},
{7,9},
{8,0},
{8,1},
{8,2},
{8,3},
{8,4},
{8,5},
{8,6},
{8,7},
{8,8},
{8,9},
{9,0},
{9,1},
{9,2},
{9,3},
{9,4},
{9,5},
{9,6},
{9,7},
{9,8},
{9,9}};
	int memoryTemp = 0;
	int tabtemp[200][200];
	int ligneTemp[200];
	int sum = 0;

	for (int h = 0; h < 200; h++)
	{
		nombre[h]=0;
		nombre[2]=1;
	}

	for(int s = 0; s<=199; s++)
	{
		ligneTemp[s]=0;
	}
	//i est la ligne du tableau contenant les multiplicateurs. 
	//j est l'entier qui multiplie 10^j du multiplicateur.
	for (int i = 0; i < 99; i++)
	{
		for (int j = 1; j >= 0; j--)
		{
			for (int m = 0; m < 199; m++)
			{
				for (int n = 0; n < 199; n++)
				{
					tabtemp[m][n]=0;
				}
			}

			for(int ss = 0; ss<=199; ss++)
			{
				ligneTemp[ss]=0;
			}

			//k est la position dans le tableau qui représente le nombre que je souhaite mmultiplier.
			for (int k = 199; k > 1; k--)
					{
						if (j == 1)
						{
							memoryTemp = mult[i][j]*nombre[k];
							if (memoryTemp>=10)
							{
								tabtemp[k][k] = (memoryTemp%10);
								tabtemp[k][k-1] = ((memoryTemp - (memoryTemp%10))/10);
							}
							else
							{
								tabtemp[k][k] = memoryTemp;
							}
						}

						else
						{
							memoryTemp = mult[i][j]*nombre[k];
							if (memoryTemp>=10)
							{
								tabtemp[k-1][k-1] = (memoryTemp%10);
								tabtemp[k-1][k-2] = ((memoryTemp - (memoryTemp%10))/10);
							}
							else
							{
								tabtemp[k-1][k-1] = memoryTemp;
							}
						}

				
					}
			for (int p = 0; p <= 99; p++)
			{
				for (int q = 199; q>0; q--)
				{
					int var2=0;
					var2 = tabtemp[2*p][q]+tabtemp[2*p+1][q];
					if (var2>=10)
					{
						ligneTemp[q] = ligneTemp[q]+(var2%10);
						ligneTemp[q-1]++;
					}
					else
					{
						ligneTemp[q] = ligneTemp[q]+var2;
					}
				}
			}
			
			for (int r = 0; r < 200; r++)
			{
				nombre[r] = ligneTemp[r];
			}
		}
	}
			for (int t = 0; t < 200; t++)
			{
				sum = sum + nombre[t];		
			}

	for (int z = 0; z < 200; z++)
	{
		cout << nombre[z] << " ";
	}
	cout << "La somme est: " << sum << endl;

return 0;
}
