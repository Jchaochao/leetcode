class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int result = 0 ;
        for(int i =0; i< len-1;++i)
        {
            int temp = prices[i+1]-prices[i];
            if(temp>0)
                result+=temp;
        }
        return result;
    }
};
