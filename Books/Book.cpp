/*
    "Book.cpp"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#include "Book.h"
#include<iostream>

using namespace std;

// Default Constructor
Book::Book() {
	
	// Title of the book
	title = "";
	
	// Plot of the book
	plot = "";
	
	// Editor of the book
	editor = "";
	
	// Preventing the 1969 bug
	// More info here: https://www.mentalfloss.com/article/26316/why-does-my-gadget-say-its-december-31-1969
	releaseYear = 1990;
}

// Parametrized Constructor
Book::Book(string title, string plot, AuthorLinkedList authors , string editor, int releaseYear ) {
	this->title = title;
	this->plot = plot;
	this->authors = authors;
	this->editor = editor;
	this->releaseYear = releaseYear;
}

// Setters and Getters
void Book::setTitle(string title) {
	this->title = title;
}
void Book::setPlot(string plot) {
	this->plot = plot;
}
void Book::setAuthors(AuthorLinkedList authors) {
	this->authors = authors;
}
void Book::setEditor(string editor) {
	this->editor = editor;
}
void Book::setReleaseYear(int year) {
	this->releaseYear = year;
}
void Book::setNext(Book* next) {
	this->next = next;
}
void Book::setPrev(Book* prev) {
	this->prev = prev;
}
string Book::getTitle() {
	return title;
}
string Book::getPlot() {
	return plot;
}
AuthorLinkedList Book::getAuthors() {
	return authors;
}
string Book::getEditor() {
	return editor;
}
int Book::getReleaseYear() {
	return releaseYear;
}
Book* Book::getNext() {
	return next;
}
Book* Book::getPrev() {
	return prev;
}

// Printing function of Book which will print all the information of book
void Book::print() {

	cout << "\nTitle : " << title << "\tPlot : " << plot<<"\tEditor : "<<editor<<"\t Release Year : "<<releaseYear<<endl;
	authors.print();
	cout << endl;
}

void Book::printTitleYearEditor() {
	cout << "\nTitle :\t" << title << endl;
	cout << "Release year :\t" << releaseYear << endl;
	cout << "Editor :\t" << editor << endl;
}
