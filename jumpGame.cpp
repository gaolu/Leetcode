class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxReach = 1;
        for(int i = 0; i < maxReach && maxReach < n; i++)
        	// get the max distance that can be reach from each node
            maxReach = max(maxReach, A[i] + (i + 1));
        return maxReach >= n;
    }
};