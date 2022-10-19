class Solution {
public:
    
    void bfs(vector<vector<int>>& image,int i,int j,int newColor,int sourcecolor){
        int n = image.size();
        int m = image[0].size();
        if(i<0 || i>=n || j<0 || j>=m || image[i][j]!=sourcecolor || image[i][j]==newColor){
            return;
        }
        image[i][j] = newColor;
        bfs(image,i-1,j,newColor,sourcecolor);
        bfs(image,i+1,j,newColor,sourcecolor);
        bfs(image,i,j-1,newColor,sourcecolor);
        bfs(image,i,j+1,newColor,sourcecolor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        bfs(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};
