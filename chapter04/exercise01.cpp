#include <iostream>
using namespace std;

const int kBufferSize = 100 + 1;

int main()
{
	char firstName[kBufferSize] = "";
	char lastName[kBufferSize] = "";
	char letterGrade = '\0';
	int age = 0;

	cout << "What is your first name? ";
	cin.getline(firstName, kBufferSize);
	cout << "What is your last name? ";
	cin >> lastName;
	cout << "What letter grade do you deserve? ";
	cin >> letterGrade;
	cout << "What is your age? ";
	cin >> age;

	cout << "Name: " << lastName << ", " << firstName << endl;
	cout << "Grade: " << char(letterGrade + 1) << endl;
	cout << "Age: " << age;

	cin.get();
	cin.get();
	return 0;
}
