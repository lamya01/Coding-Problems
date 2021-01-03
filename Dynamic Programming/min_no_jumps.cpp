#include <vector>
using namespace std;

void f(vector<int>&a, int i, int jumps, int &min_jumps){
	// reached end 
	if(i >= (int)a.size()-1){
		cout << jumps << endl;
		min_jumps = min(min_jumps, jumps);
		return;
	}
	
	// not end
	for(int j = 1; j <= a[i]; ++j)
	{
		f(a, i+j, jumps+1, min_jumps);
	}
}


int minNumberOfJumps(vector<int> array) 
{
  // Write your code here.
	// call helper fn
	int min_jumps = INT_MAX;
	f(array, 0, 0, min_jumps);
	
  return min_jumps;
}
