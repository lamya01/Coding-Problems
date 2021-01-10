#include <vector>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
 
	vector<int>val(n + 1, INT_MAX);
	val[0] = 0;
	
	for(int i = 1; i < n + 1; ++i)
	{
		for(int d: denoms)
		{
			if(i >= d)
			{
				if(val[i - d] != INT_MAX)
					val[i] = min(val[i], 1 + val[i - d]);
			}
		}
	}
	return val[n] != INT_MAX ? val[n] : -1;	
}
