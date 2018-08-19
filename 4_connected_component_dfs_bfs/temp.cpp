class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
            return 0;
        
        vector<vector<int>> label(grid.size(), vector<char>(grid[0].size(), 0));
        int res = 0;

        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1' && !label[i][j])
                    bfs(i,j,grid, label, ++res);

        //print labels
        for(int i=0;i<label.size();i++)
        {
            for(int j=0;j<label[0].size();j++)
            {
                if (label[i][j] == 0)
                    cout <<"x";
                else
                    cout << label[i][j];
            }
            cout<<"\n";
        }

        return res;
    }    
    
    void bfs(int x,int y,vector<vector<char>> &grid, vector<vector<int>> &label, int res)
    {
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};
        int m=grid.size();
        int n=grid[0].size();
        
        queue<int> q;
        q.push(x*n+y);
        label[x][y] = res;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            int xx = cur/n, yy = cur%n;
            
            for (int i=0; i<4; i++)
                if (xx+dx[i]>=0 && xx+dx[i]<m && yy+dy[i]>=0 && yy+dy[i]<n &&
                    grid[xx+dx[i]][yy+dy[i]]=='1' && !label[xx+dx[i]][yy+dy[i]])
                {
                    q.push((xx+dx[i])*n + yy+dy[i]);
                    label[xx+dx[i]][yy+dy[i]] = res;
                }
        }
    }

    void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<int>> &label, int res)
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
