class RecentCounter {
public:
    queue<int> pings;
    
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push(t);
        while( t - pings.front() > 3000  ) pings.pop();
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
