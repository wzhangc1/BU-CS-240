#include "Graph.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fin;
	string tempStr;
	vector<string> city;
	
	fin.open(argv[1]);
	
	fin >> tempStr;
	
	while (fin)
	{
		bool match = false;
		
		for (int i = 0; !match && i < static_cast<int>(city.size()); i++)
		{
			if (city[i] == tempStr)
			{
				match = true;
			}
		}

		if (!match)
		{
			city.push_back(tempStr);
		}

		fin >> tempStr;

		match = false;

		for (int i = 0; !match && i < static_cast<int>(city.size()); i++)
		{
			if (city[i] == tempStr)
			{
				match = true;
			}
		}

		if (!match)
		{
			city.push_back(tempStr);
		}

		fin.ignore(100, '\n');

		fin >> tempStr;
	}

	Graph g(city.size(), city);

	fin.clear();
	fin.seekg(0, ios::beg);

	fin >> tempStr;
	
	while (fin)
	{
		Flight tempFlight;
		int i = 0;
		Time time;
		
		while (city[i] != tempStr)
		{
			i++;
		}

		int cityIndex1 = i;

		fin >> tempStr;

		i = 0;

		while (city[i] != tempStr)
		{
			i++;
		}
		
		int cityIndex2 = i;

		fin >> tempStr;
		tempFlight.departureTime = time.timeStrToInt(tempStr);

		fin >> tempStr;
		tempFlight.arrivalTime = time.timeStrToInt(tempStr);
		
		fin >> tempStr;
		tempFlight.cost = stod(tempStr.substr(1));

		g.addEdge(cityIndex1, cityIndex2, tempFlight);

		fin >> tempStr;
	}
	
	cout << fixed << setprecision(2);
	
	do
	{
		cout << "Please select an option" << endl <<"\tCheck" << endl << "\tQuit" << endl;
		
		cin >> tempStr;
		
		if (tempStr != "Quit")
		{
			bool match;
			int arrIdx;
			int depIdx;
			string arr;
			string dep;
			string time;
			Time t;
			
			cout << endl << "From: ";
			cin >> arr;
			
			cout << endl << "To: ";
			cin >> dep;
			
			cout << endl << "Time: ";
			cin >> time;
			
			match = false;
			 
			for (int i = 0; !match && i < city.size(); i++)
			{
				if (city[i] == arr)
				{
					match = true;
					
					arrIdx = i;
				}
			}
			
			match = false;
			
			for (int i = 0; !match && i < city.size(); i++)
			{
				if (city[i] == dep)
				{
					match = true;
					
					depIdx = i;
				}
			}
			
			g.cheapestPath(arrIdx, depIdx);
			
			g.earliestPath(arrIdx, depIdx, t.timeStrToInt(time));
		}
		
	} while (tempStr != "Quit");
	
	fin.close();
	
	return 0;
	
}
