#include <iostream>
#include <string>
#include <algorithm>

struct NameAndGrade 
{
	std::string studentName;
	int grade;
};

void sortArray(NameAndGrade *nameAndGrade, int numStudents)
{
	for (int swappedValue = 0; swappedValue < numStudents; ++swappedValue)
	{
		int iteratedFromValue = swappedValue;

		for (int insideArray = iteratedFromValue + 1; insideArray < numStudents; ++insideArray)
		{
			if (nameAndGrade[insideArray].grade > nameAndGrade[swappedValue].grade)
			{
				iteratedFromValue = insideArray;
			}
		}
		std::swap(nameAndGrade[swappedValue], nameAndGrade[iteratedFromValue]);
	}
}

int main()
{
	std::cout << "How many students are there: ";
	int numStudents;
	do
	{
		std::cin >> numStudents;
	} while (numStudents <= 0);

	NameAndGrade *nameAndGrade = new NameAndGrade[numStudents];

	for (int index = 0; index < numStudents; ++index)
	{
		std::cout << "Enter a name for student #" << index + 1 << "\n";
		std::cin >> nameAndGrade[index].studentName;
		
		std::cout << "Enter a grade for student #" << index + 1 << "\n";
		std::cin >> nameAndGrade[index].grade;
	}

	sortArray(nameAndGrade, numStudents);

	for (int i = 0; i < numStudents; ++i)
	{
		std::cout << "\n" <<  nameAndGrade[i].studentName << " had a grade of " << nameAndGrade[i].grade;
	}

	std::cin.ignore();
	std::cin.get();

	return 0;
}