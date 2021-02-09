#include <vector>
using namespace std;

vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
  // Write your code here.
	// create a umap (no. -> index)
	// sort the task vector
	// iterate inwards from both ends
	int n = tasks.size();
	unordered_map<int, vector<int>>umap(n);
	for(int i = 0; i < n; ++i)
		umap[tasks[i]].push_back(i);
	sort(tasks.begin(), tasks.end());
	vector<vector<int>>ans(k, vector<int>(2));
	for(int i = 0; i < k; ++i)
	{
		ans[i] = {umap[tasks[i]].back(), umap[tasks[n - 1 - i]].back()};
		umap[tasks[i]].pop_back();
		umap[tasks[n - 1 - i]].pop_back();
	}
  return ans;
}

