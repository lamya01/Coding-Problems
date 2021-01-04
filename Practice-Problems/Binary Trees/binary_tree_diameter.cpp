using namespace std;

// This is an input class. Do not edit.
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

int f(BinaryTree *node, int &ans)
{
	if(!node)
		return 0;
	int lh = f(node->left, ans);
	int rh = f(node->right, ans);
	ans = max(ans, lh + rh);
	cout << ans << endl;
	return 1 + max(lh, rh);
}
int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
	if(!tree)
  	return -1;
	int ans = 0;
	f(tree, ans);
	return ans;
}