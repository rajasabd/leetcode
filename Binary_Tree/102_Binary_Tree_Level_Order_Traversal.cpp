/*
Let’s play a game of 2 queues. We keep 2 queues for even and odd levels of the tree. 
So starting with 0th level i.e root, initialize even queue with root. 
Now imagine holding the even queue in your right hand and the odd queue in your left 
( just 2 boxes which allow entry from only one side and exit from the opposite side).

1.Tilt your right hand so all the contents of even queue start falling out. 
2.Whenever a node falls out of a queue push it’s children into the other queue.
3.Now tilt your left hand emptying contents of odd queue and adding kids of falling out nodes into even queue.
4.Repeat until both queues are empty.
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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> even;
        queue<TreeNode*> odd;
        vector<vector<int>> result;
        
        even.push(root);
        
        while(!even.empty() || !odd.empty())
        {
            vector<int> level;
           
            if(odd.empty()){
                // while even not empty, transfer kids of falling out nodes to odd 
                while(!even.empty())
                {
                    TreeNode* curr = even.front(); even.pop();
                   
                    if(curr){
                        level.push_back(curr->val);
                        
                        odd.push(curr->left);
                        odd.push(curr->right);
                    }
                }
            }
            else if(even.empty()){
                // if even is empty, transfer kids of falling out nodes to even | keep juggling 
                while(!odd.empty())
                {
                    TreeNode* curr = odd.front(); odd.pop();
                   
                    if(curr){
                        level.push_back(curr->val);
                        
                        even.push(curr->left);
                        even.push(curr->right);
                    }
                }
            }
            
            result.push_back(level);
        }
        result.pop_back();
        return result;
    }
};