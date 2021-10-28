/*
    "DoublyCircularLinkedList.cpp"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#include "DoublyCircularLinkedList.h"

// Default Constructor
DoublyCircularLinkedList::DoublyCircularLinkedList() {
	head = NULL;
}

// Parameterized Constructor
void DoublyCircularLinkedList::insert(string title, string plot, AuthorLinkedList authors, string editor, int releaseYear) {
	Book* NewNode = new Book(title, plot, authors, editor, releaseYear);
	
	// If list is empty direct add the node in list
	if (head == NULL) {								
		head = NewNode;
		
		// pointing next to the head as it is a cirular list
		head->setNext(NewNode);						
	}
	else {
		Book* temp = head;
		Book* prev = NULL;
		
		// Finding the correct possition for current node so that our list remains sorted by book's title
		while (temp->getNext() != head && temp->getTitle()<title) {				
			prev = temp;
			temp = temp->getNext();
		}
		
		// If we got a position whose current position has greater string the our inserting node
		if (temp->getTitle() > title) {
			
			// If it is head of the list
			if (prev == NULL) {						
				NewNode->setNext(head);				
				temp = head;
				
				// Finding the last node
				while (temp->getNext() != head) {	
					temp = temp->getNext();
				}
				
				// Update the last nodes next because we are updating head of the list 
				temp->setNext(NewNode);				
				head = NewNode;					
			}
			
			// If it is not in the head
			else {									
				prev->getNext()->setPrev(NewNode);
				NewNode->setPrev(prev);
				NewNode->setNext(prev->getNext());
				prev->setNext(NewNode);
			}
		}
		else {
			NewNode->setNext(head);
			temp->setNext(NewNode);
			NewNode->setPrev(temp);
		}
	}
}


// Removing the method
void DoublyCircularLinkedList::removeList() {
	if (head != NULL) {
		remove(head);
		head->getAuthors().removeList();
		delete head;
		head = NULL;
	}
}

// Destructor
DoublyCircularLinkedList::~DoublyCircularLinkedList() {
	removeList();
}


void DoublyCircularLinkedList::deleteABook(string title) {
	Book* temp = head,*temp2;
	if (head != NULL) {
		
		// If the book is the head of the list
		if (temp->getTitle() == title) {		
			temp2 = head;
			
			// Finding the last element 
			while (temp2->getNext() != head)	
				temp2 = temp2->getNext();
			if (temp2 == head) {
				
				// If there exists only one elements
				delete head;
				head = NULL;
			}
			
			// If there exists more than one element
			else {
				// Pointing the last element's next to the new head as it is a circular list
				temp2->setNext(head->getNext());
				
				// Updating the head
				head = head->getNext();					
				head->setPrev(NULL);					
				temp->setNext(NULL);
				
				// Deleting the node 
				delete temp;						
			}
		}
		else {
			
			// Finding the positiion of the book
			while (temp->getNext() != head && temp->getNext()->getTitle() != title)		
				temp = temp->getNext();
			
			// If book exists in list
			if (temp->getNext()->getTitle() == title) {					
				temp2 = temp->getNext();
				
				// Removing the book from the existing position
				temp->setNext(temp->getNext()->getNext());
				
				// If the book is not at the last position
				if (temp->getNext() != head)
					
					// Then update the previous pointer of nextNode
					temp->getNext()->setPrev(temp);						
				temp2->setPrev(NULL);									
				temp2->setNext(NULL);
				
				// Delete the node
				delete temp2;											
			}
		}
	}
}