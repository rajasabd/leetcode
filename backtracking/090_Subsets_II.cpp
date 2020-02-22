/*
class Solution {
public:
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> powerset ;                
        sort(nums.begin(), nums.end());
        
        powerset.push_back(vector<int>(0));
        
        for(int i = 0; i <nums.size();i++)
        {
            for(int j = 0; j< pow(2,i); j++)
            {
                if ((j > 1) && (powerset[pow(2,j)] == powerset[pow(2,j-1)]))
                    continue;
                vector<int> subset = powerset[j];
                subset.push_back(nums[i]);
                powerset.push_back(subset);
            }
        }
     return powerset;
    }
    
    
};
*/

/*
    Same problem with the added constraint that the set may contain duplicates but the output power 
    set should not contain duplicate subsets.
    Approach: Sort the given array beforehand and skip over duplicates while backtracking, 
    essentially a simple 2 line change in the previous solution.
*/

class Solution {
private:
    vector<vector<int>> powerset;
    vector<int> subset;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end()); //change 1
        backtrack(nums, 0);
        return powerset;
    }
    
    void backtrack(vector<int>& nums, int start)
    {
        powerset.push_back(subset);
        for(int i = start; i < nums.size(); i++)
        {
            if(i > start && nums[i] == nums[i-1]) continue; //change 2, skip over duplicates
            subset.push_back(nums[i]);
            backtrack(nums, i+1);
            subset.pop_back();
        }
    }
};