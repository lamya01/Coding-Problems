using namespace std;

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

void dfs(BinaryTree *node, int &sum, int depth)
{
	sum += depth;
	if(node->left)
	{
		dfs(node->left, sum, depth+1);
	}
	if(node->right)
	{
		dfs(node->right, sum, depth+1);
	}	 
}
int nodeDepths(BinaryTree *root) {
	if(!root) return -1;
	int sum = 0;
	
  dfs(root, sum, 0);
  return sum;
}