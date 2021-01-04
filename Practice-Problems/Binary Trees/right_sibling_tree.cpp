#include <vector>
using namespace std;

// This is the class of the input root. Do not edit it.
class BinaryTree {
public:
  int value;
  BinaryTree *left = NULL;
  BinaryTree *right = NULL;

  BinaryTree(int value);
};
void print_(queue<BinaryTree*>q)
{
	while(!q.empty())
	{
		cout << q.front()->value << " ";
		q.pop();
	}
	cout << endl;
	
}
void f(BinaryTree *root, BinaryTree *par, int isR)
{
	if(!root) return;
	
	BinaryTree *lt = root->left;
	BinaryTree *rt = root->right;
	
	f(lt, root, 0); //left
	if(isR == 1) //rc
	{
		if(par->right == NULL)
			root->right = NULL;
		else 
			root->right = par->right->left;
	}
	else if(isR == 0) //lc
	{
		root->right = par->right;
	}
	else
	{
		root->right = NULL;
	}
	f(rt, root, 1);
}

BinaryTree *rightSiblingTree(BinaryTree *root) {
  f(root, NULL, 2);
  return root;
}
