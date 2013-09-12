class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> IPs;
        if(s.size() <= 0)
            return IPs;
        string IP;
        partitionIP(s, 0, 0, IP, IPs);
        return IPs;
    }
    
    void partitionIP(string s, int start, int depth, string IP, vector<string> &IPs){
        if(s.size() - start > 3 * (4 - depth))
            return;
        if(s.size() - start < 4 - depth)
            return;
        
        if(start == s.size() && depth == 4){
            IP.resize(IP.size() - 1);
            IPs.push_back(IP);
            return;
        }
        int currentNum = 0;
        for(int i = start; i < start + 3; i++){
            currentNum = currentNum * 10 + s[i] - '0';
            if(currentNum <= 255){
                IP += s[i];
                partitionIP(s, i + 1, depth + 1, IP + '.', IPs);
            }
            if(currentNum == 0)
                break;
        }
    }
};