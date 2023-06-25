#ifndef PROJECT_2_COURSEBST_H
#define PROJECT_2_COURSEBST_H

#include <string>
#include <vector>
#include "Course.h"



//Create Node Structure for Binary Search Tree

struct Node {
	Course course;
	Node* left;
	Node* right;

	//Default constructor

	Node() {
		//Defaults left and right nodes as null
		left = nullptr;
		right = nullptr;
	}

	//Initialize with newCourse

	Node(Course newCourse) :
		Node() {
		course = newCourse;
	}
};
class CourseBST
{
private:
	Node* root;
	void addNode(Node* node, Course course);
	void inOrder(Node* node);
	

public:
	CourseBST();
	void InOrder();
	void Insert(Course course);
	Course Search(string courseId);
};

#endif

