#include "std_lib_facilities.h"
int main()
{
          cout << "Please enter your first name and age\n";
          string first_name = "?!?";          // string variable
          int age = 666;
		  int var1= 777;
		  int var2;
		  int var3;
		  int var4;
		  cout << "var4 = " << var4 << ".\n";
		  var4>>var1;
		  cout << "var4 = " << var4 << ".\n";
		  cout << "var1 = " << var1 << ".\n";
		  var2<<var1;
		  cout << "var1 = " << var1 << ".\n";
		  var3>>var1;
		  cout << "var1 = " << var1 << ".\n";
		  cout << "var2 = " << var2 << ".\n";
		  cout << "var3 = " << var3 << ".\n";
          cout << "var4 = " << var4 << ".\n";
          cout << "Please enter a floating-point value: ";
          double n;
          cin >> n;
          cout << "n == " << n
                    << "\nn+1 == " << n+1
                    << "\nthree times n == " << 3*n
                    << "\ntwice n == " << n+n
                    << "\nn squared == " << n*n
                    << "\nhalf of n == " << n/2
                    << "\nsquare root of n == " << sqrt(n)
                    << "\n";  // another name for newline (“end of line”) in output
          return 0;
}
