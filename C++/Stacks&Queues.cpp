// Ali Ghuman
// ECE 264
// Professor Sable
// Program executes commands from a given text document and prints the results to another user-provided document

#include <iostream> 
#include <list> 
#include <fstream>

using namespace std;
//Set up the file streams
ifstream inputF; 
ofstream outputF;  

//create base class SimpleList
template <typename T> 
class SimpleList 
{
private: 
	//set up nodes for linked list
	class Node 
	{
	public:
		T data; 
		Node *next; 

		Node(T value, Node *n = nullptr) : data{value}, next{n} {}
	};

	string name; 
	int size = 0; 
	Node *head = nullptr; 
	Node *tail = nullptr; 

protected: 
	//functions that derived classes can use for push/pop
	void insertStart(T value); 
	void insertEnd(T value); 
	T removeStart(); 

public: 
	SimpleList(string &nameGiven) : name{nameGiven} {}        //constructor allows to set the name of object


	//pure virtual functions to make sure derived classes define push/pop
	virtual void push(T value) = 0;
	virtual T pop() = 0; 
	
	//functions to return the name of object/return true or false if the object is empty 
	string getName() const
	{return name;}
	bool isEmpty() const
	{return size == 0;}

};

//create a new node at the beginning of the object
template <typename T> 
void SimpleList<T>::insertStart(T value)
{
	Node *nP = new Node{value, head}; 
	head = nP; 
	size++; 	
}

//create a new node at the end of the object 
template <typename T>
void SimpleList<T>::insertEnd(T value)
{
	Node *nP = new Node{value}; 
	if (size > 0)
	{
		tail->next = nP; 
	}
	tail = nP; 
	++size;
	if (size == 1)
	{
		head = tail; 
	}
}

//remove a node from the start of the object
template <typename T>
T SimpleList<T>::removeStart()
{
	T retValue = head->data; 
	Node *tmp = head; 
	head = head->next; 
	delete tmp; 
	if (size == 1) 
	{
		tail = nullptr; 
	}
	--size; 
	return retValue; 
}


//a stack derived class w/ push and pop meant for stacks
template <typename T> 
class Stack : public SimpleList<T> 
{
public:
	Stack(string &nameGiven) : SimpleList<T>{nameGiven} {}  //delegates to base class constructor
	
	void push(T value) override
	{SimpleList<T>::insertStart(value);}

	T pop() override
	{return SimpleList<T>::removeStart();} 	

};

//a queue derived class w/ push and pop meant for q's
template <typename T> 
class Queue : public SimpleList<T> 
{
public:
	Queue(string &nameGiven) : SimpleList<T>{nameGiven} {} 
	
	void push(T value) override
	{SimpleList<T>::insertEnd(value);}

	T pop() override
	{return SimpleList<T>::removeStart();} 	
};

//function to check if an object w/ the given name exists
template <typename T> 
bool nameExist(string &name, list<SimpleList<T> *> &tList)
{
	for (auto structure : tList)
	{
		if (structure->getName() == name)
		{
			return true; 
		}
	}
	return false; 
}

//gets the type of the object (if it's a stack or queue). True for stack, false for q
bool getType(string &inputText)
{
	if (inputText[inputText.length()-1] == 'k') //checks the last letter of input line
	{
		return true; 
	}
	else 
	{
		return false; 
	}
}

//retrieves the name of the object from given input
string getName(string &text)
{	
	int i = 0; 
	string tmp = text; 
	tmp += '\0'; //created a temporary object to modify it without modifying input. Add \0 so we have a condition to check for
	while (tmp[i] != ' ') //gets past the command
	{
		++i; 
	}

	++i; 
	string name;	
	while (tmp[i] != ' ') //adds char by char the value of the input to name var.
	{								
		if (tmp[i] == '\0') // If (for pop) \0 is reached, break. Otherwise end at first space
			break; 
		name += tmp[i]; 
		++i; 
	} 

	return name; 
}

//create a stack/q on the list of type int
void createiList(string &text, string &iName, list<SimpleList<int> *> &iL)
{
	if (!nameExist(iName, iL)) //checks if the name exists or not, if not, proceed
	{
		if (getType(text)) //check if it's stack or q
		{

			iL.push_front(new Stack<int>{iName}); //add to the list a stack
		}
		else 
		{
			iL.push_front(new Queue<int>{iName}); //add to the list a q

		}
	}
	else 
	{
		outputF << "ERROR: This name already exists!\n";
	}	
}

//create a stack/q on the list of type double
void createdList(string &text, string &dName, list<SimpleList<double> *> &dL)
{
	if (!nameExist(dName, dL))
	{
		if (getType(text))
		{

			dL.push_front(new Stack<double>{dName});
		}
		else 
		{
			dL.push_front(new Queue<double>{dName});

		}
	}
	else 
	{
		outputF << "ERROR: This name already exists!\n";
	}	
}

