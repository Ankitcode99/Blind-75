class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = rows;
        
        for(int row=0; row<rows; row++) {
            for(int col=row; col<cols; col++) {
                swap(matrix[row][col],matrix[col][row]);
            }
        }
        
        for(int row=0;row<rows;row++){
            int left=0, right = cols-1;
            while(left<right){
                swap(matrix[row][left],matrix[row][right]);
                left++,right--;
            }
        }
    }
};