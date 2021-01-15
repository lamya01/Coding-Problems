
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int levenshteinDistance(string a, string b) 
{
	int r = b.size() + 1;
	int c = a.size() + 1;
 	vector<vector<int>> table(r, vector<int>(c, 0));
	/*for(int i = 0; i < r; ++i)
		table[i][0] = i;
	for(int j = 0; j < c; ++j)
		table[0][j] = j;*/
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			table[i][j] = j;
		}
		table[i][0] = i;
	}z
	
	for(int i = 1; i < r; ++i)
		for(int j = 1; j < c; ++j)
		{
			//table[i][j] = j;
			if(a[j - 1] != b[i - 1])
			{
				table[i][j] = 1 + min(table[i - 1][j - 1], 
												min(table[j - 1][i], table[i - 1][j]));
			}
			else
				table[i][j] = table[i - 1][j - 1];
		}
	
  return table[r-1][c-1];
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << levenshteinDistance(a, b) << endl; 
}
