#include <iostream>

using namespace std;

int main()
{
    int i, j, l;

    cout << "Enter a number of rows\n";
    cin >> i;

    int k = i - 1;

    for (j = 1; j <= i; j++) {

        for (l = 1; l <= k; l++) {
            cout << " ";
        }
   
        for (l = 1; l <= ((j * 2) - 1); l++) {
            cout << "*";
        }
        cout << endl;
    }

    for (j = 1; j <= i; j++) {
        for (l = 1; l <= k; l++) {
            cout << " ";
        }
        for (l = 1; l <= (((i-j)*2)-1); l++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}