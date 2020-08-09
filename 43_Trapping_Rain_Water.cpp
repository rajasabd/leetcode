class Solution {
public:
    int trap(vector<int>& height) 
    {   
        int totalAmount   = 0;
        int rightHeightBar = 0;

        if( (height.size() <= 1))
            return totalAmount;
            
        vector<int> LeftHeightBar(height.size() +1,0);
        LeftHeightBar[0] = 0;

        for(int i = 0; i< height.size();i++) 
        {
          LeftHeightBar[i+1] = max(LeftHeightBar[i],height[i]);
        }

        for(int i = height.size()-1; i>=0 ; i--)
        {
            rightHeightBar = max(height[i] ,rightHeightBar);
            totalAmount +=  (min(LeftHeightBar[i] , rightHeightBar) - height[i] > 0 )? (min(LeftHeightBar[i] , rightHeightBar) - height[i] ): 0;
        }   
        
        return totalAmount;
    }
};