#include <iostream>;
#include <regex>;
#include "CourseBST.h"

//Constructor

CourseBST::CourseBST() {
	//set root to null
	root = nullptr;
}


//In Order traversal of BST

void CourseBST::InOrder() {
	//Call method for inOrder and pass root
	inOrder(root);
}

//Insert Course

void CourseBST::Insert(Course course) {
	if (root == nullptr) {
		root = new Node(course);
	}

	else
	{
		this->addNode(root, course);
	}
}



//Search a course

Course CourseBST::Search(std::string courseId) {

	//To allow for flexible user input, convert courseId to uppercase to match against filesource
	transform(courseId.begin(), courseId.end(), courseId.begin(), ::toupper);

	//Current node equal to root

	Node* current = root;

	//While the current node is not null
	while (current != nullptr)
	{
		//If node matches, return course
		if (current->course.getCourseId().compare(courseId) == 0) {
			return current->course;
		}

		//Traverse left if the course Id is less than thhe current node
		else if (courseId.compare(current->course.getCourseId()) < 0)
		{
			current = current->left;
		}
		//Else traverse right
		else {
			current = current->right;
		}
	}
	//Return an empty course if course not found
		Course course;
		return course;

	}
/*
	Add a course recursively to some node

	@param node - Current node in Tree
	@param course - Course to add
*/
void CourseBST::addNode(Node* node, Course course) {

	//If the node is smaller, add to left;
	if (node != nullptr && (node->course.getCourseId().compare(course.getCourseId()) > 0))
	{
		//If left is empty
		if (node->left == nullptr) {
			//Node becomes left
			node->left = new Node(course);
			return;
		}
		//Recurse down left node
		else {
			this->addNode(node->left, course);
		}
	}

	//Else if node is larger, add to right
	else if (node != nullptr && (node->course.getCourseId().compare(course.getCourseId()) < 0)) {
		//If right is empty
		if (node->right == nullptr) {
			//Node becomes right
			node->right = new Node(course);
			return;
		}
		//Recurse down right node
		else {
			this->addNode(node->right, course);
		}
	}
}

//Prints nodes in alpha-numeric order
void CourseBST::inOrder(Node* node) {
	if (node != nullptr) {
		inOrder(node->left);
		cout << "Course ID: " << node->course.getCourseId() << " | "
			<< node->course.getCourseName() << endl;
		inOrder(node->right);
	}
}