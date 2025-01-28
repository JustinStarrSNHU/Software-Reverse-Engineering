#include <iostream>

using namespace std;

int main()
{
  double pi = 3.14;
  double radius;

  cout << "Enter radius: ";
  cin >> radius;

  double volume = (4.0 / 3.0) * pi * (radius * radius * radius);

  cout << "The volume is: " << volume;

  return 0;
}