/*
https://leetcode.com/problems/binary-tree-inorder-traversal/
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
      vector<int> inorder;
      stack<TreeNode *> Nodes;
        
      if(NULL == root) 
      { 
          return inorder;
      }
        
      while((NULL != root) || (!Nodes.empty()))
      {
            while((NULL != root))
            {
                Nodes.push(root);
                root = root->left;
            }
          root = Nodes.top();
          Nodes.pop();
          inorder.push_back(root->val);
          root = root->right;
      }
        
      return inorder;
    }
};