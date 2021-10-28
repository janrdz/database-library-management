/*
    "GenreBST.h"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#ifndef GENREBST
#define GENREBST
#include"GenreNode.h"

class GenreBST {

	// Root of the Binary Search Tree
	GenreNode* root;

	// Helping function for inserting the genre 
	void addGenre(string genreTitle,GenreNode* root);

	//Inorder traversal for printing BST in ascending order 
	void printInorder(GenreNode* root);

	// Helping function of searching title of genre from list 
	bool searchGenre(string title, GenreNode* root);

	// Helping function for searching the book from all genre
	Book* searchBook(string title,GenreNode* root);

	// Helping functions for adding book in a given genre
	void addBook(string genreTitle, string bookTitle, string plot, AuthorLinkedList authors, string editor, int releaseYear, GenreNode* root);

	// Helping function for printing all books of all genre
	void printAllBookByGenre(GenreNode* root);

	// helping function for Printing all books of given genre title
	void printAllBookBySelectedGenre(string genreTitle, GenreNode* root);

	// helpting function of deleting book from library
	bool deleteBook(string title, GenreNode* root);
public:
	// Default Constructor
	GenreBST();

	// Adding Genre function
	void addGenre(string genreTitle);

	// Printing all genre 
	void printAllGenre();

	// searching given genre title
	bool searchGenre(string title);

	// function for adding book in a genre
	void addBook(string genreTitle, string bookTitle, string plot, AuthorLinkedList authors, string editor, int releaseYear);

	// Search book of given title
	Book* searchBook(string title);

	// Deleting book
	bool deleteBook(string title);
	
	// Print all books of all genre
	void printAllBookByGenre();

	// Print all books of a selected genre
	void printAllBookBySelectedGenre(string genreTitle);

	// if library have genre
	bool genrePresent();
};

#endif // !GENREBST
