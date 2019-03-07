class RecentCounter {
public:
    
    deque<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(v.size() and v.front()< t-3000) v.pop_front();
        v.push_back(t);
        return v.size();
    }
};
