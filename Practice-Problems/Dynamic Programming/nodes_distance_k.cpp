using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// find nodes at level k below root
void findNodes(BinaryTree *root, int k, vector<int> &ans)
{
	// when k = 0 node reached
	if(!root) return;
	if(k == 0 && root)
	{
		ans.push_back(root->value);
	}
	else
	{
		findNodes(root->left, k - 1, ans);
		findNodes(root->right, k - 1, ans);
	}
}

void findTarget(BinaryTree *node, int &target, int &k, int &i, vector<int> &ans)
{
	if(!node) return;
	if(node->value == target)
	{
		findNodes(node, k, ans);
	}
	else
	{
		// explore lst
		findTarget(node->left,...);
		// if found in lst find neighbours at dist k
		if(flag)
			findNodes(node->right, k, ans);
		else
		{
			// explore rst
			findTarget(node->right, ...);
			if(flag)
			{
				// if target found in rst find neighbours in lst 
				findNodes(node->left, k, ans);
			}
		}	
	}
	if(flag)
		--k;
}

vector<int> findNodesDistanceK(BinaryTree *root, int target, int k) {
  
	vector<int> ans;
	findTarget(root, target, k, ans);
  return ans;
}
