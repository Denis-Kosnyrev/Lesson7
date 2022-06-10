// Lesson 7.cpp 

#include <iostream>
#include <fstream>

#include "MyLib.h"

using namespace std;



// Zadanie 1,5
inline void task5 ()
{
	const short size = 10;
	const float* arr = MyLib::createAndInitArr(size);

	if (arr != nullptr)
	{
		MyLib::printArr(arr, size);
			MyLib::printPositiveAndNegative(arr, size);

			delete[] arr;
	}
}

// Zadanie 2

#define IN_RANGE(x, y) ((x >= 0 && x < y) ? "true" : "false")

inline void task2()
{
	int num;
	cin >> num;
	cout << IN_RANGE(num, 10) << endl;

}

// Zadanie 3

#define ARR_SIZE 10

inline void task3()
{
	int* arr = new (nothrow) int[ARR_SIZE];

	if (arr != nullptr)
	{
		cout << "Enter " << ARR_SIZE << "numbers: " << endl;
		for (size_t i = 0; i < ARR_SIZE; i++)
		{
			cin >> arr[i];
		}

		MyLib::sortArr(arr, ARR_SIZE);
		MyLib::printArr(arr, ARR_SIZE);

		delete[] arr;
	}
}


// Zadanie 4

#pragma pack(push, 1)
struct Employee
{
	unsigned long long id = 0;
	char fName[255], lName[255];
	size_t age = 0;
	float salary = 0;
	short experience = 0;
};

#pragma pack(pop)

void printEmployee(const Employee* emp)
{
	if (emp != nullptr)
	{
		cout << "ID: " << emp->id << endl;
		cout << emp->lName << " " << emp->fName << ", " << emp->age << endl;
		cout << "Salary: $" << emp->salary << "month" << endl;
		cout << "Experience: " << emp->experience << "years " << endl;
		
		cout << "Size:" << sizeof(Employee) << "bytes" << endl;
	}
}

void saveEmployeeToFile(const string& FName, const Employee* emp)
{
	if (emp == nullptr)
		return;

	ofstream fout(FName);

	if (fout.is_open())
	{
		fout << "Employee:" << emp->id << "fName: " << emp->fName << "lName";
		fout << emp->lName << "age" << emp->age << "salary:" << emp->salary;
		fout << "experience: " << emp->experience << ";}," << endl;

		fout.close();
	}
	else {
		cout << "Can't open file" << endl;
	}
}

inline void task4()
{
	Employee* emp = new (nothrow) Employee;

	if (emp != nullptr)
	{
		emp->id = 1;
		strcpy_s(emp->fName, "Ivan");
		strcpy_s(emp->lName, "Ivanov");
		emp->age = 24;
		emp->salary = 100'000.00;
		emp->experience = 3;

		printEmployee(emp);

		saveEmployeeToFile("employee.txt", emp);

		delete emp;
	}
}