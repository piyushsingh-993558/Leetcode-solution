
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available_servers;

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > busyServers;

        vector<int> countRequests(k, 0);

        for(int i = 0; i < k; i++) {
            available_servers.insert(i);
        }

        for(int i = 0; i < arrival.size(); i++) {

           
            while(!busyServers.empty() &&
                  busyServers.top().first <= arrival[i]) {

                pair<int,int> store = busyServers.top();
                busyServers.pop();

                available_servers.insert(store.second);
            }

          
            int target = i % k;

            auto it = available_servers.lower_bound(target);

         
            if(it == available_servers.end()) {
                if(available_servers.empty()) continue;

                it = available_servers.begin();
            }

           
            int targetServer = *it;

            available_servers.erase(it);

           
            busyServers.push({
                arrival[i] + load[i],
                targetServer
            });

            countRequests[targetServer]++;
        }

       
        vector<int> finalans;

        int maximum = *max_element(
            countRequests.begin(),
            countRequests.end()
        );

        for(int i = 0; i < k; i++) {
            if(countRequests[i] == maximum) {
                finalans.push_back(i);
            }
        }

        return finalans;
    }
};
