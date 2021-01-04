#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
};
int f(BinaryTree *node, int &ans)
{
	if(!node)
		return 0;
	int lh = f(node->left, ans);
	int rh = f(node->right, ans);
	ans = max(ans, node->value + lh + rh);
	ans = max(ans, node->value);
	ans = max(ans, node->value + max(lh, rh));
	cout << ans << endl;
	return max(node->value, node->value + max(lh, rh));
}
int maxPathSum(BinaryTree root) {
	BinaryTree *tree = &root;
	int ans = tree->value;
	int output = f(tree, ans);
	
	return max(ans, output);
}
