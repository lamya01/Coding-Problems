#include <vector>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> a) {
  // Write your code here.
	int n = a.size();
	// to store sum of seq that ends at ith index
	vector<int> sums = a;
	// to store prev no. in sequence that ends at i
	vector<int> pindx(n, -1);
	// max sum ele indx
	int mindx = 0;
	//int msum = INT_MIN;
	// iterate each ele in array
	for(int i = 0; i < n; ++i)
	{
		// iterate all eles till i-1, and check if smaller that a[i]
		for(int j = 0; j < i; ++j)
		{
			if(a[j] < a[i])
			{
				// find the sum and check if greater that current sum
				if(a[i] + sums[j] >= sums[i])
				{
					// greter then update sum and prev indx
					sums[i] = sums[j] + a[i];
					pindx[i] = j;
				}
			}
			if(sums[i] >= sums[mindx])
			{
				//msum = sums[i];
				mindx = i;
			}
		}
	}
	// get the seq
	int i = mindx;
	vector<int> ans;
	int msum = 0;
	msum = sums[mindx];
	while(i != (int)-1)
	{
		ans.push_back(a[i]);
		
		i = pindx[i];
	}
	reverse(ans.begin(), ans.end());
	return {{msum}, ans};

}
