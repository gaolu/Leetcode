class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> parenthesis;
        int length = s.size();
        if(length % 2) return false;
        for(int i = 0; i < length; i++){
        	// push in left parenthesis
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') parenthesis.push(s[i]);
            // right parenthesis must appear after left and if found pair then pop out
            else if(!parenthesis.empty() && ((s[i] == ')' && parenthesis.top() == '(') ||
                    (s[i] == '}' && parenthesis.top() == '{') || 
                    (s[i] == ']' && parenthesis.top() == '[')))
                    parenthesis.pop();
            // right parenthesis appears when stack is empty
            else return false;
        }
        return parenthesis.empty();
    }
};
