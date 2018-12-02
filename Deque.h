#ifndef DEQUE_H
#define DEQUE_H

#include <exception>;
#include <iostream>

using namespace std;

template <class Type>
struct node { //Stores all the node's data as well as pointers to the next and previous node.
	Type data;  
	node<Type> *next;
	node<Type> *prev;
};

template <class Type>
class Deque
{
private: //contains the linked list's  head and tail, as well as a running count of the number of elements in the deque.
	node<Type> *head;
	node<Type> *tail; 
	int count;
    
public:
	Deque() { //constructor
		head = nullptr; //initialize head and tail to nullptr, and count to 0
		tail = nullptr;
		count = 0;

	}
    
	~Deque() {
		cout << "The deque is being destructed."; //destructor for the deque
	}
    
	bool isEmpty() {
		if (count == 0) { //if count is 0, then the deque has to be empty
			return true;
		}
		return false; //if it's not 0, then it's not empty
	}
    
	int size() {
		return count; //simply returns the total number  of elements
	}
    
	Type first() {
		return head->data; //returns the first element in the  deque
	}
    
	Type last() {
		return tail->data; //returns the  last element in the deque
	}
    
	void insertFirst(Type o) {
		node<Type>* newNode = new node<Type>; //instantiates a node newNode to contain the data to be inserted
		newNode->data = o; //sets the data equal to o
		if (count == 0) { //case when inserting data into an empty linked list
			newNode->next = nullptr; //since the inserted node will be the  only one in the list, the next and previous nodes have to be nullptr
			newNode->prev = nullptr;
			head = newNode; //the new node will also be both the head  and tail of the list since it is the only one in the list
			tail = newNode; 
			count++; //increase the count.
		}
		else {
			newNode->next = head; //set the new node's next equal to the list's current head
			newNode->prev = nullptr; //set the new node's previous equal to nullptr (since nothing's in its place)
			head = newNode; //replace the head with the  new node
			count++;  //increase the count.
		}
	}
    
	void insertLast(Type o) {
		node<Type>* newNode = new node<Type>; //instantiates a node newNode to contain the data to be inserted
		newNode->data = o;  //sets the data equal to o
		if (count == 0) { //case when inserting data into an empty linked list
			newNode->next = nullptr; //since the inserted node will be the  only one in the list, the next and previous nodes have to be nullptr
			newNode->prev = nullptr;
			head = newNode; //the new node will also be both the head  and tail of the list since it is the only one in the list
			tail = newNode;
			count++; //increase the count.
		}
		else {
			newNode->next = nullptr; //set the new node's next equal to nullptr
			newNode->prev = tail; //set the new node's prev equal to the list's current tail
			tail = newNode; //set the tail equal to the new node and increment
			count++;
		}
	}
    
	Type removeFirst() {
		if (count == 0) { //noting happens when the deque is empty
			cout << "Empty stack.";
			return 0;
		}
		else if (count == 1) {
			node<Type>* temp = head; //removes the  only element in the list and turns the remaining list into an empty one.
			Type tempVar = temp->data; 
			head = nullptr;
			tail = nullptr;
			delete temp;
			count--;
			return tempVar;

		}
		else {
			node<Type>* temp = head; //stores the data in the head into a temp 
			Type tempVar = temp->data; //stores that into a type node.
			head = head->next; //moves the head
			delete temp; //deletes the old head
			count--; //decreases the count
			return tempVar; //returns the removed node
		}
	}
    
	Type removeLast() { //same process as removeFirst()
		if (count == 0) {
			cout << "Empty stack.";
			return 0;
		}
		else if (count == 1) {
			node<Type>* temp = tail;
			Type tempVar = temp->data;
			head = nullptr;
			tail = nullptr;
			delete temp;
			count--;
			return tempVar;

		}
		else {
			node<Type>* temp = tail;
			Type tempVar = temp->data;
			tail = tail->prev;
			delete temp;
			count--;
			return tempVar;
		}
	}
		
	
};

#endif
