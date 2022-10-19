#include "queue.h"

using namespace std;

const int SIZE = 100;

//Khaled Esmail, CS163, 5/2/2022, in main I gather all of the info I need from the user and I pass it into each function. 


int main()
{
	char option = ' ';//user option
	char user_option = ' ';
	bool stop = true;//loop variable
	stack to;//object to call functions 	
	book_info call;//object to call functions
	queue obj;//object to call functions
	assignment call2;
	char copy_author[SIZE];
	char copy_title[SIZE];
	char copy_publisher[SIZE];
	int copy_page = 0;	
	char copy_class[SIZE];
	char copy_name[SIZE];
	char copy_date[SIZE]; 
	while(stop == true)
	{
		cout<<"Please choose what you would like to do"<<endl;
		cout<<"1.Add a book"<<endl<<"2.Display all books"<<endl<<"3.Remove a book"<<endl<<"4.Retrieve the last book added"<<endl<<"5.Add an assignment"<<endl
			<<"6.Delete an assignment"<<endl<<"7.Retrieve the last assignment added"<<endl<<"8.Display all"<<endl<<"9.Quit"<<endl;
		cin >> option;
		cin.ignore(100, '\n');
		switch(option)
		{
			case '1':cout<<"Please enter the author of the book"<<endl;
				 cin.get(copy_author, SIZE, '\n');
				 cin.ignore(100, '\n');

				 cout<<"Please enter the title of the book"<<endl;
				 cin.get(copy_title, SIZE, '\n');
				 cin.ignore(100, '\n');

				 cout<<"Please enter the publisher of the book"<<endl;
				 cin.get(copy_publisher, SIZE, '\n');
				 cin.ignore(100, '\n');

				 cout<<"Please enter the last page you left off at"<<endl;
				 cin >> copy_page;
				 cin.ignore(100, '\n');
				 call.create_book(copy_author,copy_title,copy_publisher,copy_page);
				 to.push(call);	
				 break;

			case '2':to.display();
				 break;
			case '3':to.pop();
				 break;
			case '4':to.peek();
				 break;
			case '5':

				 cout<<"Please enter the class you are in"<<endl;
				 cin.get(copy_class, SIZE, '\n');
				 cin.ignore(100, '\n');

				 cout<<"Please enter the name of the assignment"<<endl;
				 cin.get(copy_name, SIZE, '\n');
				 cin.ignore(100, '\n');

				 cout<<"Please enter the due date of the assignment"<<endl;
				 cin.get(copy_date, SIZE, '\n');
				 call2.create_assignment(copy_class, copy_name, copy_date);	
				 cin.ignore(100, '\n');

				 cout<<"To add a book enter the letter y, if you don't want to enter a book enter the letter n."<<endl;

				 cin >> user_option;
				 cin.ignore(100, '\n');
				 while(user_option == 'y')
				 {
					 cout<<"Please enter the author of the book"<<endl;
					 cin.get(copy_author, SIZE, '\n');
					 cin.ignore(100, '\n');

					 cout<<"Please enter the title of the book"<<endl;
					 cin.get(copy_title, SIZE, '\n');
					 cin.ignore(100, '\n');

					 cout<<"Please enter the publisher of the book"<<endl;
					 cin.get(copy_publisher, SIZE, '\n');
					 cin.ignore(100, '\n');

					 cout<<"Please enter the last page you left off at"<<endl;
					 cin >> copy_page;
					 cin.ignore(100, '\n');
					 cout<<"To add another book enter the letter y, if you don't want to enter another book enter the letter n."<<endl;
					 cin >> user_option;
					 cin.ignore(100, '\n');
					 call.create_book(copy_author,copy_title,copy_publisher,copy_page);
					 to.push(call);
				 }

				 obj.enqueue(call2, to);
				 break;
			case '6':obj.dequeue();
				 break;
			case '7':obj.q_peek();
				 break;
			case '8':obj.q_display();
				 break;
			case '9':stop = false;
				 break;
			default:
				 cout<<"This is the wrong option"<<endl; 
				 break;

		}

	}
	return 0;

} 
