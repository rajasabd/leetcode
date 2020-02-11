class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> result;
        
         if(nums1.empty() || nums2.empty())
             return result;
        
         unordered_set<int> table(nums1.begin(), nums1.end());
         for(int i:nums2)
         {
             if(table.erase(i) > 0)
             { 
                 result.push_back(i);
             }
         }
        
        return result;
    }
};