#include <iostream>
using namespace std;

const int SLEN = 30;

struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};


int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;

	while (cin.get() != '\n')
		continue;

	student * ptr_stu = new student[class_size];

	int entered = getinfo(ptr_stu, class_size);

	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}

	display3(ptr_stu, entered);

	delete [] ptr_stu;
	cout << "\n\nDone\n";
	return 0;
}

int getinfo(student pa[], int n)
{
	int i = 0, value = 0;

	for (i = 0; i < n; ++i)
	{
		cout << "\nStudent #" << i + 1 << "\nFullname: ";
		cin.getline(pa[i].fullname, SLEN);
		if (!pa[i].fullname[0])
		{
			break;
		}

		cout << "Hobby: ";
		cin >> pa[i].hobby;

		cout << "OOPLevel: ";
		cin >> pa[i].ooplevel;

		cin.get();
	}

	return i;
}

void display1(student st)
{
	cout << "\n\n---" << __func__;

	cout << "\nStudent " << st.fullname;
	cout << "\nHobby: " << st.hobby;
	cout << "\nOOPLevel: " << st.ooplevel;
}
void display2(const student * ps)
{
	cout << "\n\n---" << __func__;

	cout << "\nStudent " << ps->fullname;
	cout << "\nHobby: " << ps->hobby;
	cout << "\nOOPLevel: " << ps->ooplevel;
}
void display3(const student pa[], int n)
{
	cout << "\n\n---" << __func__;

	for (int i = 0; i < n; ++i)
	{
	cout << "\nStudent " << pa[i].fullname;
	cout << "\nHobby: " << pa[i].hobby;
	cout << "\nOOPLevel: " << pa[i].ooplevel << endl;
	}
}
