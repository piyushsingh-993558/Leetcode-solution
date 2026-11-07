class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // Free servers: {weight, index}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > freeServers;

        // Busy servers: {freeTime, index}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busyServers;

        queue<pair<int, int>> q;

        // Initially, all servers are free
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        // Store {taskDuration, taskIndex}
        for (int i = 0; i < m; i++) {
            q.push({tasks[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        while (!q.empty()) {

            // Release all servers that have become free
            while (!busyServers.empty() &&
                   busyServers.top().first <= time) {

                auto p = busyServers.top();
                busyServers.pop();

                freeServers.push({servers[p.second], p.second});
            }

            // Wait until the next task arrives
            if (q.front().second > time) {
                time = q.front().second;
                continue;
            }

            // If no server is free, jump to the earliest free time
            if (freeServers.empty()) {
                time = busyServers.top().first;
                continue;
            }

            // Get the next task
            auto task = q.front();
            q.pop();

            int taskTime = task.first;
            int taskIndex = task.second;

            // Get the best available server
            auto server = freeServers.top();
            freeServers.pop();

            int serverIndex = server.second;

            // Assign task to server
            ans[taskIndex] = serverIndex;

            // Server will become free after taskTime
            busyServers.push({
                time + taskTime,
                serverIndex
            });
        }

        return ans;
    }
};