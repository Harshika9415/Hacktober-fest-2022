class Solution {
public:
   
    int solve(vector<vector<int>>& grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0) return 1;
        if(grid[i][j]==-1) return 0;
        grid[i][j] = -1;
        int ans = 0;
        ans+=solve(grid,i-1,j);
        ans+=solve(grid,i+1,j);
        ans+=solve(grid,i,j - 1);
        ans+=solve(grid,i,j+1);
       
        return ans;
        
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return solve(grid,i,j);
                    
                }
            }
        }
        return 0;
    }
};
