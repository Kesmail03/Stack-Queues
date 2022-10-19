#include "stack.h"


//Khaled Esmail, CS163, 5/2/2022, this is where the implementations of my stack functions are. I created a couple extra functions like the is_empty and copy_entry function to make things easier.


using namespace std;
stack::stack()
{
	head = nullptr;
	top_index = 0;	


}

//creates the book info
int book_info::create_book(char * copy_author,  char * copy_title, char * copy_publisher, int copy_page)
{
	//this is to prevent memory leaks. If memory already exists then it will replace it and cause a leak
	if(author)
		delete [] author;
	if(title)
		delete [] title;
	if(publisher)
		delete [] publisher;
 	
	this->author = new char[strlen(copy_author) + 1];
	strcpy(this->author, copy_author);


	this->title = new char[strlen(copy_title) + 1];
	strcpy(this->title, copy_title);

	this->publisher = new char[strlen(copy_publisher) + 1];
	strcpy(this->publisher, copy_publisher);

	this->page = copy_page;

	return 1;
}

//copies the book info
int book_info::copy_entry(book_info & to_add)
{
	if(to_add.author)
	{
		this->author = new char[strlen(to_add.author) + 1];
		strcpy(this->author, to_add.author);
	}
	if(to_add.title)
	{
		this->title = new char[strlen(to_add.title) + 1];
		strcpy(this->title, to_add.title);
	}
	if(to_add.publisher)
	{
		this->publisher = new char[strlen(to_add.publisher) + 1];
		strcpy(this->publisher, to_add.publisher);
	}
	if(to_add.page)
	{
		this->page = to_add.page;
	}
	return 1;

}

//copies the stack into the queue.
int stack::copy_stack(stack & copy)
{
	node * current = copy.head;
	while(current)
	{
		for(int i = 0; i < MAX; ++i)
		{
			if(current->book[i].is_empty() == 1)
				push(current->book[i]);
		}
		current = current -> next;
	}
	return 1;
}

//this function checks if the stack is empty
int book_info::is_empty()
{
	if(author == nullptr)
		return 0;
	return 1;

	
}


//this pushes a book onto the stack
int stack::push(book_info & to_add)
{
	if(head == nullptr)
	{
		head = new node;
		head->next = nullptr;
		head->book = new book_info[MAX];	
		head->book[top_index].copy_entry(to_add);
		++top_index;
		return 1;
	}

	if(top_index < MAX)
	{
		head->book[top_index].copy_entry(to_add);	
		++top_index;
		return 1;
	}
	if(top_index == MAX)
	{
		node * temp = new node;
		temp->next = head;
		head = temp;
		head->book = new book_info[MAX];
		head->book[top_index].copy_entry(to_add);
		++top_index;
		return 1;
	}
	return 1;	
}
//wrapper function
int stack::display()
{
	if(head == nullptr)
		return 0;
	int i = top_index;
	node * current = head;
	while(current)
	{
		while(i != 0)
		{
			current->book[i-1].display_book();
			--i;
		}
		current = current -> next;
		i = MAX;
	}
	return 1;
}


int book_info::display_book()
{

	cout<<"The author is: "<<endl;
	cout<<author<<endl;

	cout<<"The title is: "<<endl;
	cout<<title<<endl;

	cout<<"The publisher is: "<<endl;
	cout<<publisher<<endl;

	cout<<"The page is: "<<endl;
	cout<<page<<endl;
	return 1;

}

//this pops a book off the stack. Deleting the latest book added
int stack::pop()
{
	if(head == nullptr)
		return 0;
	if(top_index > 0)
	{
		delete [] head->book;
		--top_index;
		return 1;
	}
	if(top_index ==0)
	{
		delete [] head->book;
		node * hold = head->next;
		delete head;
		head = hold;
		--top_index;
		return 1;
	}
	return 0;

}

//this displays the last book added
int stack::peek()
{
	if(head == nullptr)
	{
		cout<<"The list is empty"<<endl;
		return 0;
	}
	head->book[top_index].display_book();
	return 1;
}

//destructor
stack::~stack()
{
	node * temp = nullptr;
	while(head)
	{
		temp = head->next;
		if(head->book)
		{
			delete [] head->book;
			head->book = nullptr;
		}
		delete head;
		head = temp;
	}

}
book_info::book_info()
{


}

//destructor
book_info::~book_info()
{
	if(author)
	{
		delete [] author;
		author = nullptr;
	}
	if(title)
	{
		delete [] title;
		title = nullptr;
	}
	if(publisher)
	{
		delete [] publisher;
		publisher = nullptr;
	}
	

}















