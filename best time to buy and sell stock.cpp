class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(len<=1)
            return 0;
        vector<int> high(len,0);
        int templow = prices[0];
        int temphigh = prices[len-1];
        for(int j = len -1; j>=0;--j)
        {
            temphigh=max(temphigh,prices[j]);
            high[j]= temphigh;
        }
        temphigh = 0;
        for(int i = 0;i<len;++i)
        {
            templow= min(templow,prices[i]);
            if(high[i]-templow>temphigh)
                temphigh = high[i] - templow;
        }

        return temphigh;
    }
};
