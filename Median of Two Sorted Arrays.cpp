/*
This problem is not difficult, but there are a lot details
to consider. First, divide the problem into two, depending
the total number of two array is even or odd. Then in every
situation, we gradually pick smallest number until we find
the median, but before picking we should always check if
either array is used up.
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int count = 0;
        if((len1+len2) % 2 == 1)//median is a single number
        {
            int dst = (len1+len2)/2 ;
            int mid = 0;
            int idx1= 0, idx2=0;
            while(true)
            {
                if(idx2>=len2 )
                {
                    if(idx1+idx2==dst)
                        return nums1[idx1];
                    idx1++;
                }
                else if(idx1>=len1)
                {
                    if(idx1+idx2==dst)
                        return nums2[idx2];
                    idx2++;
                }
                else if(nums1[idx1]<nums2[idx2])
                {
                    if(idx1+idx2==dst)
                        return nums1[idx1];
                    idx1++;
                }
                else
                {
                    if(idx1+idx2==dst)
                        return nums2[idx2];
                    idx2++;
                }
            }
        }
        else
        {
            int dst = (len1+len2)/2;
            int midl = 0, midr = 0;
            int idx1=0, idx2=0;
            while(true)
            {
                if( idx2>=len2)
                {
                    if(idx1+idx2==dst-1)
                        midl = nums1[idx1];
                    else if(idx1+idx2==dst)
                    {
                        midr = nums1[idx1];
                        return (double(midl)+double(midr))/2;
                    }
                    idx1++;
                }
                else if(idx1>=len1)
                {
                    if(idx1+idx2==dst-1)
                        midl = nums2[idx2];
                    else if(idx1+idx2==dst)
                    {
                        midr = nums2[idx2];
                        return (double(midl)+double(midr))/2;
                    }
                    idx2++;
                }
                else if(nums1[idx1]<nums2[idx2])
                {
                    if(idx1+idx2==dst-1)
                        midl = nums1[idx1];
                    else if(idx1+idx2==dst)
                    {
                        midr = nums1[idx1];
                        return(double(midl)+double(midr))/2;
                    }
                    idx1++;
                }
                else
                {
                    if(idx1+idx2==dst-1)
                        midl = nums2[idx2];
                    else if(idx1+idx2==dst)
                    {
                        midr = nums2[idx2];
                        return (double(midl)+double(midr))/2;
                    }
                    idx2++;
                }
            }
        }
    }
};