//create a stack/q on the list of type int
void createsList(string &text, string &sName, list<SimpleList<string> *> &sL)
{
	if (!nameExist(sName, sL))
	{
		if (getType(text))
		{

			sL.push_front(new Stack<string>{sName});
		}
		else 
		{
			sL.push_front(new Queue<string>{sName});

		}
	}
	else 
	{
		outputF << "ERROR: This name already exists!\n";
	}	
}

//retrieves the value from the input 
string getVal(string &text)
{
	int count = 0; 
	int i = 0; 
	string tmp = text;
	tmp += '\0';  
	string data; 
	while (count != 2)
	{
		while (tmp[i] != ' ') {++i;}
		++count; 
		++i;
	}
	while (tmp[i] != '\0')
	{
		data += tmp[i]; 
		++i; 
	} 

	return data; 

}

//call this function to push/pop from an integer object
void pInt(string &text, string &iName, list<SimpleList<int> *> &iL)
{
	if(nameExist(iName, iL))  //checks if name exists
	{

		for (auto structure : iL)
		{
			if (structure->getName() == iName) //checks if the name matches what we're looking for
			{
				if (text[1] == 'u') //checks if push

				{
					string data = getVal(text);
					structure->push(stoi(data)); 
					break;
				}
				if (text[1] == 'o') //checks if pop
				{
					if (structure->isEmpty()) //checks if empty
					{
						outputF << "ERROR: This list is empty!\n"; 
						break;
					} 
					else
					{
						outputF << "Value popped: " << structure->pop() << '\n';
						break; 
					}
				}
			}
		}

	}
	else 
	{
		outputF << "ERROR: This name does not exist!\n";
	}
}

//call this function to push/pop from an double object
void pDouble(string &text, string &dName, list<SimpleList<double> *> &dL)
{
	if(nameExist(dName, dL))
	{

		for (auto structure : dL)
		{
			if (structure->getName() == dName)
			{
				if (text[1] == 'u')
				{
					string data = getVal(text);
					structure->push(stod(data)); 
					break;
				}
				if (text[1] == 'o')
				{
					if (structure->isEmpty())
						{
							outputF << "ERROR: This list is empty!\n"; 
							break;
						} 
					else
					{
						outputF << "Value popped: " << structure->pop() << '\n';
						break; 
					}
				}
			}
		}

	}
	else 
	{
		outputF << "ERROR: This name does not exist!\n";
	}
}

//call this function to push/pop from an string object
void pString(string &text, string &sName, list<SimpleList<string> *> &sL)
{
	if(nameExist(sName, sL)) 
	{

		for (auto structure : sL)
		{
			if (structure->getName() == sName)
			{
				if (text[1] == 'u')
				{
					string data = getVal(text);
					structure->push(data); 
					break;
				}
				if (text[1] == 'o')
				{
					if (structure->isEmpty())
						{
							outputF << "ERROR: This list is empty!\n"; 
							break;
						} 
					else
					{
						outputF << "Value popped: " << structure->pop() << '\n';
						break; 
					}
				}
			}
		}

	}
	else 
	{
		outputF << "ERROR: This name does not exist!\n";
	}
}

//processes commands and calls the proper functions to perform the command
void processCommand(string &text, list<SimpleList<int> *> &iL, list<SimpleList<double> *> &dL, list<SimpleList<string> *> &sL)
{
	string name = getName(text); 
	if (text[0] == 'c') //for create
	{
		if (text[7] == 'i')
		{
			createiList(text, name, iL);
		}
		if (text[7] == 'd')
		{
			createdList(text, name, dL);
		}
		if (text[7] == 's')
		{
			createsList(text, name, sL);
		}
	}

	if (text[0] == 'p') //for push/pop
	{
		if (name[0] == 'i')
		{
			pInt(text, name,iL);
		}
		if (name[0] == 'd')
		{
			pDouble(text, name, dL);
		}
		if (name[0] == 's')
		{
			pString(text, name, sL);
		}
	}	
}

int main() 
{
	list<SimpleList<int> *> intList; 
	list<SimpleList<double> *> doubleList; 
	list<SimpleList<string> *> stringList; 

	string in; 
	string out; 
	cout << "Enter name of input file: ";   //enter input/output files
	cin >> in;  
	cout << "Enter name of output file: "; 
	cin >> out; 

	inputF.open(in.c_str()); 
	outputF.open(out.c_str()); 

	string text; 
	while (getline(inputF, text)) //reads input line by line
	{
		outputF << "PROCESSING COMMAND: " << text << '\n'; 
		processCommand(text, intList, doubleList, stringList); //calls to process input 
	}

	inputF.close();
	outputF.close(); 
	return 0; 
}