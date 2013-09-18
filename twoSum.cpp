class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> numberSet;
        vector<int> result;
        for(int i = 0; i < numbers.size(); i++){
            // found
            if(numberSet.count(target - numbers[i]) != 0){
                result.push_back(numberSet[target - numbers[i]] + 1);
                result.push_back(i + 1);
            }
            else
                numberSet[numbers[i]] = i;
        }
        return result;
    }
};