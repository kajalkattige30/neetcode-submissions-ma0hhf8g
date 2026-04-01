class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();      //rows
        int n = matrix[0].size();   //columns

        int left = 0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;
        int dir = 0;

        /*
            dir0 : left to right
            dir1 : top to bottom
            dir2 : right to left
            dir3 : bottom to top
        */

        while(top <= bottom && left <= right) {
            if(dir == 0) {
                for(int i = left; i <= right; i++) {
                    result.push_back(matrix[top][i]);
                }
                top++;
            }
            if(dir == 1) {
                for(int i = top; i <= bottom; i++) {
                    result.push_back(matrix[i][right]);
                }
                right--;
            }
            if(dir == 2) {
                for(int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(dir == 3) {
                for(int i = bottom; i>= top; i--) {
                    result.push_back(matrix[i][left]);
                }
                left++;
            }

            dir++;
            if(dir == 4) dir = 0;
        }
        return result;
    }
};
