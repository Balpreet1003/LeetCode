class Solution {
public:

    int encode(int x, int y, int z)
    {
        return x * 49 + y * 7 + z;
    }

    vector<int> decode(int v)
    {
        return {v / 49, (v / 7) % 7, v % 7};
    }

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        const int INF = 1e9;

        vector<int> dist(343, INF);

        queue<int> q;
        vector<int> active;

        // Initial points
        for (auto &p : points)
        {
            int id = encode(p[0], p[1], p[2]);

            if (dist[id] == 0)
                continue;

            dist[id] = 0;
            q.push(id);
            active.push_back(id);
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            vector<int> a = decode(cur);

            int currentGen = dist[cur];

            int sz = active.size();

            for (int i = 0; i < sz; i++)
            {
                int other = active[i];

                if (other == cur)
                    continue;

                vector<int> b = decode(other);

                int nx = (a[0] + b[0]) / 2;
                int ny = (a[1] + b[1]) / 2;
                int nz = (a[2] + b[2]) / 2;

                int nid = encode(nx, ny, nz);

                int ng = max(dist[cur], dist[other]) + 1;

                if (ng < dist[nid])
                {
                    dist[nid] = ng;

                    q.push(nid);

                    active.push_back(nid);
                }
            }
        }

        int targetId = encode(target[0], target[1], target[2]);

        return dist[targetId] == INF ? -1 : dist[targetId];
    }
};