#include "LLC.h"

using namespace std;

int main(int argc, char *argv[])
{
	LLC llc;
	LLC llc1;
	LLC llc2;
	
	llc.insert("A");
	llc.insert("B");
	llc.insert("C");
	llc.insert("D");
	llc.insert("E");
	
	cout << "LLC:  " << llc << endl;
	
	llc1 = LLC(llc);
	
	cout << "LLC1: " << llc1 << endl;
	
	llc2 = llc;
	
	cout << "LLC2: " << llc2 << endl;
	
	if (llc.contains("A"))
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
	
	if (llc.contains("F"))
	{
		cout << "TRUE" << endl;
	}
	else
	{
		cout << "FALSE" << endl;
	}
	
	llc.insert("1");
	llc.insert("2");
	llc.insert("3");
	llc.insert("4");
	llc.insert("5");
	
	cout << "LLC:  " << llc << endl;
	
	llc.remove("A");
	llc.remove("E");
	llc.remove("1");
	llc.remove("5");
	
	cout << "LLC:  " << llc << endl;
	
	llc.shuffle();
	
	cout << "LLC:  " << llc << endl;
	
	llc = llc + llc1;
	
	cout << "LLC:  " << llc << endl;
	
	llc.head(0);
	cout << endl;
	llc.head(5);
	cout << endl;
	llc.head(15);
	cout << endl;
	
	if (llc.tail() == llc.last->data)
	{
		cout << " TRUE" << endl;
	}
	else
	{
		cout << " FALSE" << endl;
	}
	
	llc += 3;
	
	cout << "LLC:  " << llc << endl;
	
	cout << llc.len() << endl;
	
	llc.join(llc2);
	
	cout << "LLC:  " << llc << endl;
	
	return 0;
}
