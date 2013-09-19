class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num1.size() == 0 || num2.size() == 0) return NULL;
        int m = num1.size(), n = num2.size();
        int start1 = 0, start2 = 0;
        if(num1[0] == '-') start1 = 1;
        if(num2[0] == '-') start2 = 1;
        bool isNegative = false;
        if((num1[0] == '-' && num2[0] != '-') || (num1[0] != '-' && num2[0] == '-'))
            isNegative = true;
        vector<int> mul(m + n, 0);
        for(int i = m - 1; i >= start1; i--){
            for(int j = n - 1; j >= start2; j--){
                mul[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        int carry = 0;
        for(int i = m + n - 1; i >= 0; i--){
            mul[i] += carry;
            carry = mul[i] / 10;
            mul[i] = mul[i] % 10;
        }
        // construct the string
        string result = "";
        if(isNegative) result += "-";
        bool skipZero = true;
        for(int i = 0; i < m + n; i++){
            if(skipZero && mul[i] == 0 && i != m + n - 1) continue;
            result += to_string(mul[i]);
            skipZero = false;
        }
        return result;
    }
};
