#ifndef PROJECT_2_COURSES_H
#define PROJECT_2_COURSES_H

#include <string>
#include <vector>

using namespace std;

class Course
{
//Private course object 
private:

	string courseId;
	string courseName;
	vector<string>preReqs;

//Public methods

public:
	Course() = default;
	Course(string& id, string& name, vector<string>& prereqs);
	string getCourseId();
	string getCourseName();
	vector<string> getCoursePrereqs();
};

#endif //PROJECT_2_COURSES_H
