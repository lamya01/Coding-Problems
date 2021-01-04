#include <iostream>
#include <string>
using namespace std;

int longestBalancedSubstring(string str) {
  int openCount = 0, closeCount = 0;
	int ans = 0;
	for(char c : str)
	{
		if( c == '(')
		{
			++openCount;
		}
		else
		{
			++closeCount;
		}
		if(openCount == closeCount)
		{
			ans = max(ans, closeCount * 2);
		}
		else if(closeCount > openCount)
		{
			closeCount = 0;
			openCount = 0;
		}
	}
	closeCount = 0;
	openCount = 0;
  
	for(int i = str.size() - 1; i >=0; --i)
	{
		char c = str[i];
		if(c == '(')
		{
			++openCount;
		}
		else
		{
			++closeCount;
		}
		if(closeCount == openCount)
		{
			ans = max(ans, openCount * 2);
		}
		else if(openCount > closeCount)
		{
			closeCount = 0;
			openCount = 0;
		}
	}
	return ans;
}