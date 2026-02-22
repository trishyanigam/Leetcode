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
        int curGas=0;
        int st=0;
        for(int i=0;i<gas.size();i++)
        {
            curGas+=gas[i]-cost[i];
            if(curGas<0)
            {
                curGas=0;
                st=i+1;
            }
        }
        return st;
    }
};