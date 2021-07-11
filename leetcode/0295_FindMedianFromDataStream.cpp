class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> left, mid, right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mid.size()){
            if(num <= *mid.begin()){
                left.insert(num);
                num = *left.rbegin();
                left.erase( left.find(num) );
            }else if(num >= *mid.rbegin() ){
                right.insert(num);
                num = *right.begin();
                right.erase(right.find(num));
            }    
            
        }
        
        mid.insert(num);
        if(mid.size()==3){
            left.insert( *mid.begin() );
            mid.erase( mid.begin() );
            
            right.insert( *mid.rbegin() );
            mid.erase( mid.find(*mid.rbegin()) );
        }
    }
    
    double findMedian() {
        if(mid.size()==0) return 0.0;
        double sum = 0;
        for(int value:mid) sum += value;
        return sum/(mid.size());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
