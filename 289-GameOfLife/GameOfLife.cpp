class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> store;
        int row = board.size();
        if(!row){
            return;
        }
        int column = board[0].size();
        vector<vector<int>> bearing = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        for(int i = 0; i < row; i++){
            vector<int> tmp;
            for(int j = 0; j < column; j++){
                tmp.push_back(board[i][j]);
            }
            store.push_back(tmp);
        }
        int countOfOne = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < column; j++){
                countOfOne = 0;
                for(int k = 0; k < 8; k++){
                    int nrow = i + bearing[k][0];
                    int ncol = j + bearing[k][1];
                    if(nrow < 0 || nrow >= row || ncol < 0 || ncol >= column){
                        continue;
                    }
                    if(store[nrow][ncol]){
                        countOfOne++;
                    }
                }
                if(board[i][j]){
                    if(countOfOne < 2 || countOfOne > 3){
                        board[i][j] = 0;
                    }
                }
                else{
                    if(countOfOne == 3){
                        board[i][j] = 1;
                    }
                }
            }
        }
    }
};
