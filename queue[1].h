#include "stack.h"
#include <iostream>
#include <cstring>
#include <cctype>

//Khaled Esmail, CS163, 5/2/2022, this header file contains the classes for my queue and all of the info for my assignment. It has the struct node for my queue also. 

class assignment
{
	public:
		assignment();
		~assignment();
		int create_assignment(char * copy_class, char * copy_name, char * copy_date);
  		int copy_assignment(assignment & add);
		int display_assignment();
		int insert_book(book_info & to_add);
		int copy_stack(stack & copy);
	private:
		char * class_name;
		char * name;
		char * date;
		stack object;	
};



struct q_node
{
	q_node * next;
	assignment data;

};



class queue
{
	public:
		queue();
		~queue();
		int enqueue(assignment & add, stack & object);
		int q_display();
		int dequeue();
		int q_peek();
		int destructor();
	private:
		q_node * rear;
		int index;
		int q_display(q_node * rear);
		int destructor(q_node *& current);

};





