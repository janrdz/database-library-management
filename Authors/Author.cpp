/*
    "Author.cpp"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#include "Author.h"

// Implementation of the author node class

// Author class
Author::Author() {
	
	// First name of the author
	firstName = "";
	
	// Last name of the author
	lastName = "";
	next = NULL;
}

// Storing the author first and last name inside the variables 
Author::Author(string firstName, string lastName) {
	
	// Storing the first name of the author
	setFirstName(firstName);
	
	// Storing the last name of the author
	setLastName(lastName);
	next = NULL;
}

// Void function that sets author's first name
void Author::setFirstName(string firstName) {
	this->firstName = firstName;
}

// Void function that sets author's last name
void Author::setLastName(string lastName) {
	this->lastName = lastName;
}

// Getting the author first name, so we search a book, we can print his name
string Author::getFirstName() {
	return firstName;
}

// Getting the author last name, so we search a book, we can print his last name
string Author::getLastName() {
	return lastName;
}

// If there's more than one author, 
void Author::setNext(Author* next) {
	this->next = next;
}

// Getting the reamaining authors
Author* Author::getNext() {
	return this->next;
}
