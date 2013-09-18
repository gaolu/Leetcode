class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() < 3) return INT_MAX;
        sort(num.begin(), num.end());
        int closestSum = num[0] + num[1] + num[2];
        for(int i = 0; i < num.size() - 2; i++){
            int start = i + 1, end = num.size() - 1;
            while(start < end){
                int sum = num[i] + num[start] + num[end];
                if(abs(sum - target) < abs(closestSum - target)) closestSum = sum;
                if(sum == target) return sum;
                else if(sum < target) start++;
                else end--;
            }
        }
        return closestSum;
        
    }
};
