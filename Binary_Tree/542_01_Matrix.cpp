class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) 
    {
        queue<vector<int>> bfs;
        int dist = 0;
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0) bfs.push(vector<int>({i, j}));    // keep track of all 0's 
                else matrix[i][j] = INT_MAX;                            // else initialize distance to infinity 
            }
        }
        
        vector<vector<int>> directions({{1,0}, {-1, 0}, {0, 1}, {0, -1}});
        
        while(!bfs.empty())
        {
            vector<int> current = bfs.front(); 
            bfs.pop();
            
            for(auto d : directions)
            {
                int i = current[0] + d[0];
                int j = current[1] + d[1];
                
                // if new cell is out of bounds or is already closer to another 0, stop further bfs in this cell  
                if((i >= 0 && i <= (m - 1)) && 
                   (j >= 0 && j <= (n - 1) ) && 
                   (matrix[i][j] > matrix[current[0]][current[1]] + 1) )
                 {
                     bfs.push(vector<int>({i, j}));                     // put in queue for further bfs operations
                     matrix[i][j] = matrix[current[0]][current[1]] + 1; // update new smaller distance
                 }
            }
        }
        
        return matrix;
    }
};