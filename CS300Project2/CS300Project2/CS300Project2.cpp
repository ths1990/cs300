#include <iostream>
#include <fstream>
#include <sstream>
#include<regex>
#include "CourseBST.h"


/*
	Logic to load course for .txt file separating values at each comma
*/
void loadCourses(const string& filePath, CourseBST* coursesBst) {
	cout << "Now loading file " << filePath << endl << endl;

	ifstream file(filePath);
	string currentRow;



	try {
		while (getline(file, currentRow)) {
			stringstream ss(currentRow);
			string word, id, name;
			vector<string> prereqs;
			int index = 0;
			
			while (!ss.eof()) {
				getline(ss, word, ',');
				word = regex_replace(word, regex(R"(\r\n|\r|\n)"), "");
				if (index == 0) {
					id = word;
				}
				else if (index == 1) {
					name = word;
				}
				else {
					prereqs.push_back(word);
				}

				index++;
			}

			Course course = Course(id, name, prereqs);

			coursesBst->Insert(course);
		}
	}
	catch (ifstream::failure& e) {
		cerr << e.what() << endl;
	}

	file.close();
}

/*
	Logic to print a course and its prerequisites (if prerequisties exist.
*/
void printCourse(Course course) {
	vector<string> coursePreReqs = course.getCoursePrereqs();
	string prereqs;
	
	//If course only has one prereq
	if (coursePreReqs.size() == 1) {
		prereqs = course.getCoursePrereqs()[0];
	}
	//If course has multiple prereqs
	else if (coursePreReqs.size() > 1) {
		//Iterate through prereq list
		for (int i = 0; i < coursePreReqs.size() - 1; i++)
		{
			//For user readability, add comma to end of prereq for duration of the loop
			prereqs += coursePreReqs[i] + ", ";
		}

		prereqs += coursePreReqs.back();
	}

	//No prereqs
	else {
		prereqs = "n/a";
	}

	cout << course.getCourseId() << ", "
		<< course.getCourseName() << endl;
	cout << "Prerequisites: " << prereqs << endl <<  endl;
}

/*
	Main method. 
	Prints main menu and prompts user to Load Course List, Display All Courses, Search and Display a Selected Course and Details, or Exit the Program

	The course list that is loaded is hard coded. Future iterations could allow user to select a course list to load. For the purposes of this exercise, we only have one list
	therefore we do not need to prompt the user to select a list to load. 

	Per the requirements, there is no need to delete courses or add line item courses. Though the functionality could be added later if desired.
*/
int main() {
	
	//Define BST to hold all courses
	CourseBST* coursesBst;
	coursesBst = new CourseBST();
	Course course;
	
	string inputFile, courseKey;

	//Predefined file
	inputFile = "CourseList.txt";

	cout << "Welcome to the ABCU Course Planner!" << endl << endl;
	
	int choice = 0;
	while (choice != 9) {
		cout << "Menu:" << endl;
		cout << "1.Load Courses" << endl;
		cout << "2. Display All Courses" << endl;
		cout << "3. Search Course and Display Info" << endl;
		cout << "9. Exit" << endl << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cout << endl;

		switch (choice) {

		case 1:

			loadCourses(inputFile, coursesBst);
			break;

		case 2:
			coursesBst->InOrder();
			cout << endl;
			break;

		case 3:
			cout << "Enter the Course ID for the class you would like to know more about: ";
			cin >> courseKey;
			course = coursesBst->Search(courseKey);

			if (!course.getCourseId().empty()) {
				printCourse(course);
			}

			else {
				cout << "Course ID " << courseKey << " not found." << endl;
			}
			break;

		case 9:
			cout << "Thank you for using the ABCU Course Planner. Have a nice day!" << endl;
			break;

		default:
			cout << "You selected " << choice << " which is an invalid selection. Try again." << endl;
			break;
		}

	}
}