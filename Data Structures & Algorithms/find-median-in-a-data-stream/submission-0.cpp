class MedianFinder {
    priority_queue<int> smallele;
    priority_queue<int,vector<int>,greater<int>> largeele;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        smallele.push(num);
        if(!(largeele.empty()) && smallele.top()>largeele.top()){
            largeele.push(smallele.top());
            smallele.pop();
        }
        if(smallele.size()>largeele.size()+1){
            largeele.push(smallele.top());
            smallele.pop();
        }
        if(largeele.size()>smallele.size()+1){
            smallele.push(largeele.top());
            largeele.pop();   
        }
    }
    
    double findMedian() {
        if(smallele.size()==largeele.size()){
            return (largeele.top()+smallele.top())/2.0;
        } else if (smallele.size()>largeele.size()){
            return smallele.top();
        }else{
            return largeele.top();
        }
    }
};
