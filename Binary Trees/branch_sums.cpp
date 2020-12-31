using namespace std;

// This is the class of the input root. Do not edit it.

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = NULL;
    right = NULL;
  }
};
void dfs(BinaryTree *root, int sum, vector<int>&ans)
{
	sum += root->value;
	
	if(!root->left && !root->right)
	{
		ans.push_back(sum);
		cout << sum << endl;
		return;
	}
	if(root->left)
	{
		dfs(root->left, sum, ans);
	}
	if(root->right)
	{
		dfs(root->right, sum, ans);
	}
}
vector<int> branchSums(BinaryTree *root) {
 vector<int>ans;
	if(!root) return {};
	dfs(root, 0, ans);
	for(int n: ans)
		cout << n << endl;
	
  return ans;
}
