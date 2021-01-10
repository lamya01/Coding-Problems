using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};
BinaryTree* getLeftMostNode(BinaryTree *root)
{
	while(root->left)
		root = root->left;
	return root;
}
BinaryTree* getParent(BinaryTree *node)
{
	BinaryTree *par = node->parent;
	while(par && par->left != node)
	{
		par = par->parent;
		node = node->parent;
	}
	return par;
}
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
 if(node->right)
 {
	 BinaryTree *leftmost = getLeftMostNode(node->right);
	 if(leftmost)
		 return leftmost;
	 else
		 return node->right;
 }
 else
 {
	 BinaryTree *par = node->parent;
	 if(!par)
		 return par;
	 if(par->left == node)
		 return par;
	 else
	 {
		 BinaryTree *successor = getParent(node);
		 return successor;
	 }
 }
  
}
