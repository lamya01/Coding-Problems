#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int>&a,  vector<int>&vis)
{
	cout << i << " " << endl;
	if(find(vis.begin(), vis.end(), i) != vis.end())
	{
		vis.push_back(i);
		return;
	}
		
	vis.push_back(i);
	int n = a.size();
	int ans = (i+a[i])%n;
	
	
	ans = (ans<0)? ans+n : ans;
	
	dfs(ans, a, vis);
}

bool hasSingleCycle(vector<int> array) {
	
	int n = array.size();
	vector<int>vis;
	for(int i = 0; i < n; ++i)
	{
		vis.clear();
		dfs(i, array, vis);
		/*if((int)vis.size() == n)
			return true;
			*/
		// if last pushed = i && size is n+1 then true
		int last = vis.back();
		int size = vis.size()-1;
		if(size == n && last == i)
		{
			return true;
		}
		
	}
  return false;
}
