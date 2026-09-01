class Solution {
public:

    struct State {
        int i;
        int j;
        int e;
        int mask;
        int dist;
    };

    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();

        int si = 0;
        int sj = 0;

        // Give every L an ID
        vector<vector<int>> id(
            m,
            vector<int>(n, -1)
        );

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'L') {
                    id[i][j] = cnt;
                    cnt++;
                }

                if (classroom[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
            }
        }

        // All litter collected
        int fullMask = (1 << cnt) - 1;

        // best[i][j][mask]
        //
        // Maximum energy with which we have
        // already reached (i,j) with this mask.
        vector<vector<vector<int>>> best(
            m,
            vector<vector<int>>(
                n,
                vector<int>(
                    1 << cnt,
                    -1
                )
            )
        );

        queue<State> q;

        // Starting state
        q.push({
            si,
            sj,
            energy,
            0,
            0
        });

        best[si][sj][0] = energy;

        int di[] = {1, -1, 0, 0};
        int dj[] = {0, 0, -1, 1};

        while (!q.empty()) {

            State cur = q.front();
            q.pop();

            int i = cur.i;
            int j = cur.j;
            int e = cur.e;
            int mask = cur.mask;
            int dist = cur.dist;

            // If all litter collected
            if (mask == fullMask) {
                return dist;
            }

            for (int d = 0; d < 4; d++) {

                int ni = i + di[d];
                int nj = j + dj[d];

                // Boundary
                if (ni < 0 || ni >= m ||
                    nj < 0 || nj >= n) {
                    continue;
                }

                // Wall
                if (classroom[ni][nj] == 'X') {
                    continue;
                }

                // Moving costs 1 energy
                int ne = e - 1;

                // Cannot move if no energy
                if (ne < 0) {
                    continue;
                }

                // Recharge if we enter R
                if (classroom[ni][nj] == 'R') {
                    ne = energy;
                }

                // Collect litter
                int nmask = mask;

                if (classroom[ni][nj] == 'L') {

                    int k = id[ni][nj];

                    nmask = nmask | (1 << k);
                }

                // If we have already reached this
                // position with same mask and MORE energy,
                // this state is useless.
                if (best[ni][nj][nmask] >= ne) {
                    continue;
                }

                // We found a better state
                best[ni][nj][nmask] = ne;

                q.push({
                    ni,
                    nj,
                    ne,
                    nmask,
                    dist + 1
                });
            }
        }

        return -1;
    }
};