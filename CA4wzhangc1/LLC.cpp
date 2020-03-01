#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

template <typename T>
struct Node
{
	T data;
	struct Node *next;
};

template <typename T>
class LLC
{
public:
	Node<T>* first;
	Node<T>* last;
	
public:
	LLC(void);
	LLC(const LLC<T> &aLLC);
	LLC& operator=(const LLC& aLLC);
	~LLC(void);
	bool contains(const T& var);
	void insert(const T& var);
	void remove(const T& var);
	void shuffle(void);
	LLC operator+(const LLC& llc);
	void head(int n);
	T tail(void);
	void operator+=(int n);
	int len(void);
	void join(const LLC& other);
	
	template<typename U>
	friend ostream& operator<<(ostream &out, const LLC<U>& llc);
};

template <typename T>
LLC<T>::LLC(void)
{
	first = NULL;
	last = NULL;
}

template <typename T>
LLC<T>::LLC(const LLC<T> &aLLC)
{
	Node<T> *ptr;
	
	ptr = aLLC.first;
	
	while (ptr != NULL)
	{
		insert(ptr->data);
		ptr = ptr->next;
	}
}

template <typename T>
LLC<T>& LLC<T>::operator=(const LLC& aLLC)
{
	Node<T> *ptr;
	
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

template <typename T>
LLC<T>::~LLC(void)
{
	Node<T> *ptr;
	
	while (first != NULL)
	{
		ptr = first->next;
		delete first;
		first = ptr;
	}
}

template <typename T>
bool LLC<T>::contains(const T& var)
{
	bool match;
	Node<T> *ptr;
	
	match = false;
	ptr = first;
	
	while (!match && ptr != NULL)
	{
		if (ptr->data == var)
		{
			match = true;
		}
		
		ptr = ptr->next;
	}
	
	return match;
}

template <typename T>
void LLC<T>::insert(const T& var)
{
	Node<T> *ptr;
	
	ptr = new Node<T>();
	
	ptr->data = var;
	
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

template <typename T>
void LLC<T>::remove(const T& var)
{
	Node<T> *prev;
	Node<T> *ptr;
	
	if (first != NULL)
	{
		while (first->data == var)
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
			if (ptr->data == var)
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

template <typename T>
void LLC<T>::shuffle(void)
{
	int i;
	int j;
	int length;
	int ran;
	Node<T> *prev;
	Node<T> *ptr;
	
	length = len();
	
	srand(time(NULL));
	
	for (i = 0; i < (length * (length - 1)) / 2; i++)
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

template <typename T>
LLC<T> LLC<T>::operator+(const LLC& llc)
{
	Node<T> *ptr;
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

template <typename T>
void LLC<T>::head(int n)
{
	int i;
	Node<T> *ptr;
		
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

template <typename T>
T LLC<T>::tail(void)
{
	cout << last->data;
	
	return last->data;
}

template <typename T>
void LLC<T>::operator+=(int n)
{
	int i;
	Node<T> *ptr;
	
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

template <typename T>
int LLC<T>::len(void)
{
	int i;
	Node<T> *ptr;
	
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

template <typename T>
void LLC<T>::join(const LLC& other)
{
	Node<T> *ptr;
	
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

template <typename T>
ostream& operator<<(ostream &out, const LLC<T>& llc)
{
	Node<T>*ptr;
	
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
