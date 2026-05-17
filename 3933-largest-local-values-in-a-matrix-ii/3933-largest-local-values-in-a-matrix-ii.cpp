class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        vector<vector<pair<int, int>>>arr(201);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr[matrix[i][j]].push_back({i, j});
            }
        }
        

        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                    continue;
                bool flag=true;

                for(int val=matrix[i][j]+1; val<201 && flag; val++)
                {
                    for(auto [x, y]:arr[val])
                    {
                        int x1=abs(x-i); 
                        int y1=abs(y-j);

                        if(x1<=matrix[i][j] && y1<=matrix[i][j])
                        {
                            if(x1==matrix[i][j] && y1==matrix[i][j])
                                continue;
                            
                            flag=false;
                            break;
                        }
                    }
                }
                
                if(flag)
                    ans++;
            }
        }
        return ans;
    }
};