/*
 * C++ Program to Implement Singly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "ll.h"
using namespace std;
/*
 * Node Declaration
 */
int counter = 0;    //This counter is used because I need to use a different method when I'm adding the first node. I have two
                    //different methods, one that adds the node at the end and one that adds the node at the beginning. The
                    //method that adds the method at the end of the node cannot be used to add the first line

struct node
{                       //creating my node
    string info;        //has paramaters string, and pointer to next node
    struct node *next;
}*start;

/*
 * Class Declaration
 */
class single_llist
{
     //Function prototypes
    public:
	void fragment();
        node* create_node(string);      //node constructor
        void insert_begin();            //adds elements to the nodes at the beginning
        void insert_last();             //adds elements to the nodes at the end
        void delete_pos();              //deletes elements
        void display();                 //Displays the slots of memore
        single_llist()                  //class constructor which initializes the first node to be NULL
        {
            start = NULL;
        }
};

/*
 * Main :contains menu
 */
main()
{
    int choice, nodes, element, position, i;        //declare variables
    single_llist sl;                            //create an instance of the class
    start = NULL;       //ensures that the first node is NULL
    while (1)           //Program iterates unless user terminates
    {
        cout<<"1. Add program\n";
        cout<<"2. Kill program\n";
        cout<<"3. Fragmentation\n";
        cout<<"4. Print memory\n";
        cout<<"5. Exit \n"<<"\n";
        cout<<"Choice -  ";
        cin>>choice;        //User picks an item from the menu
        switch(choice)
        {
        case 1:
            cout<<"Inserting Node at Last: "<<endl;     //If the user wants to add a node
            sl.insert_last();
            cout<<endl;
            break;


        case 3:
            cout<<"Fragment: "<<endl;       //counts the number of fragments
            sl.fragment();
            cout<<endl;
            break;

        case 2:
            cout<<"Delete a particular node: "<<endl;       //deletes a program
            sl.delete_pos();
            break;
            /*
        case 6:
            cout<<"Update Node Value:"<<endl;
            sl.update();
            cout<<endl;
            break;
            */

        case 4:
            cout<<"Display elements of link list"<<endl;
            sl.display();
            cout<<endl;                                                 //prints out the linked list
            break;
        case 5:
            cout<<"Exiting..."<<endl;
            exit(1);                        //exits program
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}


 // Creating Node

node *single_llist::create_node(string value)       //The input is a string
{
    struct node *temp, *s;      //creates a temporary node
    temp = new(struct node);    //temp points to the node
    if (temp == NULL)           //makes sure there is a value in the node
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else
    {                           //temp points to the string but the next node is null
        temp->info = value;
        temp->next = NULL;
        return temp;
    }
}






void single_llist::fragment(){
	int i = 1;

}







/*
 * Inserting element in beginning
 */
void single_llist::insert_begin()
{
    int i = 0;              //counter for the number of nodes the program takes up
    string value;           //what goes into the node
    int size;                       //How many KB's the program has
    cout<<"Program name -  ";
    cin>>value;
    while(true){
        cout<<"Program size (KB)- ";
        cin>>size;
        if(size > 128){
            true;
            cout<<"Error, Not enough memory for Program " <<value <<" Please try again\n";
        }
        else{
            break;
        }
    }
    do{
    struct node *temp, *p;
    temp = create_node(value);          //creates the instance of a temp node

        if (start == NULL)
        {
            start = temp;           //the first node is now the the temp value
            start->next = NULL;     //it then goes to NULL
        }
        else
        {
            p = start;
            start = temp;
            start->next = p;
        }
        i++;
        size = size -4;
    }
    while(size > 0);
    cout<< "Program "<<value<<" added successfully: "<<i << " page(s) used.\n";
}

/*
 * Inserting Node at last
 */
void single_llist::insert_last()
{
    int i = 0;          //counts the number of nodes the program takes
    if(counter ==0)     //makes sure the method that inserts the data into the node at the beginning instead of the end it used
    {
        insert_begin();
        counter++;          //as long as the counter is greater than 0, the method which puts
    }
    else{
    string value;           //the name of the program
    int size;               //KB's in the program
    cout<<"Program name - ";
    cin>>value;
    while(true){
        cout<<"Program size (KB)- ";
        cin>>size;
        if(size > 128){
            true;
            cout<<"Error, Not enough memory for Program " <<value <<" Please try again\n";
        }
        else{
            break;
        }
    }
    do{
    struct node *temp, *s;              //temp is constructed, it points to the node
    temp = create_node(value);          //also, s referes the the first node
    s = start;

        while (s->next != NULL)
        {
            s = s->next;
        }
        temp->next = NULL;
        s->next = temp;
        i++;
        //cout<<"Element Inserted at last"<<endl;
        size = size -4;
        }
        while(size > 0);
        cout<< "Program "<<value<<" added successfully: "<<i << " page(s) used.\n";
    }


}

/*
 * Delete element at a given position
 */
void single_llist::delete_pos()     //deletes programs
{
    int i, counter = 0;
    string toRemove;            //takes in user input to find out the name of the program to delete
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;        //if the first element is NULL, you can't remove anthing
        return;
    }
    cout<<"Enter the program to be deleted: ";
    cin>>toRemove;
    struct node *s, *ptr;       //constructs pointers to the nodes
    //temp = start;

    struct node *temp;      //also a temp node
    temp = start;           //it is initialized as pointing to the first node
    for(int i = 0; i< 32; i++){
	if(temp -> next == NULL){       //if the node is null, exit
		break;
	}

        if((temp->info.compare(toRemove) == 0)){        //if wny of the values in temp are NULL, print Free
           	temp -> info = "Free";
        }

        temp = temp->next;                      //temp now points to the next node
    }
	bool cut = false;
	temp -> info = "Free";
	temp = start;
	for (int i = 0; i < 32; i++)
	{
		if(temp -> next == NULL){
		break;
	}
		if(!(temp->info.compare("Free") == 0)){
           	cut = true;
        	}
		temp = temp -> next;
	}
	if (cut)
	{
		counter = 0;
	}

}

/*
 * Update a given Node
 */
 /*
void single_llist::update()
{
    string value;
    int pos, i;
    if (start == NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Enter the node postion to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s, *ptr;
    s = start;
    if (pos == 1)
    {
        start->info = value;
    }
    else
    {
        for (i = 0;i < pos - 1;i++)
        {
            if (s == NULL)
            {
                cout<<"There are less than "<<pos<<" elements";
                return;
            }
            s = s->next;
        }
        s->info = value;
    }
    cout<<"Node Updated"<<endl;
}

/*
 * Display Elements of a link list
 */
void single_llist::display()
{
    struct node *temp;
    temp = start;
    for(int i = 0; i < 32; i++){
        if(i == 8 || i == 16 || i == 24){       //go to the next line after 8 elements
            cout<<"\n";
        }

        if (temp == NULL)               //When the node is empty or doesnt exist yet, print out free
        {
            cout<<"Free\t";
        }

        if(temp != NULL )
        {                                   //otherwise print the name of the program in the node
            cout<<temp->info<<"\t";
            temp = temp->next;
        }
    }
}
