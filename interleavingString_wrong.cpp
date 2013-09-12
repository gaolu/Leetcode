class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s1.size() + s2.size() != s3.size())
            return false;
        int s1Index = 0, s2Index = 0, s3Index = 0;
        for(int i = 0; i < s3.size(); i++){
            // s1 done
            if(s1Index >= s1.size()){
                if(s2[s2Index] != s3[i])
                    return false;
                s2Index++;
            }
            // s2 done
            else if(s2Index >= s2.size()){
                if(s1[s1Index] != s3[i])
                    return false;
                s1Index++;
            }
            // none of s1 or s2 done
            else{
                if(s1[s1Index] == s3[i] && s2[s2Index] != s3[i]){
                    s1Index++;
                }
                else if(s1[s1Index] != s3[i] && s2[s2Index] == s3[i]){
                    s2Index++;
                }
                else if(s1[s1Index] == s3[i] && s2[s2Index] == s3[i]){
                    if(s1Index > s2Index)
                        s2Index++;
                    else if(s1Index < s2Index)
                        s1Index++;
                    else
                        s1Index++;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
