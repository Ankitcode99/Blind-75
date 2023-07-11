class Solution {
private:
    pair<int,int> moveRight(int x, int y){
        return {x,y+1};
    }
    pair<int,int> moveDown(int x, int y){
        return {x+1,y};
    }
    pair<int,int> moveLeft(int x,int y){
        return {x,y-1};
    }
    pair<int,int> moveUp(int x, int y){
        return {x-1, y};
    }
    bool isVisited(vector<vector<bool>> &vis,int x, int y){
        return vis[x][y];
    }
    bool isValid(int rows, int cols, pair<int,int> newCell){
        return newCell.first >=0 and newCell.first<rows and newCell.second >=0 and newCell.second <cols;
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int movementType = 1;
        vector<int> ans;
        int rows = matrix.size();
        int col = matrix[0].size();
        int currX=0, currY=0;
        pair<int,int> newCell;
        vector<vector<bool>> vis(rows+1, vector<bool> (col+1,false));
        while(ans.size()!=rows*col){
            switch(movementType){
                case 1: 
                    ans.push_back(matrix[currX][currY]);;
                    vis[currX][currY] = true;
                    newCell = moveRight(currX,currY);
                    if(isValid(rows,col,newCell) and isVisited(vis,newCell.first, newCell.second)==false){
                            currX= newCell.first;
                            currY= newCell.second;
                        }else{
                            movementType=2;
                            newCell = moveDown(currX, currY);
                            currX = newCell.first;
                            currY = newCell.second;
                        }
                    break;
                case 2:
                    ans.push_back(matrix[currX][currY]);
                    vis[currX][currY] = true;
                    newCell = moveDown(currX,currY);
                    if(isValid(rows,col,newCell) and isVisited(vis,newCell.first, newCell.second)==false){
                            currX= newCell.first;
                            currY= newCell.second;
                        }else{
                            movementType=3;
                            newCell = moveLeft(currX, currY);
                            currX = newCell.first;
                            currY = newCell.second;
                        }
                    break;
                case 3:
                    ans.push_back(matrix[currX][currY]);
                    vis[currX][currY] = true;
                    newCell = moveLeft(currX,currY);
                    if(isValid(rows,col,newCell) and isVisited(vis,newCell.first, newCell.second)==false){
                            currX= newCell.first;
                            currY= newCell.second;
                        }else{
                            movementType=4;
                            newCell = moveUp(currX, currY);
                            currX = newCell.first;
                            currY = newCell.second;
                        }
                    break;
                case 4:
                    ans.push_back(matrix[currX][currY]);
                    vis[currX][currY] = true;
                    newCell = moveUp(currX,currY);
                    if(isValid(rows,col,newCell) and isVisited(vis,newCell.first, newCell.second)==false){
                            currX= newCell.first;
                            currY= newCell.second;
                        }else{
                            movementType=1;
                            newCell = moveRight(currX, currY);
                            currX = newCell.first;
                            currY = newCell.second;
                        }
                    break;
                default:;
            }
        }
        return ans;  
    }
};