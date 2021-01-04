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
vector<int> f(BinaryTree *root, int &sum)
{
	if(!root) return {0,0};
	vector<int> L = f(root->left, sum);
	vector<int> R = f(root->right, sum);
	
	cout << "n and depth sum : " << L[0] + R[0] + 1 << " " << L[0] + L[1] + R[0] + R[1] << endl;
	sum += L[0] + L[1] + R[0] + R[1];
	return {L[0] + R[0] + 1, L[0] + L[1] + R[0] + R[1]};
}
int allKindsOfNodeDepths(BinaryTree *root) {
  
	if(!root)
  return -1;
	int sum = 0;
	vector<int> ans = f(root, sum);
	cout << sum << endl;
	return sum;
}