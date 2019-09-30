/*
Very easy question, just know how to use to_string
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for(int i = 1;i<=n;++i)
        {
            string temp;
            if(i%3==0 && i%5 ==0)
            {
                temp = "FizzBuzz";
            }

            else if(i%3 == 0)
            {
                temp = "Fizz";
            }
            else if(i%5 == 0)
            {
                temp = "Buzz";
            }
            else
                temp = to_string(i);

            result.emplace_back(temp);
        }
        return result;
    }
};
