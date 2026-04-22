class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas=0;
        int totCost=0;
        for(int g:gas)
        {
            totGas+=g;
        }
        for(int c:cost)
        {
            totCost+=c;
        }
        if(totGas<totCost)
        {
            return -1;
        }
        int st=0;
        int currGas=0;
        for(int i=0;i<gas.size();i++)
        {
            currGas+=gas[i]-cost[i];
            if(currGas<0)
            {
                currGas=0;
                st=i+1;
            }
        }
        return st;
    }
};