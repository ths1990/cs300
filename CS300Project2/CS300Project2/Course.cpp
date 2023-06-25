#include "Course.h"

//Constructor for creating a Course object

/*
	@param id for CourseId
	@param name for courseName
	@param prereqs for list of preReqs
*/

Course::Course(string& id, string& name, vector<string>& prereqs) {
	this->courseId = id;
	this->courseName = name;
	this->preReqs = prereqs;
}

/*
	Get courseId
*/

std::string Course::getCourseId() {
	return this->courseId;
}

/*
	Get courseName
*/

std::string Course::getCourseName() {
	return this->courseName;
}

/*
	Get coursePrereqs
*/

std::vector<string> Course::getCoursePrereqs() {
	return this->preReqs;
}

