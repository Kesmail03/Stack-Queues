#include <iostream>
#include <cstring>
#include <cctype>


//Khaled Esmail, CS163, 5/2/2022, this header file contains the class for the book info and the stack. It also contains the struct node. 

class book_info
{
	public:
		book_info();
		~book_info();
		int display_book();
		int create_book(char * copy_author, char * copy_title, char * copy_publisher, int copy_page);
		int copy_entry(book_info & to_add);
		int is_empty();//returns 0 if it's empty
	private:
		char * author;
		char * title;
		char * publisher;
		int page;
		
};



struct node
{
	book_info * book;
	node * next;

};

const int MAX = 5;

class stack
{
	public:
		int push(book_info & to_add);
		int pop();
		int display();
		int peek();
		int copy_stack(stack & copy);
		stack();
		~stack();
	private:
		node * head;
		int top_index;


};




