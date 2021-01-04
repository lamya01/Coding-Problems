#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) 
{
 vector<int>t(n+1, 0);
	t[0] = 1;
	for(int coin:denoms)
	{
		for(int i = coin; i < n+1; ++i)
		{
			t[i] += t[i-coin];
		}
	}
	return t[n];
}