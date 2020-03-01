#include "LLC.h"

LLC::LLC(void)
{
	first = NULL;
	last = NULL;
}

LLC::LLC(const LLC& aLLC)
{
	Node *ptr;
	
	ptr = aLLC.first;
	
	while (ptr != NULL)
	{
		insert(ptr->data);
		ptr = ptr->next;
	}
}

LLC& LLC::operator=(const LLC& aLLC)
{
	Node *ptr (*Node)malloc(sizeof(Node));
	
	while (first != NULL)
	{
		ptr = first->next;
		
		delete first;
		
		first = ptr;
	}
	
	ptr = aLLC.first;
	
	while (ptr != NULL)
	{
		insert(ptr->data);
		
		ptr = ptr->next;
	}
	
	return *this;
}

LLC::~LLC(void)
{
	Node *ptr;
	
	while (first != NULL)
	{
		ptr = first->next;
		delete first;
		first = ptr;
	}
}

bool LLC::contains(const string& aString)
{
	bool match;
	Node *ptr;
	
	match = false;
	ptr = first;
	
	while (!match && ptr != NULL)
	{
		if (ptr->data == aString)
		{
			match = true;
		}
		
		ptr = ptr->next;
	}
	
	return match;
}

void LLC::insert(const string& aString)
{
	Node *ptr;
	
	ptr = new Node();
	
	ptr->data = aString;
	
	ptr->next = NULL;
	
	if (first == NULL)
	{
		first = ptr;
		
		last = ptr;
	}
	else
	{
		last->next = ptr;
		
		last = last->next;
	}
}

void LLC::remove(const string& aString)
{
	Node *prev;
	Node *ptr;
	
	if (first != NULL)
	{
		while (first->data == aString)
		{
			ptr = first->next;
		
			delete first;
		
			first = ptr;
		}
	}
	
	if (first != NULL)
	{
		prev = first;
		ptr = first->next;
		
		while (ptr != NULL)
		{
			if (ptr->data == aString)
			{
				prev->next = ptr->next;
				
				delete ptr;
				
				ptr = prev->next;
			}
			else
			{
				prev = ptr;
				
				ptr = ptr->next;
			}
		}
		
		if (prev->next == NULL)
		{
			last = prev;
		}
	}
}

void LLC::shuffle(void)
{
	int i;
	int j;
	int length;
	int ran;
	Node *prev;
	Node *ptr;
	
	srand(time(NULL));
	
	length = len();
	
	for (i = 0; i < length * length; i++)
	{
		ran = rand() % length;
		
		ptr = first;
		
		if (ran > 0)
		{
			for (j = 0; j < ran; j++)
			{
				prev = ptr;
				
				ptr = ptr->next;
			}
			
			insert(ptr->data);
			
			prev->next = ptr->next;
		}
		else
		{
			insert(ptr->data);
			
			first = first->next;
		}
		
		delete ptr;
	}
}

LLC LLC::operator+(const LLC& llc)
{
	Node *ptr;
	LLC temp;
	
	while (first != NULL)
	{
		temp.insert(first->data);
		
		ptr = first->next;
		
		delete first;
		
		first = ptr;
	}
	
	ptr = llc.first;
	
	while (ptr != NULL)
	{
		temp.insert(ptr->data);
		
		ptr = ptr->next;
	}
	
	return temp;
}

void LLC::head(int n)
{
	int i;
	Node *ptr;
		
	if (first != NULL)
	{
		i = 0;
		
		ptr = first;
		
		cout << '[';
		
		while (i < n && ptr != NULL)
		{
			cout << ptr->data;
			
			if (i + 1 < n && ptr->next != NULL)
			{
				cout << ", ";
			}
			
			i++;
			
			ptr = ptr->next;
		}
		
		cout << ']';
	}
}

string LLC::tail(void)
{
	cout << last->data;
	
	return last->data;
}

ostream& operator<<(ostream &out, const LLC& llc)
{
	Node *ptr;
	
	ptr = llc.first;
	
	out << '[';
	
	while (ptr != NULL)
	{
		out << ptr->data;
		
		if (ptr->next != NULL)
		{
			out << ", ";
		}
		
		ptr = ptr->next;
	}
	
	out << ']';
	
	return out;
}

void LLC::operator+=(int n)
{
	int i;
	Node *ptr;
	
	if (first != NULL)
	{
		for (i = 0; i < n; i++)
		{
			ptr = first;
			
			while (ptr->next != last)
			{
				ptr = ptr->next;
			}
			
			last->next = first;
			
			first = last;
			
			last = ptr;
			
			last->next = NULL;
		}
	}
}

int LLC::len(void)
{
	int i;
	Node *ptr;
	
	i = 0;
	
	if (first != NULL)
	{
		ptr = first;
		
		while (ptr != NULL)
		{
			ptr = ptr->next;
			
			i++;
		}
	}
	
	return i;
}

void LLC::join(const LLC& other)
{
	Node* ptr;
	
	if (other.first != NULL)
	{		
		ptr = other.first;
		
		while (ptr != NULL)
		{
			insert(ptr->data);
			
			ptr = ptr->next;
		}
	}
}
