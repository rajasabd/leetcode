/*

Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.
The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]

Notice that we’ll have to explore many cases and there is no “smart” way to avoid that, 
the only smart thing we could do is to stop exploring a case as soon as we know it won’t lead 
to the solution and so this is a backtracking problem.
The solution is entirely same as subsets solution, only with a slight modification that
we have a constraint included: the sum of the final collected combination 
should equal target.

*/

class Solution 
{
private:
    vector<int> combination;
    vector<vector<int>> combinations;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
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
            // explore all solutions using candidates[i] at least once
            combination.push_back(candidates[i]);
            explore(candidates, i, target - candidates[i]);
            
            // explore solutions that don't use candidates[i]
            combination.pop_back();
        }
    }
};