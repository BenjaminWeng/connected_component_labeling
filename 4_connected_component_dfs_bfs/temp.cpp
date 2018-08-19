class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        int n=grid.size();
        int m=grid[0].size();
        
        int i,j,sum;
        sum=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    sum++;
                    bfs(i,j,grid,n,m);
                }
            }
        }
        return sum;
    }
    
    
    void bfs(int x,int y,vector<vector<char>> &grid,int n,int m)
    {
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};
        
        queue<int> q;
        q.push(x*m+y);
        grid[x][y]='0';
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            int xx=cur/m;
            int yy=cur%m;
            
            for (int i=0; i<4; i++)
                if (xx+dx[i]<n&&xx+dx[i]>=0&&yy+dy[i]<m&&yy+dy[i]>=0&&grid[xx+dx[i]][yy+dy[i]]=='1')
                {
                    q.push((xx+dx[i])*m+(yy+dy[i]));
                    grid[xx+dx[i]][yy+dy[i]]='0';
                }
        }
    }

    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<char>> &label, int res)
    {
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};

        if (x<0 || x>=grid.size()) return;
        if (y<0 || y>=grid[0].size()) return;
        if (label[x][y] || grid[x][y]==0) return;

        label[x][y] = res;

        for (int i=0; i<4; i++)
            dfs(x+dx[i], y+dy[i], grid, label, res);
    }

};
