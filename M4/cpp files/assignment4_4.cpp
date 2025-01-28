#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    long long binaryNumber;
    int decimalNumber = 0;
    int i = 0;
    int remainder;

    cout << "Enter a binary number: \n";
    cin >> binaryNumber;

    while (binaryNumber != 0) {
        remainder = binaryNumber % 10;
        binaryNumber /= 10;
        // This is what I used in the second submission to be able to generate a binary file
        decimalNumber += remainder * (2 ^ i);
        // you could also use: (but it priduces an incorrect hexadecimal value in codio)
        // decimalNumber += remainder * (2 << i);
        // or, which is what i used in my first submission and this would not allow me to geneerate a binary file.
        // decimalNumber += remainder * pow(2, i);
        i++;
    }

    stringstream hexStream;
    hexStream << hex << decimalNumber;
    string hexOutput = hexStream.str();
    
    cout << "Equivalent hexadecimal value: " << hexOutput;

  return 0;
}