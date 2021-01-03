#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) 
{
  vector<int>temp = array;
	int ans = 0;
	for(int i = 0; i < (int)temp.size(); ++i)
	{
		int curr = temp[i];
		int max_ = curr;
		for(int j = i - 2; j >= 0; --j)
		{
			max_ = max(max_, curr+temp[j]);
		}
		temp[i] = max_;
		ans = max(ans, max_);
	}
  return ans;
}
