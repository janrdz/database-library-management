/*
    "GenreNode.h"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#ifndef GENRENODE
#define GENRENODE
#include"DoublyCircularLinkedList.h"

// Genre Node 
class GenreNode {

	// Attributes of genre 
	string title;
	DoublyCircularLinkedList books;
	GenreNode* left;
	GenreNode* right;
public:
	// Default Constructor
	GenreNode(string title);

	// Function for inserting book in genre
	void insertBook(string title, string plot, AuthorLinkedList authors, string editor, int releaseYear);

	// Searching book function 
	Book* searchBook(string title);

	// Printing all books of genre
	void printAllBooks();
	
	// setters and getters
	void setleft(GenreNode* next);
	void setRight(GenreNode* next);
	GenreNode* getLeft();
	GenreNode* getRight();

	// Delete book from genre
	void deleteBook(string title);
	void setTitle(string title);
	string getTitle();

};
#endif // !GENRENODE
