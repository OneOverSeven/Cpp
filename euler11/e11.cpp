#include <iostream>

using namespace std;

int main()
{
	int a1 = 0;
	int b1 = 0;

    int a2 = 0;
    int b2 = 0;

    int a3 = 0;
    int b3 = 0;

    int a4 = 0;
    int b4 = 0;

    int a5 = 0;
    int a6 = 0;
    int a7 = 0;
    int a8 = 0;
    int a9 = 0;
    int a10 = 0;
    int a11 = 0;
    int a12 = 0;

    int a13 = 0;
    int b13=0;

    int b5 = 0;

    int tab2[8];
    int maxtab = 0;

    unsigned short tab[20][20]={{8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
{52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
{24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
{67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
{24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
{21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
{16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
{86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
{19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
{4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
{88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
{4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
{20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
{20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
{1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48}};

    // ligne par ligne horizonalement de gauche à droite
    for (int i = 0; i <= 16; i++)
    {
    	for (int j = 0; j <= 19; j++)
    	{
    		a1=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i][j+1]))*(static_cast<int>(tab[i][j+2]))*(static_cast<int>(tab[i][j+3]));
    		if (a1 > b1)
    		{
    			b1=a1;
    		}


    	}
    }
    cout << "b1 = " << b1 << endl;

        //trait horizontal qui parcour de gauche à droite et de haut en bas
    for (int i = 0; i <= 19; i++)
    {
        for (int j = 0; j <= 16; j++)
        {
            a13=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i][j+1]))*(static_cast<int>(tab[i][j+2]))*(static_cast<int>(tab[i][j+3]));
            if (a13 > b13)
            {
                b13=a13;
            }


        }
    }
    cout << "b13 = " << b13 << endl;
    
    // col par col de haut en bas
    for (int j = 0; j <= 19; j++)
    {
        for (int i = 0; i <= 16; i++)
        {
            a2=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i+1][j]))*(static_cast<int>(tab[i+2][j]))*(static_cast<int>(tab[i+3][j]));
            if (a2 > b2)
            {
                b2=a2;
            }


        }
    }
    cout << "b2 = " << b2 << endl;

    // ligne par ligne, diagonale comme ca \ de gauche à droite
    for (int i = 0; i <= 16; i++)
    {
        for (int j = 0; j <= 16; j++)
        {
            a3=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i+1][j+1]))*(static_cast<int>(tab[i+2][j+2]))*(static_cast<int>(tab[i+3][j+3]));
            if (a3 > b3)
            {
                b3=a3;
            }
        }
    }
        cout << "b3 = " << b3 << endl;

    // ligne par ligne, diagonale comme ca / de gauche à droite
    for (int i = 0; i <= 16; i++)
    {
        for (int j = 19; j >= 3; j--)
        {
            a4=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i+1][j-1]))*(static_cast<int>(tab[i+2][j-2]))*(static_cast<int>(tab[i+3][j-3]));
            if (a4 > b4)
            {
                b4=a4;
            }
        }
    }
        cout << "b4 = " << b4 << endl;

//Wtf?
    for (int i = 3; i <= 16; i++)
    {
        for (int j = 3; j <= 16; j++)
        {
            a5=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i-1][j]))*(static_cast<int>(tab[i-2][j]))*(static_cast<int>(tab[i-3][j]));
            a6=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i-1][j+1]))*(static_cast<int>(tab[i-2][j+2]))*(static_cast<int>(tab[i-3][j+3]));
            a7=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i][j+1]))*(static_cast<int>(tab[i][j+2]))*(static_cast<int>(tab[i][j+3]));
            a8=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i+1][j+1]))*(static_cast<int>(tab[i+2][j+2]))*(static_cast<int>(tab[i+3][j+3]));
            a9=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i+1][j]))*(static_cast<int>(tab[i+2][j]))*(static_cast<int>(tab[i+3][j]));
            a10=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i+1][j-1]))*(static_cast<int>(tab[i+2][j-2]))*(static_cast<int>(tab[i+3][j-3]));
            a11=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i][j-1]))*(static_cast<int>(tab[i][j-2]))*(static_cast<int>(tab[i][j-3]));
            a12=(static_cast<int>(tab[i][j]))*(static_cast<int>(tab[i-1][j-1]))*(static_cast<int>(tab[i-2][j-2]))*(static_cast<int>(tab[i-3][j-3]));
            tab2[0]=a5;
            tab2[1]=a6;
            tab2[2]=a7;
            tab2[3]=a8;
            tab2[4]=a9;
            tab2[5]=a10;
            tab2[6]=a11;
            tab2[7]=a12;

            for (int p = 0; p <= 7; p++)
            {
                if (tab2[p] > maxtab)
                {
                    maxtab = tab2[p];
                }
            }
            
        }
    }
    cout << "maxtab = " << maxtab << endl;

return 0;

}
