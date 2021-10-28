/*
    "GenreBST.cpp"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#include "GenreBST.h"

// Constructor
GenreBST::GenreBST() {
	root = NULL;
}

// Add genre helping function which will add the genre in the Binary Search Tree
void GenreBST::addGenre(string genreTitle, GenreNode* root) {
	
	// If the genre title is less than current node's title (remember a is small than z) then we add the genre title left of the tree
	if (genreTitle < root->getTitle()) {	

		// If the left of the node is empty, then insert it here
		if (root->getLeft() == NULL) {						
			root->setleft(new GenreNode(genreTitle));		
		}
		
		// If the left node is not empty we're going to the left node and find any other position
		else{
			addGenre(genreTitle, root->getLeft());			
		}
	}
	
	// If the genre title is greater than or equal to current node's title then insert on right of the tree
	else {													
		if (root->getRight() == NULL) {	
			
			// If the right node is empty then insert it here  
			root->setRight(new GenreNode(genreTitle));
		}
		else {
			
			// Otherwise go to the right node and find the position
			addGenre(genreTitle, root->getRight());			
		}
	}
}

// Add the book with the given genre
void GenreBST::addBook(string genreTitle, string bookTitle, string plot, AuthorLinkedList authors, string editor, int releaseYear, GenreNode* root) {
	
	// If there exists no any genre in the tree
	if (root == NULL)
		return;
	
	// Finding given genre node and then inserting the book in the given genre
	if (root->getTitle() == genreTitle) {
		
		// Finding genre node and inserting it
		root->insertBook(bookTitle, plot, authors, editor, releaseYear);
	}
	
	// If given genre title is less than current genre's title
	else if (genreTitle < root->getTitle()) {
		
		// Find given genre in the left of that current node
		addBook(genreTitle, bookTitle, plot, authors, editor, releaseYear, root->getLeft());
	}
	
	// Find given genre in the right of that node
	else 
		addBook(genreTitle, bookTitle, plot, authors, editor, releaseYear, root->getRight());
}

// Add book function 
void GenreBST::addBook(string genreTitle, string bookTitle, string plot, AuthorLinkedList authors, string editor, int releaseYear) {
	if (searchGenre(genreTitle)) {
		addBook(genreTitle, bookTitle, plot, authors, editor, releaseYear, root);
	}
	else
		cout << "No such genre found in library." << endl;
}

// Print all the books by genre
void GenreBST::printAllBookByGenre() {
	printAllBookByGenre(root);
}

// Helping function for printing books of given genre
void GenreBST::printAllBookBySelectedGenre(string title, GenreNode* root) {
	
	// If the current node is null than return 
	if (root == NULL)
		return;
	
	// If we found given genre in the tree
	if (root->getTitle() == title)
		
		// Print all the books of that genre
		root->printAllBooks();
		
	// If we not find the given genre and the given genre's title is less than current genre, then go to left and find the genre
	else if (title < root->getTitle())
		printAllBookBySelectedGenre(title, root->getLeft());
	
	// If we not find the given genre and the given genre's title is not less than current genre's title then go to the right of the treee
	else
		printAllBookBySelectedGenre(title, root->getRight());
}

// Helping function of deleting book 
bool GenreBST::deleteBook(string title,GenreNode* root) {
	
	// If current node is null then return false
	if (root == NULL)
		return false;
	
	// If the title of the book is found at the current genre
	if (root->searchBook(title) != NULL) {
		
		// Then delete it and return true
		root->deleteBook(title);
		return true;
	}
	
	// Else check the book in the left genre tree
	bool b = deleteBook(title, root->getLeft());
	
	// If book was found and deleted in the left of tree than return 
	if (b)
	return b;

	// Else go to the right and delete the book if is found
	return deleteBook(title, root->getRight());
}
