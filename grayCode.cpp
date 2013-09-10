class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> code;
        int count = 1 << n;
        for(int i = 0; i < count; i++){
            code.push_back(i ^ (i >> 1));
        }
        return code;
    }
};