class Solution {
private:
    bool isValid(int newX, int newY, int rowCount, int colCount){
        return (newX>=0 and newX<rowCount and newY>=0 and newY<colCount);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int row[] = {-1,0,1,0};
        int col[] = {0,-1,0,1};
        int rowCount = grid.size(), columnCount = grid[0].size();
        // vector<vector<int>> vis(rowCount, vector<int> (columnCount, 0));
        queue<pair<int,int>> q;
        for(int i=0;i<rowCount;i++){
            for(int j=0;j<columnCount;j++){

                if(grid[i][j]=='1'){
                    count++;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(q.size()){
                        auto node = q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nx = node.first + row[k];
                            int ny = node.second + col[k];

                            if(isValid(nx, ny, rowCount, columnCount) && grid[nx][ny]=='1'){
                                q.push({nx,ny});
                                grid[nx][ny]='0';
                            }
                        }
                    }
                }

            }
        }
        return count;
    }
};