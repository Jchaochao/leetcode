class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector<int> dicNum = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<std::string>dicStr = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int idx = 0;
        while(num>0)
        {
            if(num>=dicNum[idx])
            {
                result += dicStr[idx];
                num -= dicNum[idx];
            }
            else
            {
                idx++;
            }

        }
        return result;
    }
};
