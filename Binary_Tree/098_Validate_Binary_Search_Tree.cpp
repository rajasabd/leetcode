/*
https://leetcode.com/problems/validate-binary-search-tree/
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

/* recursive approach
class Solution {
public:
    bool validBST(TreeNode *root,long int *prev)
    {
        if(NULL == root) return 1;
        if(!validBST(root->left,prev))
            return 0;
        if(root->val <= *prev)
            return 0;
        *prev = root->val;
        return validBST(root->right,prev);
    }
    
    bool isValidBST(TreeNode* root) 
    {
        long int min = LONG_MIN;
        return validBST(root,&min);
    }
};

*/

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
      stack<TreeNode *> Nodes;
      TreeNode* Prev = NULL;
        
      if(NULL == root) 
      { 
          return 1;
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
          if((NULL != Prev) && (root->val <= Prev->val))
          {
              return 0;
          }
          Prev = root;
          root = root->right;
      }
      return 1;
    }
};