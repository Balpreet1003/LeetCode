class TaskManager {
    struct Task {
        int priority, taskId, userId;
    };

    struct cmp {
        bool operator()(const Task& a, const Task& b) const {
            if (a.priority == b.priority)
                return a.taskId > b.taskId;
            return a.priority < b.priority;
        }
    };

    priority_queue<Task, vector<Task>, cmp> tasks_list;
    unordered_map<int, int> trace;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& x : tasks) {
            tasks_list.push({x[2], x[1], x[0]});
            trace[x[1]] = x[2];
        }
    }
    
    void add(int userId, int taskId, int priority) {
        tasks_list.push({priority, taskId, userId});
        trace[taskId] = priority;
    }
    
    void edit(int taskId, int newPriority) {
        trace[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        trace.erase(taskId);
    }
    
    int execTop() {
        while (!tasks_list.empty() &&
              (!trace.count(tasks_list.top().taskId) ||
               trace[tasks_list.top().taskId] != tasks_list.top().priority)) {
            auto x = tasks_list.top();
            tasks_list.pop();
            if (trace.count(x.taskId))
                tasks_list.push({trace[x.taskId], x.taskId, x.userId});
        }

        int ans = tasks_list.top().userId;
        tasks_list.pop();
        return ans;
    }
};