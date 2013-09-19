class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string result = "";
        //if(n == 1) return "1";
        helper(result, n);
        return result;
    }
    
    string helper(string &result, int n){
    	// return initial condition
        if(n == 1){
            result = "1";
            return result;
        }
        else{
        	// get previous result
            result = helper(result, n - 1);
            string newResult = "";
            // do the new count again
            for(int i = 0; i < result.size(); ){
                int count = 0;
                char current = result[i];
                while(result[++i] == current) ++count;
                newResult = newResult + to_string(count + 1) + current;
            }
            result = newResult;
            return result;
        }
    }
};