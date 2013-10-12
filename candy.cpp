class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int length = ratings.size();
        if(length <= 0) return 0;
        int sum = length;
        vector<int> candy(length, 0);
        int currCandy = 0;
        for(int i = 1; i < length; i++){
            if(ratings[i - 1] < ratings[i]) currCandy++;
            else currCandy = 0;
            candy[i] = currCandy;
        }
        currCandy = 0;
        for(int i = length - 2; i >=0; i--){
            if(ratings[i] > ratings[i + 1]) currCandy++;
            else currCandy = 0;
            candy[i] = max(candy[i], currCandy);
            sum += candy[i];
        }
        sum += candy[length - 1];
        return sum;
    }
};