#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;
  BinaryTree *parent;

  BinaryTree(int value, BinaryTree *parent = NULL);
  void insert(vector<int> values, int i = 0);
};
void setPointer(BinaryTree *root)
{
	BinaryTree *curr = root->left;
	// get the right most node
	while(curr->right != nullptr)
	{
		curr = curr->right;
	}
	curr->right = root;	
}
int vis(BinaryTree *node, unordered_map<BinaryTree*, int> &umap)
{
	if(umap[node] == 1)
		return true;
	return false;	
}
void iterativeInOrderTraversal(BinaryTree *tree,
                               void (*callback)(BinaryTree *tree)) 
{
	BinaryTree *curr = tree;
	unordered_map<BinaryTree*, int>umap;
	while(curr)
	{
	if(curr->left && !vis(curr->left, umap))
	{
		cout << "has left" << " " << curr->value << endl;
		
		setPointer(curr);
		
		// mark as visited
		umap[curr->left] = 1;
		curr = curr->left;
		
	}
	else
	{
		callback(curr);
		cout << curr->value << endl;
		curr = curr->right;
	}
	}
}
