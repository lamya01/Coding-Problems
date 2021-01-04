#include <vector>
using namespace std;

class TrieNode
{
	public:
	unordered_map<char, TrieNode*>children;
	string word;
	
};


class Trie
{
	public:
	TrieNode* root;
	
	char endSymbol;
	void add(string);
	
	Trie();
};

Trie::Trie()
{
	this->root = new TrieNode();
	this->endSymbol = '*';
}

void Trie::add(string word)
{
	TrieNode *node = this->root;
	for(char letter : word)
	{
		if(node->children.find(letter) == node->children.end())
		{
			TrieNode *newNode = new TrieNode();
			node->children.insert({letter, newNode});
		}
		node = node->children[letter];
		
	}
	node->children.insert({this->endSymbol, NULL});
	node->word = word;
}
bool isValid(int i, int j, vector<vector<char>> &board)
{
	int rows = board.size();
	int cols = board[0].size();
	if(i >= 0 && i < cols && j >= 0 && j < rows)
		return true;
	return false;
}
vector<vector<int>> getNeighs(int i, int j, vector<vector<char>> &board)
{
	vector<vector<int>>neighs;
	vector<int> x = {i - 1, i - 1, i + 1, i + 1, i - 1, i + 1, i, i};
	vector<int> y = {j - 1, j + 1, j + 1, j - 1, j, j, j - 1, j + 1};
	for(int k = 0; k < 8; ++k)
	{
		if(isValid(x[k], y[k], board))
			neighs.push_back({x[k], y[k]});
	}
	return neighs;
}

void explore(int i, int j, vector<vector<char>> &board, TrieNode *root, vector<
						vector<bool>> &vis, unordered_set<string> &ans)
{
	if(vis[i][j])
		return;
	char letter = board[i][j];
	if(root->children.find(letter) == root->children.end())
		return;
	vis[i][j] = true;
	root = root->children[letter];
	if(root->children.find('*') != root->children.end())
	{
		ans.insert(root->word);
	}
	vector<vector<int>> neighs = getNeighs(i, j, board);
	for(auto neigh : neighs)
	{
		explore(neigh[0], neigh[1], board, root, vis, ans);
	}
	vis[i][j] = false;
}



vector<string> boggleBoard(vector<vector<char>> board, vector<string> words) {
  // Write your code here.
	Trie trie;
	for(string word : words)
	{
		trie.add(word);
	}
	int rows = board.size();
	int cols = board[0].size();
	unordered_set<string> ans;
	vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
  for(int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			explore(i, j, board, trie.root, vis, ans);
		}
	}
	vector<string> ans1(ans.begin(), ans.end());
	
	return ans1;
}
