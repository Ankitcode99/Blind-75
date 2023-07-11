class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        bool firstRow = false;
        for(int col = 0; col < cols ; col++){
            if(matrix[0][col]==0){
                firstRow = true;
                break;
            }
        }
        
        for(int row = 1;row < rows;row++){
            for(int col=0;col<cols;col++){
                if(matrix[row][col]==0){
                    matrix[0][col] = 0;
                }
            }
        }
        
        for(int row=1; row<rows; row++){
            bool containsZero = false;
            
            for(int col=0;col<cols;col++){
                if(matrix[row][col]==0){
                    containsZero = true;
                    break;
                }
            }
            
            for(int col=0;col<cols;col++){
                if(containsZero==true || matrix[0][col]==0){
                    matrix[row][col]=0;
                }
            }
        }
        
        if(firstRow){
            for(int col=0;col<cols;col++){
                matrix[0][col]=0;
            }
        }
    }
};