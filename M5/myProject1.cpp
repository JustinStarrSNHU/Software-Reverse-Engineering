#include <iostream>

using namespace std;

string clients[] = { "Bob Jones", "Sarah Davis", "Amy Friendly", "Johnny Smith", "Carol Spears" };
int clientChoices[] = { 1,2,1,2,1 };

string username = "";

void ChangeCustomerChoice() {

	int clientNumber, serviceNumber;

	cout << "Enter the number of the client that you wish to change.\n";
	cin >> clientNumber;

	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
	cin >> serviceNumber;

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

	string password = ""; 
	string correctPassword = "123"; 

	cout << "Enter your username: ";
	cin >> username; 

	cout << "Enter your password: ";
	cin >> password; 

	if (password.compare(correctPassword) == 0) {
		return 1;
	}
	else {
		cout << "Invalid Password." << endl;
		cout << "Please try again." << endl;
		return 2;
	}
}

int main() {

	int validUser = 0;

	cout << "Created by: Justin Starr" << endl << endl;

	cout << "Welcome to our Investment Company." << endl;

	while (validUser != 1) {
		validUser = CheckUserPermissionAccess();
	}

	int choice = 0;

	while (choice != 3) {
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client's list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl;
		cout << "EXIT the program (enter 3)" << endl;

		cin >> choice;

		cout << "You chose " << choice << "." << endl;

		if (choice == 1) {
			DisplayInfo();
		}

		else if (choice == 2) {
			ChangeCustomerChoice();
		}
	}

	return 0;
}