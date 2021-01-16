/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getHeightOfTree(TreeNode *root)
    {
        if(!root)
            return -1;
        int height = 0;
        while(root->left)
        {
            ++height;
            root = root->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) 
    {
        if(!root) 
            return 0;
        //if(!root->left && !root->right) 
            //return 1;
        int height_lst = getHeightOfTree(root->left);
        int height_rst = getHeightOfTree(root->right);
        // Case 1: if same height then recurse for rst
        if(height_rst == height_lst)
        {
            return pow(2, height_lst + 1) + countNodes(root->right);
        }
        // Case 2: if heights are different then rst is complete 
        else
        {
            return pow(2, height_rst + 1) + countNodes(root->left);
        }
    }
};