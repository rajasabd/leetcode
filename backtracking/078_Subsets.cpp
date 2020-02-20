/*
class Solution {
private:
    vector<vector<int>> powerset; // stores all subsets
    vector<int> subset; // temporary subset which will be updated as the recursive function executes    
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {        
        backtrack(nums, 0);
        return powerset;
    }

    void backtrack(vector<int>& nums, int start)
    {
        powerset.push_back(subset);
        for(int i = start; i < nums.size(); i++)
        {  
            // recording all subsets that include nums[i]
            subset.push_back(nums[i]);
            backtrack(nums, i+1);
            
            // remove nums[i] from the present subset and move further to explore subsets that don't contain nums[i]
            subset.pop_back();
        }
    }
};

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        powerset.push_back(vector<int>(0));
        
       // printf("powerset %d , nums.size %d \n ",powerset.size(), nums.size());
        // after each iteration of this loop we are left with the powerset of the subset nums[0..i]
        for(int i = 0; i < nums.size(); i++)
        {
            // append nums[i] to already recorded subsets to form new ones.
            for(int j = 0; j < (int)pow(2, i); j++)
            {
                vector<int> subset = powerset[j];
                subset.push_back(nums[i]);
                powerset.push_back(subset);
               // printf("j = %d, (pow 2, i %d) %d, powerset %d \n ", j, i, (int)pow(2, i), powerset.size());
            } 

        }
        
        return powerset;
    }
};
