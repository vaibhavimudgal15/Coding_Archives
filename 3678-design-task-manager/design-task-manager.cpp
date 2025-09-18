class TaskManager {
public:
set<pair<int,int>> s;
unordered_map<int,int> m1,m2;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks){
            int a=i[0],b=i[1],c=i[2];
            s.insert({c,b});
            m1[b]=c;m2[b]=a;
        }
    }
    
    void add(int a, int b, int c) {
        s.insert({c,b});
        m1[b]=c;m2[b]=a;
    }
    
    void edit(int b, int c) {
        auto it = s.find({m1[b],b});
        if(it!=s.end()){s.erase(it);}
        s.insert({c,b});m1[b]=c;
    }
    
    void rmv(int b) {
        auto it = s.find({m1[b],b});
        if(it!=s.end()){s.erase(it);}
        m1.erase(b);
    }
    
    int execTop() {
        if(!s.empty()){
        auto it = s.rbegin();auto last = *it;
        int k = m2[last.second];
        s.erase(*it);return k;
        }
        return -1;
    }
};