/*
	"Author.h"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
	- Author Node class -
*/

#ifndef AUTHOR
#define AUTHOR
#include<iostream>

using namespace std;

// Class author
class Author {
	
	// Author first name
	string firstName;
	
	// Author last name
	string lastName;
	
	// Next author
	Author* next;
	
public:
	// Default Contructor
	Author();
	
	//Parametrized Consructor for intializing member variables
	Author(string firstName, string lastName);
	
	// Setters and Getters for the member variables
	void setFirstName(string firstName);
	void setLastName(string lastName);
	string getFirstName();
	string getLastName();
	void setNext(Author* next);
	Author* getNext();
};
#endif // !AUTHOR