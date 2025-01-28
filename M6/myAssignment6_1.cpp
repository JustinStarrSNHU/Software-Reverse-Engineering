// The following commented code contains the program as it was written before any security vulnerabilities are fixed
// I have added comments throughout this section identifying security vulnerabilities.

/*
#include <iostream>

using namespace std;

void DisplayMenu() {
    cout << "----------------";
    cout << "- 1)Add -";
    cout << "- 2)Subtract -";
    cout << "- 3)Multiply -";
    cout << "- 4)Exit -";
    cout << "----------------";
}

int main()
{
    int choice = 0;

    while (choice != 5) {

        // In the assembly code, the function DisplayMenu is never called. It displays the menu strings here first.
        // Also, the code is intending for us to divide, not multiply, therefore, this should be fixed.

        cout << "----------------";
        cout << "- 1)Add -";
        cout << "- 2)Subtract -";
        cout << "- 3)Multiply -";
        cout << "- 4)Exit -";
        cout << "----------------";

        // the variable choice is taken in from input, and some checks are done, but not all checks, which could lead to a vulnerability where the loop is
        // never exited because the user expects the program to exit by selecting option 4, however, option 4 is never checked, and the program will only
        // terminate if the user enters the value 5. Also, input validation should be applied to the variable choice. A user could enter a value larger than
        // the variables numeric limits, which could cause a buffer overflow.

        cin >> choice;

        if (choice == 1) {
            // variables should always be declared and initialized right before their use. Here we see they are declared, but never initialized.
            int num1, num2;

            // use of un-initialized variables, we should ask the user to enter two numbers to add together. Not doing so could lead to undefined or unexpected behavior.
            // incorrect operation, this should be changed to addition
            // There is no input validation. If the user enters a value that is not within the numerical limits of an integer, a buffer overflow will occur. This could lead to other security issues, for example, a Denial-of-Service.
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
        }

        if (choice == 2) {
            // variables should always be declared and initialized right before their use. Here we see they are declared, but never initialized.
            int num1, num2;

            // use of un-initialized variables, we should ask the user to enter two numbers to subtract. Not doing so could lead to undefined or unexpected behavior.
            // incorrect operation, this should be changed to subtraction
            // There is no input validation. If the user enters a value that is not within the numerical limits of an integer, a buffer overflow will occur. This could lead to other security issues, for example, a Denial-of-Service.
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
        }

        if (choice == 3) {
            // variables should always be declared and initialized right before their use. Here we see they are declared, but never initialized.
            double num1, num2;

            // use of uninitialized variables, we should ask the user to enter two numbers to divide by. Not doing so could lead to undefined or unexpected behavior.
            // There is no input validation. If the user enters a value that is not within the numerical limits of an integer, a buffer overflow will occur. This could lead to other security issues, for example, a Denial-of-Service.
            // Also, there is no input validation to ensure the second number is not zero, since a number cannot be divided by zero.

            cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
        }
    }
}
*/

// The security methods applied include the following: encapsulation, prevention of buffer overflow, and initialization of variables.
// It also ensures the menu is being displayed properly to the user, that the functions are performing the correct operations, and that when dividing, a user cannot try to divide by zero.
// The private function ParseInteger was also created to validate user input and it ensures that only valid integers are given in all cases.

// The following code is how the program should be written with vulnerabilities handled.

#include <iostream>
#include <cstring>

using namespace std;

// By creating a class for the program, we encapsulate essential program logic to hide as much information from the user as possible, through the use of private functions.
// This also helps keep the program more organized, and protects data from accidental modification.
class SimpleCalculator {

    // We can keep the DisplayMenu function public
public:

    void DisplayMenu() {

        // formatted the output and changed Multiply to Divide
        cout << "----------------\n";
        cout << "-  1)Add       -\n";
        cout << "-  2)Subtract  -\n";
        cout << "-  3)Divide    -\n";
        cout << "-  4)Exit      -\n";
        cout << "----------------\n\n";
        cout << "Please select an option: ";
    }

    // We keep the program driver public so that it can be accessed from the main.  This ensured the program driver can access private functions, but not the main function.
    void RunProgramDriver() {

        int choice = 0;

        while (choice != 4) {

            // Calls the function to display the menu from the function DisplayMenu as intended.
            DisplayMenu();

            // read input and validate to ensure the value entered is a valid integer
            // This ensures no buffer overflow or unexpected behavior will occur.

            bool parsed_correct = false;

            char test_number[4096]; // used for validating the input given by the user to ensure it is an integer value
            cin >> test_number;
            
            parsed_correct = ParseInteger(test_number, &choice); // if the passed in test_number variable returns true, choice is assigned the integer value created from the ParseInteger function
                                                                 // otherwise, the value of choice remains 0 and the loop will iterate again, with the default case's output being displayed to the user
   
            // handles all possible cases
            switch (choice) {
            case 1:
                AddNumbers();
                break; // ensures no other functions are called before returning to the main menu
            case 2:
                SubtractNumbers();
                break; // ensures no other functions are called before returning to the main menu
            case 3:
                DivideNumbers();
                break; // ensures no other functions are called before returning to the main menu
            case 4:
                break; // breaks and then the loop will exit and the program will end. this also ensures the default message will not be output to the user.
            default:
                cout << "Invalid Selection." << endl;
            }
        }
    }

    // any function here cannot be accessed outside of the SimpleCalcualtor class, keeping information hidden from users, and ensuring it cannot be modified from outside the class.
private:

