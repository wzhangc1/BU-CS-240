#include "Graph.h"

Graph::Graph(int V, vector<string> aCity)
{
	this->V = V;
	
	adj = new list< pair<int, Flight> >[V];

	city = aCity;
}

void Graph::addEdge(int u, int v, Flight w)
{
	adj[u].push_back(make_pair(v, w));
}

void Graph::printPath(vector<int> pre, vector<Flight> flight, int src, int i)
{
	Time time;
	
	if (i != src)
	{
		int j = pre[i];

		if (j != src)
		{
			printPath(pre, flight, src, j);
		}
	}
	
	cout << setw(20) << city[i] << setw(10) << 
		time.timeIntToStr(flight[i].departureTime) << setw(10) << 
		time.timeIntToStr(flight[i].arrivalTime) << setw(9) <<
		flight[i].cost << '$' << endl;
}

void Graph::cheapestPath(int src, int dst)
{
	set< pair<int, int> > setds;

	vector<double> dist(V, INF);

	setds.insert(make_pair(0, src));
	dist[src] = 0;
	vector<Flight> flight(V);
	vector<int> pre(V, -1);

	while (!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		list< pair<int, Flight> >::iterator i;
		
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			
			double weight = (*i).second.cost;

			if (dist[v] > dist[u] + weight)
			{
				if (dist[v] != INF)
				{
					setds.erase(setds.find(make_pair(static_cast<int>(dist[v]), v)));
				}

				dist[v] = dist[u] + weight;
				flight[v] = (*i).second;
				pre[v] = u;
				setds.insert(make_pair(static_cast<int>(dist[v]), v));
			}
		}
	}

	if (pre[dst] > 0)
	{
		cout << endl << "Cheapest Path:" << endl << setw(20) << "City" 
			<< setw(10) << "Dep Time" << setw(10) << "Arr Time" << 
			setw(10) << "Cost" << endl;
		
		printPath(pre, flight, src, dst);
	}
	else
	{
		cout << "ERROR - Path does not exist" << endl;
	}
}

void Graph::earliestPath(int src, int dst, int time)
{
	set< pair<int, int> > setds;

	vector<int> dist(V, INF);

	setds.insert(make_pair(0, src));
	dist[src] = time;
	vector<Flight> flight(V);
	vector<int> pre(V, -1);

	int day = 0;
	
	while (!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;
		
		list< pair<int, Flight> >::iterator i;
		
		for (i = adj[u].begin(); i != adj[u].end(); ++i)
		{
			int v = (*i).first;
			
			if ((*i).second.departureTime <= dist[u])
			{
				day++;
			}
			
			int weight = (*i).second.arrivalTime - dist[u] + day * 1440;

			if (dist[v] > dist[u] + weight)
			{
				if (dist[v] != INF)
				{
					setds.erase(setds.find(make_pair(dist[v], v)));
				}

				dist[v] = dist[u] + weight;
				flight[v] = (*i).second;
				pre[v] = u;
				setds.insert(make_pair(dist[v], v));
			}
		}
	}
		
	if (pre[dst] > 0)
	{
		cout << endl << "Earliest Path:" << endl << setw(20) << "City" 
			<< setw(10) << "Dep Time" << setw(10) << "Arr Time" << 
			setw(10) << "Cost" << endl;

		printPath(pre, flight, src, dst);
	}
	else
	{
		cout << "ERROR - Path does not exist" << endl;
	}
}
