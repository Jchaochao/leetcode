/*
Idea:
Use divede and conquer to solve this skyline problem.
It is like merge sort, you just have to consider when you get two
parts of skyline then how to merge them. In fact, it is simple. I just
have to scan from left to right, and when we encounter with a height that
is not same as what we already got, the we refresh the final output.
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())
          return buildings;
        return divideAndConquer(buildings,0,buildings.size()-1);

    }
private:
    vector<vector<int>> divideAndConquer(auto buildings, int leftEnd, int rightEnd)
    {
        vector<vector<int>> result;

        if(rightEnd > leftEnd)//There are more than one building in the set
        {
            //Divide into two group and get the result
            int mid = (leftEnd + rightEnd) / 2;
            auto left = divideAndConquer(buildings,leftEnd,mid);
            auto right = divideAndConquer(buildings, mid+1, rightEnd);

            //Merge two parts
            int countLeft = left.size();
            int countRight = right.size();
            int i = 0 , j = 0 ;
            int heightLeft = 0, heightRight = 0;
            vector<int>temp;
            //loop until all elements in two parts merged
            while(i < countLeft && j < countRight )
            {
                if(left[i][0]<right[j][0])
                {
                    heightLeft = left[i][1];
                    if(result.empty() || result.back()[1] !=  max(heightLeft,heightRight))
                    {
                        temp = {left[i][0],max(heightLeft,heightRight)};
                        result.emplace_back(temp);
                    }
                    i++;
                }
                else if(left[i][0]>right[j][0])
                {
                    heightRight = right[j][1];
                    if(result.empty() || result.back()[1] !=  max(heightLeft,heightRight))
                    {
                        temp = {right[j][0],max(heightLeft,heightRight)};
                        result.emplace_back(temp);
                    }
                    j++;
                }
                else
                {
                    heightLeft = left[i][1];
                    heightRight = right[j][1];
                    if(result.empty() || result.back()[1] !=  max(heightLeft,heightRight))
                    {
                        temp = {right[j][0],max(heightLeft,heightRight)};
                        result.emplace_back(temp);
                    }
                    i++;
                    j++;
                }
            }
            while(i<countLeft)
            {
                result.emplace_back(left[i]);
                i++;
            }
            while(j<countRight)
            {
                result.emplace_back(right[j]);
                j++;
            }

        }
        else//There is only one building in the set
        {
            vector<int>leftPtr = {buildings[leftEnd][0],buildings[leftEnd][2]};
            vector<int>rightPtr = {buildings[leftEnd][1], 0};
            result.emplace_back(leftPtr);
            result.emplace_back(rightPtr);

        }
        return result;
    }
};
