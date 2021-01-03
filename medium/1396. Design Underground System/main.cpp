class UndergroundSystem {
public:
    // id -> out, time
    // in,out -> double, count
    
    // average = sum/count
    // average*count+newtime/count+1
    // average*count/(count+1) + newtime/count+1 
    
    unordered_map<int,pair<string,int>> mp;
    unordered_map<string, pair<double,int>> p;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, -t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto[s,t1] = mp[id];
        mp.erase(id);
        string built = s+", "+stationName;
        auto&[av,cnt] = p[built];
        
        t +=t1;
        av = (av/(cnt+1))*cnt+((double)t/(cnt+1));
        cnt++;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string built = startStation+", "+endStation;
        return p[built].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

