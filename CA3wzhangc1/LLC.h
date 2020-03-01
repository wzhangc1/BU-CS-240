#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h> 

using namespace std;

struct Node
{
	string data;
	struct Node *next;
};

class LLC
{
public:
	Node* first;
	Node* last;
	
public:
	LLC(void);
	LLC(const LLC& aLLC);
	LLC& operator=(const LLC &aLLC);
	~LLC(void);
	bool contains(const string& aString);
	void insert(const string& aString);
	void remove(const string& aString);
	void shuffle(void);
	LLC operator+(const LLC& llc);
	void head(int n);
	string tail(void);
	friend ostream& operator<<(ostream &out, const LLC& llc);
	void operator+=(int n);
	int len(void);
	void join(const LLC& other);
};
