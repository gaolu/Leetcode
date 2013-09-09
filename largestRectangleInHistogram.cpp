class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<int> S;
        height.push_back(0);
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            if(S.empty() || height[i] >= height[S.top()])
                S.push(i);
            else{
                int peak = S.top();
                S.pop();
                sum = max(sum, height[peak] * (S.empty() ? i : i - S.top() - 1));
                i--;
            }
        }
        return sum;
    }
};