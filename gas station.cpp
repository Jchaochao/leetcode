class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        int total = 0;
        int index = -1;
        for(int i = 0; i < n ; ++i)
        {
            gas[i]-=cost[i];
            total+=gas[i];
            cout<<gas[i]<<" ";
        }
        if(total<0)
            return -1;
        for(int i = 0; i<n ; ++i)
        {
            sum += gas[i];
            if(sum<0)
            {
                sum = 0;
                index = i;
            }
        }
        return index+1;
    }
};
