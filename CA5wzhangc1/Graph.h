#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <set>
#include <vector>
#include "Time.h"

using namespace std;

#define INF 0x3f3f3f3f

struct Flight 
{
	int departureTime;
	int arrivalTime;
	double cost;
};

class Graph
{
public:
	int V;
	
	vector<string> city;

	list< pair<int, Flight> > *adj;

public:
	Graph(int V, vector<string> aCity);
	
	void addEdge(int u, int v, Flight w);

	void cheapestPath(int s, int d);

	void earliestPath(int s, int d, int t);

	void printPath(vector<int> pre, vector<Flight> flight, int src, int idx);
};
