#include <iostream>
#include <windows.h>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node* prev;
};


class Mylist {
	private:
		Node* head;
		Node* tail;
		int count;
	public:
		Mylist():head(NULL),tail(NULL),count(0){}
		~Mylist();                       
		void push_back(int data); 
		void push_front(int data);
		void pop_back();
		void pop_front();
		void insert(int data,int index);
		int at(int index);
		void remove(int index);
		int get_size();
		void set(int data,int index);
		int find_first(Mylist* secondlist);
		bool isEmpty();
		friend ostream& operator << (ostream& out, const Mylist* temp);
};

ostream& operator << (ostream& out, const Mylist* tempM)
{
	Node* tempN = tempM->head;
	if(tempN==NULL)
	{
		out << "List is Empty!\n";
		return(out);
	}
	else
	{
		while (tempN != NULL)
		{
			cout << tempN->data << " ";
			tempN = tempN->next;
		}
		out << "\n";
		return(out);
	}
}

Mylist::~Mylist()                          
{
	while (head)                       
	{
		tail = head->next;             
		delete head;                   
		head = tail; 
		count--;
	}
	
}

void Mylist::push_back(int data)
{
	Node* temp = new Node;               
	temp->next = NULL;                   
	temp->data = data;                        

	if (head != NULL)                  
	{
		temp->prev = tail;             
		tail->next = temp;              
		tail = temp;                     
	}
	else 
	{
		temp->prev = NULL;               
		head = tail = temp;              
	}
	count++;
}

void Mylist::push_front(int data)
{
	Node* temp = new Node;
	temp->prev = NULL;
	temp->data = data;
	temp->next = head;

	if (head != 0)head->prev = temp;

	if (head == NULL)head = tail = temp;
		else head = temp;

	count++;
}

void Mylist::pop_front() 
{
	tail = head->next;
	delete head;
	head = tail;
	count--;
}

void Mylist::pop_back() 
{
	Node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	tail = temp->prev;
	delete temp;
	tail->next = NULL;
	count--;
}

void Mylist::insert(int data,int index)
{
	if (index < 1 || index > count + 1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	if (index == count + 1)
	{
		push_back(data);
		return;
	}
	else if (index == 1)
	{
		push_front(data);
		return;
	}

	int i = 1;

	Node* elem = head;

	while (i < index)
	{
		elem = elem->next;
		i++;
	}

	Node* prevelem = elem->prev;
	Node* temp = new Node;
	temp->data=data;

	if (prevelem != 0 && count != 1)prevelem->next = temp;

	temp->next = elem;
	temp->prev = prevelem;
	elem->prev = temp;

	count++;
}

int Mylist::at(int index)
{
	Node* temp = head;

	if (index < 1 || index > count + 1)
	{
		cout << "Incorrect position !!!\n";
		return(0);
	}

	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	}
	return(temp->data);
}

void Mylist::remove(int index)
{
	
	if (index < 1 || index > count)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	int i = 1;

	Node* delelem = head;

	while (i < index)
	{
		delelem = delelem->next;
		i++;
	}

	Node* prevdelelem = delelem->prev;
	Node* afterdelelem = delelem->next;

	
	if (prevdelelem != 0 && count != 1)
		prevdelelem->next = afterdelelem;

	if (afterdelelem != 0 && count != 1)
		afterdelelem->prev = prevdelelem;

	if (index == 1)
		head = afterdelelem;
	if (index == count)
		tail = prevdelelem;

	delete delelem;

	count--;
}

int Mylist::get_size()
{
	return(count);
}

void Mylist::set(int data,int index)
{
	Node* temp = head;

	if (index < 1 || index > count + 1)
	{
		cout << "Incorrect position !!!\n";
		return;
	}

	for (int i = 0; i < index-1; i++)
	{
		temp = temp->next;
	}
	temp->data = data;
}

int Mylist::find_first(Mylist* secondlist)
{
	int secondlength,breaker,index;
	secondlength = secondlist->get_size();

	Node* first = head;
	Node* second = secondlist->head;

	for (int i = 0; i < count; i++) 
	{
		breaker = 0;
		for (int j = 0; j < secondlength; j++) 
		{
			if (first->data == second->data) 
			{
				index = j;
				breaker = 1;
				break;
			}
			second = second->next;
		}
		if (breaker == 1) {
			break;
		}
		first = first->next;
		second= secondlist->head;
	}
	return(index);
}

bool Mylist::isEmpty() {
	if (head == NULL) 
	{
		cout << "List is empty!!!";
		return(0);
	}
	else 
	{
		cout << "List is NOT empty!!!";
		return(1);
	}
	cout << "\n";
}

int main() {
	Mylist firstlist,secondlist;
	int data,enter,index,length;
	boolean flag = 1;

	cout << "enter length:";
	cin >> length;
	cout << "\n";

	cout << "first list:\n";
	for (int i = 0; i < length; i++) {
		cin >> data;
		firstlist.push_back(data);
	}

	while (flag==1) 
	{
		cout << "1)ShowMylist(<<)\n";
		cout << "2)pop_back\n";
		cout << "3)pop_front\n";
		cout << "4)~Mylist(clear)\n";
		cout << "5)push_back\n"; 
		cout << "6)push_front\n";
		cout << "7)insert\n";
		cout << "8)remove\n";
		cout << "9)get_size\n";
		cout << "10)set\n";
		cout << "11)isEmpty\n";
		cout << "12)at\n";
		cout << "13)find_first\n";
		cout << "chose action:";
		cin >> enter;
		cout << "\n";
		if (enter == 1)
		{
			cout << &firstlist;
		}
		if (enter == 2)
		{
			firstlist.pop_back();
		}
		if (enter == 3)
		{
			firstlist.pop_front();
		}
		if (enter == 4)
		{
			firstlist.~Mylist();
		}
		if (enter == 5) 
		{
			cin >> data;
			firstlist.push_back(data);
		}
		if (enter == 6)
		{
			cin >> data;
			firstlist.push_front(data);
		}
		if (enter == 7)
		{
			cin >> data;
			cin >> index;
			firstlist.insert(data, index);
		}
		if(enter==8)
		{
			cin >> index;
			firstlist.remove(index);
		}
		if(enter==9)
		{
			cout << firstlist.get_size() << "\n";
		}
		if(enter==10)
		{
			cin >> data;
			cin >> index;
			firstlist.set(data, index);
		}
		if(enter==11)
		{
			firstlist.isEmpty();
		}
		if (enter == 12) 
		{
			cin >> index;
			cout << firstlist.at(index) << "\n";
		}
		if (enter == 13) 
		{
			cout << "enter length:";
			cin >> length;
			cout << "\n";
			cout << "second list:\n";
			for (int i = 0; i < length; i++) {
				cin >> data;
				secondlist.push_back(data);
			}
			cout<<firstlist.find_first(&secondlist)<<"\n";
			secondlist.~Mylist();
		}
		cout << "\n";
	}
}