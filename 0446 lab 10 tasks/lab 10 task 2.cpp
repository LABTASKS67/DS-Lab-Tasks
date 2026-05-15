#include<iostream>
#include<string>
using namespace std;
bool palindroma(const string& str, int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	if (str[start] != str[end])
	{
		return false;
	}
	return palindroma(str, start + 1, end - 1);
}

int main()
{
	string given = "blolb";
	if (palindroma(given, 0, given.length() - 1))
	{
		cout << "this string is palindrome;\n";
	}
	else
	{
		cout << "no palindrome;\n";
	}
	return 0;
}