class Router {
public:
    typedef pair<int,pair<int,int>> pip;
    queue<pip> q;
    set<pip> ust;
    unordered_map< int,pair<int,vector<int> > > mp;
    int maxp;
    Router(int memoryLimit) {
        maxp=memoryLimit;
       
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(ust.find({source,{destination,timestamp}})!=ust.end()) {
            return false;
        }
        else {
            q.push({source,{destination,timestamp}});
            mp[destination].second.push_back(timestamp);
            ust.insert({source,{destination,timestamp}});
            if(q.size()>maxp) {
                pip temp=q.front();q.pop();
               mp[temp.second.first].first++;
                ust.erase(temp);
            }
            return true;
        }
    }
    
    vector<int> forwardPacket() {
        vector<int> ans;
        if(!q.empty()) {
            pip t=q.front();q.pop();
            mp[t.second.first].first++;
            ans.push_back(t.first);
            ans.push_back(t.second.first);
            ans.push_back(t.second.second);
            ust.erase(t);
        }
        return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int pos=mp[destination].first;
          return upper_bound(mp[destination].second.begin()+pos,mp[destination].second.end(),endTime)-lower_bound(
            mp[destination].second.begin()+pos,mp[destination].second.end(),startTime
        );
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */