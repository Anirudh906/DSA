class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> q;
    priority_queue<int, vector<int>, greater<int>> s;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q.size() > s.size()){
            
             if(!q.empty() and q.top() > num){
                      s.push(q.top());
                      q.pop();
                      q.push(num);
             }
            else s.push(num);
        }
        else{
            if(!q.empty() and num <= q.top()){
                   q.push(num);
             }else{

             s.push(num);
                q.push(s.top());
                s.pop();
            }
        }
    }
    
    double findMedian() {

        if(q.size() > s.size()){
             return (double)(q.top());
        }else{
            return (double)(q.top() + s.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */