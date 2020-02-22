
/*

Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]

*/

class Solution {
private:
    vector<int> combination;
    vector<vector<int>> combinations;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        explore(candidates, 0, target);
        return combinations;
    }

    void explore(vector<int>& candidates, int start, int target)
    {
        if(target == 0)
        {
            combinations.push_back(combination); // yes! a valid solution found
            return;
        }    
        
        if(target < 0) return; // this is when we lose hope and backtrack :(

        for(int i = start; i < candidates.size(); i++)
        {
            if((i > start) && (candidates[i] == candidates[i-1]))
                continue;
            // explore all solutions using candidates[i] at least once
            combination.push_back(candidates[i]);
            explore(candidates, i+1, target - candidates[i]);
            
            // explore solutions that don't use candidates[i]
            combination.pop_back();
        }
    }
};
