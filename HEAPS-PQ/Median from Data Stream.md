# Median from Data Stream


class MedianFinder {
public:
    priority_queue<int> lefthalf;
    priority_queue<int, vector<int>, greater<int>> righthalf;
    MedianFinder() {

    }
    
    void addNum(int num) {
        lefthalf.push(num);
        if(righthalf.size() != 0 && righthalf.top() < lefthalf.top() )
        {
            righthalf.push(lefthalf.top());
            lefthalf.pop();
        }
        if(righthalf.size() > lefthalf.size())
        {
            lefthalf.push(righthalf.top());
            righthalf.pop();
        }
        else if(lefthalf.size() > righthalf.size() + 1)
        {
            righthalf.push(lefthalf.top());
            lefthalf.pop();
        }
        return;
    }
    
    double findMedian() {
        if( (lefthalf.size() + righthalf.size() ) % 2 == 1)
        {
            // odd no of elements
            return lefthalf.top();
        }
        else
        {
            return(
                ((double)lefthalf.top() + 
                (double)righthalf.top())
                /(double)2.0);
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