    // a function to determin whether the input given is an integer.
    // This is the function that will be used during all input validation.
    // we keep this function private because we do not want it accessed outside of this class
    bool ParseInteger(char* string, int* integer) {
        int i = 0;

        while (isspace(string[i])) i++; // allow white spaces

        int length = strlen(string);

        if (length == i) return false; // nothing was entered, therefore return false.

        char integer_buffer[4096]; // character buffer that will be converted to an integer if an actual integer was given into input
        int integer_chars = 0;

        if (string[i] == '-') { // checks if the first character is a negative sign
            integer_buffer[integer_chars] = '-'; // adds the negative sign to the character buffer
            integer_chars++;
            i++;

            if (!isdigit(string[i])) return false; // if the next character, at this point, is not a digit, the input given was not a valid integer. we return false
        }

        while (i < length && !isspace(string[i])) { // iterate over the string and determind if the next characters are digits
            if (!isdigit(string[i])) return false; // if the next character is not a digit, return false.
            integer_buffer[integer_chars] = string[i];
            integer_chars++;
            i++;
        }

        integer_buffer[integer_chars] = '\0'; // adds a null terminator to integer buffer, our character array that will be converted to an integer.

        while (isspace(string[i])) i++; // continue looping through any trailing whitespace

        if (string[i] != '\0') return false; // in case we have not reached the null terminator in the passed in string, we return false because the string is not properly formatted.

        *integer = atoi(integer_buffer); // convert the character buffer to an integer value.

        return true;
    }

    void AddNumbers() {
        int num1 = 0, num2 = 0; // variables should always be declared and initialized right before their use.

        // read input and validate to ensure the value entered is a valid integer
        // This ensures no buffer overflow or unexpected behavior will occur.

        bool parsed_correct = false;
        char test_number1[4096]; // used to validate input before assigning num1 an integer value. 
        char test_number2[4096]; // used to validate input before assigning num2 an integer value.

        do {

            // prompt the user for input
            cout << "Enter the first number: ";
            cin >> test_number1;

            // validate the input taken from the user is an integer
            // a false value indicates that the user did not enter a valid integer
            // a true value indicates that the user entered a valid integer and only an integer, and num1 is assigned this integer value
            parsed_correct = ParseInteger(test_number1, &num1);

        } while (parsed_correct == false); // continue checking until the user has entered a valid integer

        parsed_correct = false; // reset this to false for input validation of second number

        // repeats this process for the second number, ensuring the user only inputs a valid integer, and num2 is assigned this integer value
        do {
            cout << "Enter the second number: ";
            cin >> test_number2;
            parsed_correct = ParseInteger(test_number2, &num2);

        } while (parsed_correct == false);

        cout << num1 << " + " << num2 << " = " << num1 + num2 << endl; // outputs the corrected operation
    }

    void SubtractNumbers() {
        int num1 = 0, num2 = 0; // variables should always be declared and initialized right before their use.

        // read input and validate to ensure the value entered is a valid integer
        // This ensures no buffer overflow or unexpected behavior will occur.

        bool parsed_correct = false;
        char test_number1[4096]; // used to validate input before assigning num1 an integer value. 
        char test_number2[4096]; // used to validate input before assigning num2 an integer value.

        do {

            // prompt the user for input
            cout << "Enter the first number: ";
            cin >> test_number1;

            // validate the input taken from the user is an integer
            // a false value indicates that the user did not enter a valid integer
            // a true value indicates that the user entered a valid integer and only an integer and num1 is assigned this integer value
            parsed_correct = ParseInteger(test_number1, &num1);

        } while (parsed_correct == false); // continue checking until the user has entered a valid integer

        parsed_correct = false;

        // repeats this process for the second number, ensuring the user only inputs a valid integer, and num2 is assigned this integer value
        do {
            cout << "Enter the second number: ";
            cin >> test_number2;
            parsed_correct = ParseInteger(test_number2, &num2);

        } while (parsed_correct == false);

        cout << num1 << " - " << num2 << " = " << num1 - num2 << endl; // outputs the corrected operation
    }

    void DivideNumbers() {
        int num1 = 0, num2 = 0; // variables should always be declared and initialized right before their use.

        // read input and validate to ensure the value entered is a valid integer
        // This ensures no buffer overflow or unexpected behavior will occur.

        bool parsed_correct = false;
        char test_number1[4096]; // used to validate input before assigning num1 an integer value. 
        char test_number2[4096]; // used to validate input before assigning num2 an integer value.

        do {

            // prompt the user for input
            cout << "Enter the first number: ";
            cin >> test_number1;

            // validate the input taken from the user is an integer
            // a false value indicates that the user did not enter a valid integer
            // a true value indicates that the user entered a valid integer and only an integer and num1 is assigned this integer value
            parsed_correct = ParseInteger(test_number1, &num1);

        } while (parsed_correct == false); // continue checking until the user has entered a valid integer

        // repeats this process for the second number, ensuring the user only inputs a valid integer and that the second number is not zero becasue any number cannot be divided by zero,
        // and num2 is assigned this integer value
        do {
            cout << "Enter the second number: ";
            cin >> test_number2;
            parsed_correct = ParseInteger(test_number2, &num2);

        } while (parsed_correct == false || num2 == 0);

        cout << num1 << " / " << num2 << " = " << static_cast<double>(num1) / num2 << endl; // displays the output to the user and converts the resulting value of the operation to double-precision 
    }
};

int main() {
    SimpleCalculator simpleCalculator; // instantiation of a SimpleCalculator object
    simpleCalculator.RunProgramDriver(); // calls the program driver
    return 0; // returns 0 when user chooses to exit the program
}