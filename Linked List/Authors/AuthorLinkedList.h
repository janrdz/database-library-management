/*
    "AuthorLinkedList.h"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#ifndef AUTHORLINKEDLIST
#define AUTHORLINKEDLIST
#include "Author.h"

// Author Linked List class 

class AuthorLinkedList {
	Author* head;
	// Recursive function to remove all the elements from the list 
	void remove(Author* head);
	
public:
	// Default Constructor for intializing member variables as null
	AuthorLinkedList();

	// Insert the function
	void insert(string firstName, string lastName);
	
	// Printing the function
	void print();
	
	// An assignment operator overloading which will help us to do the deep copy 
	AuthorLinkedList& operator=(const AuthorLinkedList& rhs);
	
	// Remove list public method
	void removeList();
};
#endif // !AUTHORLINKEDLIST