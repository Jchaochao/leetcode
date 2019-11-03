class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int past = 0;
        std::map<char, int> my_map = {  { 'I', 1 },
                                        { 'V', 5 },
                                        { 'X', 10 },
                                        { 'L', 50 },
                                        { 'C', 100 },
                                        { 'D', 500 },
                                        { 'M', 1000}};
        for(auto it = s.begin(); it < s.end(); ++it) {
            int currVal = my_map[*it];
            if (currVal > past) {
                total -= past;
                currVal = currVal - past;
            }
            total += currVal;
            past = currVal;
        }
        return total;

    }
};
