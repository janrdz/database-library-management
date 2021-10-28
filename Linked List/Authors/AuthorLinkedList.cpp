/*
    "AuthorLinkedList.cpp"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#include "AuthorLinkedList.h"

// Implemantation of author linked list which will store the author name ordered by last name

AuthorLinkedList::AuthorLinkedList() {
	head = NULL;
}

// Insering the function 
void AuthorLinkedList::insert(string firstName, string lastName) {
	
	// If the list is empty, we're going to add directly the node onto the list
	if (head == NULL) {														
		head = new Author(firstName, lastName);
	}
	
	// If there exists some elements in list
	else {
		// New node for the authors
		Author* newNode = new Author(firstName, lastName);
		
		// False flag
		bool inserted = false;
		Author* temp = head;
		if (lastName < head->getLastName()) {
			newNode->setNext(head);
			head = newNode;
			inserted = true;
		}
		else {
			// Finding the position for node by comparing the last names
			while (temp->getNext() != NULL && (!inserted) && temp->getNext()->getLastName() < lastName) {	
				temp = temp->getNext();
			}
			
			// Correcting the position of the node
			newNode->setNext(temp->getNext());			
			temp->setNext(newNode);
		}
	}
}

// Printing authors list
void AuthorLinkedList::print() {
	cout << "Authors : "<<endl;
	Author* temp = head;
	while (temp != NULL) {
		cout << "\t\t"<<temp->getFirstName() << ' ';
		cout << temp->getLastName() << endl;
		temp = temp->getNext();
	}
	cout << endl;
}

// An assignment operator
AuthorLinkedList& AuthorLinkedList::operator=(const AuthorLinkedList& rhs) {
	
	// Comparing self assignment
	if (this != &rhs) {
		
		// Removing existing list
		removeList();							
		Author* temp = rhs.head;				
		while (temp != NULL) {
			
			// Inserting new elements 
			insert(temp->getFirstName(), temp->getLastName());		
			temp = temp->getNext();
		}
	}
	return *this;
}
