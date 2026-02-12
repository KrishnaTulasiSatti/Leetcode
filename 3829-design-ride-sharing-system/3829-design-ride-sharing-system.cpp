class RideSharingSystem {
public:

    queue<int>rider;
    queue<int>driver;

    vector<int>cancel;
    vector<int>vis;
    
    RideSharingSystem() {
        cancel.resize(1001,0);
        vis.resize(1001,0);
    }
    
    void addRider(int riderId) {
        vis[riderId] = 1;
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && cancel[rider.front()] == 1) rider.pop();

        if(!driver.empty() && !rider.empty()) {
            auto tr = rider.front();
            auto td = driver.front();
            rider.pop();
            driver.pop();
            return {td,tr};
        }
        
        return {-1,-1};
    }
    
    void cancelRider(int riderId) {
        if(vis[riderId]) cancel[riderId] = 1;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */