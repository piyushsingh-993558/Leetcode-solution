class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > freeServers;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > busyServers;

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        for(int i = 0; i < m; i++) {
            q.push({tasks[i], i});
        }

        vector<int> ans(m);

        long long time = 0;

        while(!q.empty()) {

            // Release all free servers
            while(!busyServers.empty() &&
                  busyServers.top().first <= time) {

                auto p = busyServers.top();
                busyServers.pop();

                freeServers.push({servers[p.second], p.second});
            }

            // Task has not arrived yet
            if(q.front().second > time) {

                time = q.front().second;
                continue;
            }

            // No free server: jump to next free time
            if(freeServers.empty()) {

                time = busyServers.top().first;
                continue;
            }

            // Assign task
            auto task = q.front();
            q.pop();

            auto server = freeServers.top();
            freeServers.pop();

            int taskTime = task.first;
            int taskIndex = task.second;

            int serverIndex = server.second;

            ans[taskIndex] = serverIndex;

            busyServers.push({
                time + taskTime,
                serverIndex
            });
        }

        return ans;
    }
};