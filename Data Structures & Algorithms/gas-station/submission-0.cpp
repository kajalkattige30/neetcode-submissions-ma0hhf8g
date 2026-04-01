class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0;
        int totCost = 0;
        int startIndex = 0;
        int currGas = 0;

        for(int i = 0; i < gas.size(); i++) {
            totGas += gas[i];
            totCost += cost[i];

            currGas += gas[i] - cost[i];

            if(currGas < 0) {
                startIndex = i + 1;
                currGas = 0;
            }
        }
        if(totGas < totCost) return -1;
        return startIndex;
    }
};
