#include <vector>
using namespace std;

int validStartingCity(vector<int> dist, vector<int> fuel, int mpg) {	
	int n = fuel.size();
	int start = 0;
	int curr = 0;
	int vis = 0;
	int net = 0; 
	while(vis != n)
	{
		net = net + mpg * fuel[curr] - dist[curr];
		++vis;
		
		while(net < 0) // starting point is incorrect, shift it
		{
			net = net - mpg * fuel[start] + dist[start];
			start = (start + 1) % n;
			--vis;
		}
		curr = (curr + 1) % n;
	}
  return start;
}
