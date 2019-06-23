#include <iostream>
#include <iomanip>
#include <string>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

//default constructor
//set head and tail to nullptr
LinkedList::LinkedList() {
	head = nullptr;
	tail = nullptr;
}

//destructor
//call the clear function
LinkedList::~LinkedList() {

	//initailize a node to head
	Node* temp = head;

	//iterate through the LinkedList and delete each node
	while(temp)
	{
		Node* tempNext = temp->next;
		delete temp;
		temp = tempNext;
	}
}

//copy constructor
LinkedList::LinkedList(const LinkedList& source) {

	//declare two nodes
	Node* n1;
    Node* n2;
    
    //if the source list is empty
    //set head and tail to nullptr
    if(source.head == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
        return;
    }
    //else make a new Node and copy the head
    else
    {
        this->head = new Node();
        this->head->data = source.head->data;
        
        n1 = this->head;
        n2 = source.head->next;
    }
    
    //iterate through the source
    //make a new node and copy the data from it's counterpart in source
    while(n2)
    {
        n1->next = new Node();
        n1 = n1->next;
        n1->data = n2->data;
        
        if(n2->next == nullptr)
        {
            n1->next = nullptr;
            this->tail = n1;
        }
        n2 = n2->next;
    }
}

//copy assignment
LinkedList& LinkedList::operator=(const LinkedList& source) {
	
	//declare two nodes
	Node* n1;
    Node* n2;
    
    //if the source list is empty
    //set head and tail to nullptr
    if(source.head == nullptr)
    {
        this->head = nullptr;
        this->tail = nullptr;
        return *this;
    }
    //else make a new Node and copy the head
    else
    {
        this->head = new Node();
        this->head->data = source.head->data;
        
        n1 = this->head;
        n2 = source.head->next;
    }
    
    //iterate through the source
    //make a new node and copy the data from it's counterpart in source
    while(n2)
    {
        n1->next = new Node();
        n1 = n1->next;
        n1->data = n2->data;
        
        if(n2->next == nullptr)
        {
            n1->next = nullptr;
            this->tail = n1;
        }
        n2 = n2->next;
    }

    return *this;
}

//insert the into the correct palce in the list
void LinkedList::insert(string location, int year, int month, double temperature) {

	//Make a new Node of the given arguments
	Node* nodeToInsert = new Node(location, year, month, temperature);

	//if the list is empty
	//then make the nodeToInsrt the head
	if(head == nullptr)
	{
		nodeToInsert->next = nullptr;
		head = nodeToInsert;
		tail = nodeToInsert;
	}

	//if nodeToInsert is less than head
	//assign the next pointer to the current head
	//then replace the head
	else if(nodeToInsert->operator<(*head))
	{
		nodeToInsert->next = head;
		head = nodeToInsert;
	}

	else
	{
		//boolean to check if the node is inserted or not
		bool inserted = false;
		Node* temp = head;

		//iterate through the LinkedList
		while(temp->next)
		{
			//if nodeToInsert is less than temp->next
			//inset it in between temp and temp->next
			//set the boolean to true
			//break the loop
			if(nodeToInsert->operator<(*temp->next))
			{
				nodeToInsert->next = temp->next;
				temp->next = nodeToInsert;
				inserted = true;
				break;
			}

			temp = temp->next;
		}

		//if boolean is still false
		//means that nodeToInsert should be added to back of the list
		//at this moment temp is the last node in the list
		//thus set temp->next to nodeToInsert
		//change the tail
		if(!inserted)
		{
			temp->next = nodeToInsert;
			nodeToInsert->next = nullptr;
			tail = nodeToInsert;
		}
	}
}

//helper funstion for the destructor
void LinkedList::clear() {
	
	//initailize a node to head
	Node* temp = head;

	//iterate through the LinkedList and delete each node
	while(temp)
	{
		Node* tempNext = temp->next;
		delete temp;
		temp = tempNext;
	}

	delete head;
}

//get the head of the LinkedList
Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

//print a LinkedList
string LinkedList::print() const {
	string outputString = "";
	stringstream ss;
	
	//if the list is empth don't do anything just return the empty string
	if(head == nullptr)
		;
	else
	{
		Node* temp = head;

		//iterate through the loop
		while(temp)
		{
			//print each node onto stringstream
			ss << temp->data.id << " " << temp->data.year <<  " " << temp->data.month << " " << temp->data.temperature << "\n" ;

			temp = temp->next;
		}

		//convert the stringstream to string and append it to outputString
		outputString = outputString + ss.str();
	}

	return outputString;
}

//overloading operator
ostream& operator<<(ostream& os, const LinkedList& ll) {
	//call the print function
	os << ll.print();
	return os;
}
