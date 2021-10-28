/*
    "DoublyCircularLinkedList.h"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#ifndef DOUBLYCIRCULARLINKEDLIST
#define DOUBLYCIRCULARLINKEDLIST

#include"Book.h"

// Doubly Circular Linked list for Book 

class DoublyCircularLinkedList {
	// Head of the LinkedList
	Book* head;
	
	// Private functions for removing all elements from list
	void remove(Book* head);
	void removeList();
public:
	// Default Constructor
	DoublyCircularLinkedList();
	
	// Insert function
	void insert(string title, string plot, AuthorLinkedList authors, string editor, int releaseYear);
	
	// Search function which will take book title as parameter and return the address of that node
	Book* search(string title);
	
	// Print function 
	void print();
	
	// Function for deleting a book from list
	void deleteABook(string title);
	
	// Destructor 
	~DoublyCircularLinkedList();
};
#endif // !DOUBLYCIRCULARLINKEDLIST
