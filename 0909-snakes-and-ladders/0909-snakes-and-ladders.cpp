class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> visited(n * n + 1, 0);
        queue<pair<int, int>> q;
        q.push({1, 0});
        visited[1] = 1;

        while (!q.empty()) {
            auto [s, moves] = q.front();
            q.pop();
            if (s == n * n) return moves;
            
            for (int i = 1; i <= 6; ++i) {
                int next = s + i;
                if (next > n * n) continue;
                auto [r, c] = getCoordinates(next, n);
                if (board[r][c] != -1)
                    next = board[r][c];
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }

    pair<int, int> getCoordinates(int s, int n) {
        int r = n - (s - 1) / n - 1;
        int c = (s - 1) % n;
        if ((n - r) % 2 == 0)
            c = n - 1 - c;
        return {r, c};
    }
};