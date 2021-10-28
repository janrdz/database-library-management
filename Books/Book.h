/*
    "Book.h"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#ifndef BOOK
#define BOOK
#include<iostream>
#include"AuthorLinkedList.h"

using namespace std;

// Book Node class 
class Book {
	// Attributes of Book class 
	string title;
	string plot;
	AuthorLinkedList authors;
	string editor;
	int releaseYear;
	Book* next;
	Book* prev;
public:
	// Default Constructor for intializing parameters as null
	Book();
	// Parametrized Constructor for intializing member varibles
	Book(string title, string plot, AuthorLinkedList authors, string editor, int releaseYear);
	// Setters and getter for member variables
	void setTitle(string title);
	void setPlot(string plot);
	void setAuthors(AuthorLinkedList authors);
	void setEditor(string editor);
	void setReleaseYear(int year);
	void setNext(Book* next);
	void setPrev(Book* prev);
	string getTitle();
	string getPlot();
	AuthorLinkedList getAuthors();
	string getEditor();
	int getReleaseYear();
	Book* getNext();
	Book* getPrev();
	// Print function which will print all information of book 
	void print();
	// Print method for book which will only print the title, release year and editor of the book
	void printTitleYearEditor();
};
#endif // !BOOK
