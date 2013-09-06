class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int carry = 0;
        vector<int> afterPlus (digits.size() + 1, 0);
        if(digits.size() == 0)
            return afterPlus;
        reverse(digits.begin(), digits.end());
        int length = digits.size();
        int i = 1;
        int firstSum = digits[0] + 1 + carry;
        carry = firstSum / 10;
        int firstDigit = firstSum % 10;
        afterPlus[0] = firstDigit;
        while(i < length){
            int localSum = digits[i] + carry;
            carry = localSum / 10;
            int localDigit = localSum % 10;
            afterPlus[i] = localDigit;
            i++;
        }
        if(carry > 0)
            afterPlus[afterPlus.size() - 1] = carry;
        if(afterPlus[afterPlus.size() - 1] == 0)
            afterPlus.resize(afterPlus.size() - 1);
        reverse(afterPlus.begin(), afterPlus.end());
        return afterPlus;
    }
};
