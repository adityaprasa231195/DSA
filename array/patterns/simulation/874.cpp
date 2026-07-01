class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        unordered_set<long long> obs;

        for (auto &v : obstacles) {
            long long key = ((long long)(v[0] + 30000) << 16) | (v[1] + 30000);
            obs.insert(key);
        }

        int dir = 0;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int x = 0, y = 0;
        int ans = 0;

        for (int c : commands) {

            if (c == -1) {
                dir = (dir + 1) % 4;
            }
            else if (c == -2) {
                dir = (dir + 3) % 4;
            }
            else {
                while (c--) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long key = ((long long)(nx + 30000) << 16) | (ny + 30000);

                    if (obs.count(key))
                        break;

                    x = nx;
                    y = ny;
                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};
