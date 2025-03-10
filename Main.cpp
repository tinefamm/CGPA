#include <iostream>

// Structure to represent the course's grade point (GP) and credits.
struct Data
{
	float GP;
	int credits;
};

// Function to calculate and display the CGPA.
void CGPA(Data* courses, int numCourse, int totalCredits)
{
	float CGPA = 0;
	for (int i = 0; i < numCourse; i++)
	{
		CGPA += courses[i].GP * courses[i].credits;
	}
	CGPA /= totalCredits;
	std::cout << "The student's CGPA is " << CGPA << "." << std::endl;
}

int main()
{
	// Ask the user for the number of courses.
	int numCourse;
	std::cout << "How many courses do you want to calculate?" << std::endl;
	std::cin >> numCourse;
	while (numCourse <= 1)
	{
		std::cout << "Please enter at least 2 courses!" << std::endl;
		std::cin >> numCourse;
	}

	// Dynamically allocate an array to store course data.
	Data* courses = new Data[numCourse];

	// Collect GP and credits for each course.
	float totalGP = 0;
	int totalCredits = 0;
	for (int i = 0; i < numCourse; i++)
	{
		std::cout << "Insert the GP and the credits of the course " << i + 1 << ":" << std::endl;
		std::cin >> courses[i].GP >> courses[i].credits;
		totalGP += courses[i].GP;
		totalCredits += courses[i].credits;
	}
	// Display total grade points and credits.
	std::cout << "The total number of grades point are " << totalGP << " and the number of credits are " << totalCredits << "." << std::endl;

	CGPA(courses, numCourse, totalCredits);

	std::cin.get();

	// Free dynamically allocated memory.
	delete[] courses;
}