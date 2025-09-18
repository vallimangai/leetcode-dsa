class TaskManager {
public:
    set<pair<int,int>,greater<pair<int,int>>>se;
    map<int,int>task_priority;
    map<int,int>task_user;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto t:tasks){
            se.insert({t[2],t[1]});
            task_priority[t[1]]=t[2];
            task_user[t[1]]=t[0];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        se.insert({priority,taskId});
        task_priority[taskId]=priority;
        task_user[taskId]=userId;
    }
    
    void edit(int taskId, int newPriority) {
        int old= task_priority[taskId];
        se.erase({old,taskId});
        se.insert({newPriority,taskId});
        task_priority[taskId]=newPriority;
    }
    
    void rmv(int taskId) {
         int old= task_priority[taskId];
        se.erase({old,taskId});
    }
    
    int execTop() {
        if(se.size()<=0)
            return -1;
        pair<int,int> pq=*se.begin();
        rmv(pq.second);
        // cout<<pq.second;
        return task_user[pq.second];

    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */