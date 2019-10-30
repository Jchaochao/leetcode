class MedianFinder {
public:
    /** initialize your data structure here. */

    MedianFinder() {
        large.push(numeric_limits<int>::max());
        small.push(numeric_limits<int>::min());
    }

    void addNum(int num) {
        if(num>large.top())
            large.push(num);
        else
            small.push(num);
        int temp;
        if (large.size() > small.size() + 1)
        {
            temp = large.top();
            large.pop();
            small.push(temp);
        }
        else if (small.size() > large.size() + 1)
        {
            temp = small.top();
            small.pop();
            large.push(temp);
        }
    }

    double findMedian() {
        if(large.size()==1&&small.size()==1)
            return 0;
        else if(large.size()==small.size())
            return (double(large.top())+double(small.top()))/2;
        else if (large.size() > small.size()) {
            return large.top();
        } else {
            return small.top();
        }

    }
private:
    priority_queue<int>small;
    priority_queue<int,vector<int>,std::greater<int>>large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
