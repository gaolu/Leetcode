class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(a.size() == 0)
            return b;
        if(b.size() == 0)
            return a;
        int aSize = a.size() - 1;
        int bSize = b.size() - 1;
        int carry = 0;
        string sum = "";
        while(aSize >= 0 || bSize >= 0 || carry > 0){
            int localSum = 0;
            if(aSize >= 0)
                localSum += a[aSize] - '0';
            if(bSize >= 0)
                localSum += b[bSize] - '0';
            localSum += carry;
            carry = localSum / 2;
            localSum %= 2;
            sum = string(1, (localSum + '0')) + sum;
            aSize--;
            bSize--;
        }
        return sum;
        
    }
};
