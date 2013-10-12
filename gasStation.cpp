class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(gas.empty() || cost.empty() || gas.size() != cost.size()) return -1;
        int begin = 0, end = 0, currentPos = 0, gasInCar = 0, numOfStation = gas.size(), n = 0;
        while(n < numOfStation){
            gasInCar += gas[currentPos] - cost[currentPos];
            if(gasInCar >= 0){
                end++;
                currentPos = end;
            }
            else{
                begin--;
                if(begin < 0) begin = numOfStation - 1;
                currentPos = begin;
            }
            n++;
        }
        gasInCar += gas[currentPos] - cost[currentPos];
        return gasInCar >= 0 ? begin : -1;
    }
};