class MedianFinder {
private:
    priority_queue<int> maxpq;
    priority_queue<int,vector<int>,greater<int>> minpq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.empty() or maxpq.top() > num) 
            maxpq.push(num);
        else
            minpq.push(num);
        
        if(maxpq.size() > minpq.size() + 1){
            minpq.push(maxpq.top());
            maxpq.pop();
        } else if(minpq.size() > maxpq.size()+1){
            maxpq.push(minpq.top());
            minpq.pop();
        }
        
    }
    
    double findMedian() {
        if(maxpq.size()==minpq.size())
            return ((maxpq.top()+minpq.top())/2.0);
        else if(maxpq.size()>minpq.size())
            return maxpq.top();
        else
            return minpq.top();
    }
};