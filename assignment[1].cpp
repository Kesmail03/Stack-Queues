#include "queue.h"


using namespace std;

//Khaled Esmail, CS163, 5/2/2022, this is where I implemented the functions for my queue. This also had a stack added in which is why I have some functions being called from my book.cpp file. 



//constructor
queue::queue()
{
	rear = nullptr;
	index = 0;
}


//To create the assignment using the info from main
int assignment::create_assignment(char * copy_class, char * copy_name, char * copy_date)
{
	if(copy_class)
	{
		this->class_name = new char[strlen(copy_class) + 1];
		strcpy(this->class_name, copy_class);
	}
	if(copy_name)
	{
		this->name = new char[strlen(copy_name) + 1];
		strcpy(this->name, copy_name);
	}
	if(copy_date)
	{
		this->date = new char[strlen(copy_date) + 1];
		strcpy(this->date, copy_date);
	}
	return 1;

}
//copies the info 
int assignment::copy_assignment(assignment & add)
{
	if(add.class_name)
	{
		class_name = new char[strlen(add.class_name) + 1];
		strcpy(class_name, add.class_name);
	}
	if(add.name)
	{
		name = new char[strlen(add.name) + 1];
		strcpy(name, add.name);
	}
	if(add.date)
	{
		date = new char[strlen(add.date) + 1];
		strcpy(date, add.date);
	}
	
	
	return 1;
}
//calls the function that copies the book info into the queue
int assignment::copy_stack(stack & copy)
{
	object.copy_stack(copy);
	return 1;

}
//adds to the queue
int queue::enqueue(assignment & add, stack & object)
{
	if(rear == nullptr)
	{
		rear = new q_node;
		rear->next = rear;
		rear->data.copy_assignment(add);
		rear->data.copy_stack(object);
		return 1;
	}
	else
	{
		q_node * temp = new q_node;
		temp->next = rear->next;
		rear->next = temp;
		rear = temp;
		rear->data.copy_assignment(add);
		rear->data.copy_stack(object);
		return 1;
	}
	return 1;

}

//removes from the queue
int queue::dequeue()
{
	if(!rear)
		return 0;
	if(rear == rear->next)
	{
		delete rear;
		rear = nullptr;
		return 1;
	}
	else
	{
		q_node * temp = rear->next->next;
		delete rear->next;
		rear->next = temp;
		return 1;
	}	


}

//peeks the first node added
int queue::q_peek()
{
	if(!rear)
	{
		cout<<"The list is empty"<<endl;
		return 0;
	}
	rear->next->data.display_assignment();
	return 1;		


}
//wrapper function
int queue::q_display()
{
	if(!rear)
	{
		cout<<"The list is empty"<<endl;
		return 0;
	}
	return q_display(rear->next);
}

int queue::q_display(q_node * rear)
{
	if(rear == this->rear)
	{
		rear->data.display_assignment();
		return 0;
	}
	rear->data.display_assignment();
	return q_display(rear->next);

}

//displays the assignment info and calls function to display book info
int assignment::display_assignment()
{

	cout<<"The class name is: "<<endl;
	cout<< class_name <<endl;

	cout<<"The assignment name is: "<<endl;
	cout<< name <<endl;

	cout<<"The due date is: "<<endl;
	cout<< date <<endl;

	object.display();	

	return 1;

}


int queue::destructor()
{
	if(!this->rear)
		return 0;
	return destructor(rear);


}

int queue::destructor(q_node *& current)
{
	if(current == rear)
	{
		delete current;	
		return 0;
	}
	destructor(current->next);
	delete current;
	return 1;

}


queue::~queue()
{
	destructor();

}

assignment::assignment()
{
	class_name = nullptr;
	name = nullptr;
	date = nullptr;

}

assignment::~assignment()
{
	 
	delete [] class_name;
	delete [] name;
	delete [] date;

}








