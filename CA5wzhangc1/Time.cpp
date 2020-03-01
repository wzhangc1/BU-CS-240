#include "Time.h"

int Time::timeStrToInt(string str)
{
	int time;

	int hrs = stoi(str.substr(0, 2));
	int min = stoi(str.substr(3, 2));

	if (str.substr(5, 2) == "pm")
	{
		if (hrs == 12)
		{
			time = 60 * hrs + min;
		}
		else
		{
			time = 720 + 60 * hrs + min;
		}
	}
	else
	{
		if (hrs == 12)
		{
			time = min;
		}
		else
		{
			time = 60 * hrs + min;
		}
	}

	return time;
}

string Time::timeIntToStr(int time)
{
	ostringstream ss;
	string str;

	int hrs = time / 60;
	int min = time % 60;

	if (hrs > 12)
	{
		ss << setfill('0') << setw(2) << hrs - 12 << ":" << setfill('0') << setw(2) << min << "pm";
	}
	else if (hrs == 12)
	{
		ss << 12 << ":" << setfill('0') << setw(2) << min << "pm";
	}
	else if (hrs > 0)
	{
		ss << setfill('0') << setw(2) << hrs << ":" << setfill('0') << setw(2) << min << "am";
	}
	else
	{
		ss << 12 << ":" << setfill('0') << setw(2) << min << "am";
	}
	
	return ss.str();
}
