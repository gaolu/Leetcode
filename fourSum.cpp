class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> result;
        if(num.size() < 4) return result;
        sort(num.begin(), num.end());
        for(int i = 0; i < num.size(); i++){
            if(i > 0 && num[i - 1] == num[i]) continue;
            for(int j = num.size() - 1; j > i; j--){
                if(j != num.size() - 1 && num[j] == num[j + 1]) continue;
                int start = i + 1, end = j - 1;
                while(start < end){
                    int sum = num[i] + num[start] + num[end] + num[j];
                    if(start != i + 1 && num[start] == num[start - 1]) start++;
                    else if(end != j - 1 && num[end] == num[end + 1]) end--;
                    else if(sum > target) end--;
                    else if(sum < target) start++;
                    // found sum == target
                    else{
                        result.resize(result.size() + 1);
                        result.back().push_back(num[i]);
                        result.back().push_back(num[start]);
                        result.back().push_back(num[end]);
                        result.back().push_back(num[j]);
                        start++;
                        end--;
                    } 
                }
            }
        }
        return result;
    }
};
