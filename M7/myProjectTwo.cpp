#include <iostream>
#include <cstring>

using namespace std;

// By creating a class for the program, we encapsulate essential program logic to hide as much information from the user as possible, through the use of private functions.
// This also helps keep the program more organized, and protects data from accidental modification.

class ClientManagement {

	public:

	// we keep the ProgramDriver public so that it can be accessed from the program's main function

	void ProgramDriver() {
		cout << "Created by: Justin Starr" << endl << endl;

		cout << "Welcome to our Investment Company." << endl;

		// variable validUser is initialized before its use.
		int validUser = 0;

		while (validUser != 1) {
			validUser = CheckUserPermissionAccess();
		}

		// the variable choice is initialized before its use.
		int choice = 0;

		while (choice != 3) {
			cout << "What would you like to do?" << endl;
			cout << "DISPLAY the client's list (enter 1)" << endl;
			cout << "CHANGE a client's choice (enter 2)" << endl;
			cout << "EXIT the program (enter 3)" << endl;

			// Before, there was no input validation for the variable chocie. This could lead to undefined or unexpected behavior.

			//cin >> choice;

			char test_number[4096];
			bool parsedCorrect = false;

			// validate input from user for the variable choice
			do {
				cout << "Select an option: ";
				cin >> test_number;

				// validate that the input taken from the user is an integer.
				// a false value indicates that the user did not enter a valid integer
				// a true value indicates that the user entered a valid integer and only an integer
				parsedCorrect = ParseInteger(test_number, &choice);
			}
			// before, the program did not ensure the user was entering a valid choice.
			while (parsedCorrect == false || (choice != 1 && choice != 2 && choice != 3));

			cout << "You chose " << choice << "." << endl;

			if (choice == 1) {
				DisplayInfo();
			}

			else if (choice == 2) {
				ChangeCustomerChoice();
			}
		}
	}

	private:

	// we keep our variables private so they cannot be modified outside of the ClientManagement class. This helps prevent accidental modification.
	string clients[5] = { "Bob Jones", "Sarah Davis", "Amy Friendly", "Johnny Smith", "Carol Spears" };
	int clientChoices[5] = { 1,2,1,2,1 };

	string username = "";

	// a function to determin whether the input given is an integer. This will be called any time we are validating integer input.
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

	void ChangeCustomerChoice() {

		//int clientNumber, serviceNumber; // Variables should be initialized before use.
		int clientNumber = 0, serviceNumber = 0;

		// before there was no input validation for the variables clientNumber or serviceNumber. This could lead to undefined or unexpected behavior.

		bool parsedCorrect = false;
		char test_number1[4096];// used to validate input before assigning clientNumber an integer value
		char test_number2[4096];// used to validate input before assigning serviceNumber an integer value

		do {
			// prompt the user for input
			cout << "Enter the number of the client that you wish to change.\n";
			//cin >> clientNumber;
			cin >> test_number1;

			// validate that the input taken from the user is an integer.
			// a false value indicates that the user did not enter a valid integer
			// a true value indicates that the user entered a valid integer and only an integer
			parsedCorrect = ParseInteger(test_number1, &clientNumber);

		}
		// before, the program did not check to ensure the user is selecting a valid client. This could lead to undefined or unexpected behavior because it could potentially access a memory location out-of-bounds of the size of clientChoices when assigning the new clientChoice
		while (parsedCorrect == false || (clientNumber != 1 && clientNumber != 2 && clientNumber != 3 && clientNumber != 4 && clientNumber != 5));

		parsedCorrect = false; // reset this variable for the next input validation loop.

		do {
			//prompt the user for input
			cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
			//in >> serviceNumber;
			cin >> test_number2;

			// validate that the input taken from the user is an integer.
			// a false value indicates that the user did not enter a valid integer
			// a true value indicates that the user entered a valid integer and only an integer
			parsedCorrect = ParseInteger(test_number2, &serviceNumber);
		}
		// before, the program did not check to ensure the user is entering a valid service number. While this was not directly a security vulnerability, we should ensure the program assigns values as expected.
		while (parsedCorrect == false || (serviceNumber != 1 && serviceNumber != 2));

		if (clientNumber == 1) {
			clientChoices[clientNumber - 1] = serviceNumber;
		}
		else if (clientNumber == 2) {
			clientChoices[clientNumber - 1] = serviceNumber;
		}
		else if (clientNumber == 3) {
			clientChoices[clientNumber - 1] = serviceNumber;
		}
		else if (clientNumber == 4) {
			clientChoices[clientNumber - 1] = serviceNumber;
		}
		else if (clientNumber == 5) {
			clientChoices[clientNumber - 1] = serviceNumber;
		}
	}

	// Since we never access memory locations inside this function that would be considered out-of-bounds, we have no security vulnerabilities within this function.
	void DisplayInfo() {
		cout << "Client's Name: " << clients[0] << endl;
		cout << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
		cout << "Selected Option " << clientChoices[0] << endl;

		cout << "Client's Name: " << clients[1] << endl;
		cout << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
		cout << "Selected Option " << clientChoices[1] << endl;

		cout << "Client's Name: " << clients[2] << endl;
		cout << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
		cout << "Selected Option " << clientChoices[2] << endl;

		cout << "Client's Name: " << clients[3] << endl;
		cout << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
		cout << "Selected Option " << clientChoices[3] << endl;

		cout << "Client's Name: " << clients[4] << endl;
		cout << "Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
		cout << "Selected Option " << clientChoices[4] << endl;
	}

	int CheckUserPermissionAccess() {

		// Passwords should never be hard coded into the source code. If the source code became exposed, anyone would be able to read the password.
		// This is an identified security vulnerability that will not be fixed for this project. However, one method for fixing this vulnerability would be to hash the user input and then validate the hash instead of having the password directly exposed in the source code.
		string password = "";
		string correctPassword = "123";

		do {
			cout << "Enter your username: ";
			cin >> username;
		}
		// This ensures the user cannot enter a value for username that would exceed its capacity, which would cause undefined or unexpected behavior.
		while (username.length() > 25);

		do {
			cout << "Enter your password: ";
			cin >> password;
		}
		// This ensures the user cannot enter a value for username that would exceed its capacity, which would cause undefined or unexpected behavior.
		while (password.length() > 25);


		if (password.compare(correctPassword) == 0) {
			return 1;
		}
		else {
			//cout << "Invalid Password." << endl;
			//cout << "Please try again." << endl;

			// we should have a more generic error message that does not explicitly say whether the username or password is incorrect.
			cout << "Invalid Username or Password." << endl;
			cout << "Please try again." << endl;
			return 2;
		}
	}
};

int main() {

	ClientManagement clientManagement;
	clientManagement.ProgramDriver();
	return 0;
}