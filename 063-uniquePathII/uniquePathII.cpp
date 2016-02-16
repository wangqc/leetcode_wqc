class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> path(m, vector<int>(n,0));
        path[0][0] = 1;
        int layer = 1;
        while(layer < m+n-1){
            for(int i = 0; i <= layer; i++){
                if(i >= m || layer - i >= n){
                    continue;
                }
                int j = layer - i;
                if(obstacleGrid[i][j]){
                    path[i][j] = 0;
                    continue;
                }
                if(i == 0){
                    path[i][j] = path[i][j-1];
                }
                else if(j == 0){
                    path[i][j] = path[i-1][j];
                }
                else{
                    path[i][j] = path[i][j-1] + path[i-1][j];
                }
            }
            layer++;
        }
        return path[m-1][n-1];
    }
};
