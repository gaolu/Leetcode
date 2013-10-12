class Solution {
public:
    int singleNumber(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int ones = 0, twos = 0, threes = 0;
        for(int i = 0; i < n; i++){
        	// twos contain which bit came across twice
        	// ones contain which bit came across once
        	// if both set then three times then clear it
            twos |= (ones & A[i]);
            ones ^= A[i];
            threes = ~(twos & ones);
            ones &= threes;
            twos &= threes;
        }
        return ones;
    }
};