/*
    "GenreNode.cpp"
    Nombre: Jan Rodriguez
    Fecha: 14 de mayo de 2021
    Prof. Julio Cruz || Yahya Masalmah
    COMP 315 Lab | Sección 41
    Proyecto - Library Database
*/

#include "GenreNode.h"

GenreNode::GenreNode(string title) {
	this->title = title;
	this->left = NULL;
	this->right = NULL;
}
void GenreNode::insertBook(string title, string plot, AuthorLinkedList authors, string editor, int releaseYear) {
	books.insert(title, plot, authors, editor, releaseYear);
}
Book* GenreNode::searchBook(string title) {
	return books.search(title);
}
void GenreNode::deleteBook(string title) {
	books.deleteABook(title);
}
void GenreNode::printAllBooks() {
	cout << "\n**Genre: " << title<<"**";
	books.print();
}
void GenreNode::setleft(GenreNode* left) {
	this->left = left;
}
void GenreNode::setRight(GenreNode* right) {
	this->right = right;
}
GenreNode* GenreNode::getLeft() {
	return left;
}
GenreNode* GenreNode::getRight() {
	return right;
}
void GenreNode::setTitle(string title) {
	this->title = title;
}
string GenreNode::getTitle() {
	return title;
}
