
class Solution {
public:
    unordered_map<int, int> days;

    void fillMap(unordered_map<int, int>& start,
                 unordered_map<int, int>& finish,
                 string arrive, string leave) {

        int arriveMonth = stoi(string(arrive.begin(), arrive.begin() + 2));
        int arriveDay = stoi(string(arrive.begin() + 3, arrive.end()));

        int leaveMonth = stoi(string(leave.begin(), leave.begin() + 2));
        int leaveDay = stoi(string(leave.begin() + 3, leave.end()));

        for (int i = arriveMonth; i <= leaveMonth; i++) {
            start[i] = (i == arriveMonth) ? arriveDay : 1;
            finish[i] = (i == leaveMonth) ? leaveDay : days[i];
        }
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        days[1] = 31;
        days[2] = 28;
        days[3] = 31;
        days[4] = 30;
        days[5] = 31;
        days[6] = 30;
        days[7] = 31;
        days[8] = 31;
        days[9] = 30;
        days[10] = 31;
        days[11] = 30;
        days[12] = 31;

        unordered_map<int, int> aliceStart, aliceFinish;
        unordered_map<int, int> bobStart, bobFinish;

        fillMap(aliceStart, aliceFinish, arriveAlice, leaveAlice);
        fillMap(bobStart, bobFinish, arriveBob, leaveBob);

        int ans = 0;

        for (auto it : aliceStart) {
            int month = it.first;

            if (bobStart.find(month) != bobStart.end()) {
                int start = max(aliceStart[month], bobStart[month]);
                int finish = min(aliceFinish[month], bobFinish[month]);

                if (start <= finish) {
                    ans += finish - start + 1;
                }
            }
        }

        return ans;
    }
};
