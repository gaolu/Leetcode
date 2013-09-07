class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int numOfRows = matrix.size();
        if(numOfRows <= 0)
            return false;
        int numOfCols = matrix[0].size();
        if(numOfCols <= 0)
            return false;
        int left = 0, right = numOfRows * numOfCols - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(matrix[mid / numOfCols][mid % numOfCols] == target)
                return true;
            else if(matrix[mid / numOfCols][mid % numOfCols] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};