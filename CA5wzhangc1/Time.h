#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class Time
{
public:
	int timeStrToInt(string str);
	string timeIntToStr(int time);
};
