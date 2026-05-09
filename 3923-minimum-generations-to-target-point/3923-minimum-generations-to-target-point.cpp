#define vi vector
#define ll long long

class Solution {
    ll compress_points(ll x, ll y, ll z)
    {
        return x*49+((y*7))+z;
    }
    vi<ll>get_pnt(ll x)
    {
        return {x/49, (x/7)%7, x%7};
    }
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& t) {
        vi<ll>dist(343, INT_MAX);
        queue<ll>q;
        vi<ll>vis;

        for(auto x:points)
        {
            ll y=compress_points(x[0], x[1], x[2]);
            if(dist[y]==0)
                continue;
            dist[y]=0;
            q.push(y);
            vis.push_back(y);
        }

        while(!q.empty())
        {
            ll x=q.front();
            q.pop();
            auto pnt1=get_pnt(x);
            ll dist1=dist[x];
            ll sz=vis.size();
            for(ll i=0;i<sz;i++)
            {
                ll y=vis[i];
                if(y==x)
                    continue;

                auto pnt2=get_pnt(y);
                ll nx=(pnt1[0]+pnt2[0])/2;
                ll ny=(pnt1[1]+pnt2[1])/2;
                ll nz=(pnt1[2]+pnt2[2])/2;

                ll k=compress_points(nx, ny, nz);
                ll new_dist=max(dist[x], dist[y])+1;

                if(dist[k]>new_dist)
                {
                    dist[k]=new_dist;
                    q.push(k);
                    vis.push_back(k);
                }
            }
        }
        ll tar=compress_points(t[0], t[1], t[2]);
        return dist[tar]==INT_MAX ? -1 : dist[tar];
    }
};