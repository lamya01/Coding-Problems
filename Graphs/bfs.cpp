#include <vector>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array) {
    // Write your code here.
		Node *start_vertex = this;
		// create q
		// add this node
		unordered_map<string, int>vis;
		queue<Node*>q;
		q.push(start_vertex);
		while(!q.empty())
		{
			Node *curr = q.front();
			q.pop();
			cout << curr->name << " ";
			(*array).push_back(curr->name);
			vis[curr->name] = 1;
			// add all its children
			for(Node *node: curr->children)
			{
				if(vis[node->name] != 1)
				q.push(node);
			}
				
		}
    return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};
