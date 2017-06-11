#include "../std_lib_facilities.h"
int main()
{
double d = 0;
while (cin >> d)    // repeat the statements below
{                   // as long as we type in numbers
    int i=d;        // squeezing a double into an int
    char c=i;       // squeezing an int into a char
    int i2 = c;     //get the integer value of the character
    cout << "d == " << d << "\ni== " << i << "\ni2 == " << i2 << ", char(" << c << ")\n";
}
        return 0;
}

