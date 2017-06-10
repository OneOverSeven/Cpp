// Loop through every number between 1 and 50
#include <iostream>
using namespace std;

int main()
{
int iii = 1;
while (iii <= 50)
	{
	cout << iii << " "; // print the number

	if (iii % 10 == 0) // if the loop variable is divisible by 10, print a newline
		{
			cout << endl;		
		}
			
     iii++; // increment the loop counter
	}
return 0;
}