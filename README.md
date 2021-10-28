# database-library-management

A database to store books using the console. Here I implement what I learned on the course COMP 315 on UAGM. Code is partially open source. You will find: Single Linked List, Doubly Linked and Circular List, Binary Search Trees and so on.

This program was designed with the following menu:

* Add a genre
* Add a book
* Modify a book.
* List all genre
* List all book by genre
* List all book for a particular genre
* Search for a book
* Exit

### Project’s architecture 

The list of genres must be implemented using a binary search tree sorted based on genre’s title. Each node must contain two attributes: Genre’s title and a title-sorted doubly circular list with books’ information. For each book, the author list must be implemented using a singly linked list ordered by author’s last name.

