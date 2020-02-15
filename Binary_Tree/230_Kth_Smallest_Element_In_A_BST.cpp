/*
https://leetcode.com/problems/kth-smallest-element-in-a-bst/
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
    int kthSmallest(TreeNode* root, int k) 
    {  
      stack<TreeNode *> Nodes;
      if((NULL == root) || (k < 1 ))
      { 
          return 0;
      }
        
      while( (NULL != root) || 
             (!Nodes.empty())
           )
      {
            while((NULL != root))
            {
                Nodes.push(root);
                root = root->left;
            }
          root = Nodes.top();
          Nodes.pop();
          k--;
          if(k == 0)
          {
              return root->val;
          }
          root = root->right;
      }
        
      return 0;  
    }
};