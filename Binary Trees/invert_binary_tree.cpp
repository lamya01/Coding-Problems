#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void preorder(BinaryTree *root)
{
	BinaryTree *temp = root->right;
	root->right = root->left;
	root->left = temp;
	
	if(root->right)
		preorder(root->right);
	if(root->left)
		preorder(root->left);	
}

void invertBinaryTree(BinaryTree *tree) {
  // pre-order traversal
	// swap for each step
	if(!tree)
		return;
	preorder(tree);
	
}
