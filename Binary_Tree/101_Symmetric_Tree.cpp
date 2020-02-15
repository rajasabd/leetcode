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
    bool isSymmetric(TreeNode* root) 
    {
     queue<TreeNode *> list;
        TreeNode *t1, *t2;
        
     if(NULL == root)
        return 1;
    
     list.push(root);
     list.push(root);
        
     while(!list.empty())
     {
         t1 = list.front();list.pop();
         t2 = list.front();list.pop();
         if((t1 == NULL) && (t2 == NULL))
         {
             continue;
         }
         else if ((t1 == NULL) || (t2 == NULL))
         {
             return false;
         }
         else if(t1->val != t2->val)
         {
             return false;
         }
         list.push(t1->left);
         list.push(t2->right);
         list.push(t1->right);
         list.push(t2->left);
     }
       return true; 
    }
};