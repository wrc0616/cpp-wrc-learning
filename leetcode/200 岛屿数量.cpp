//深度优先算法
class Solution {
public:
    void mydbs(vector<vector<char>>& grid,int i,int j,int &row,int &col)
    {
        if( i<0||
            j<0||
            i>=row||
            j>=col||
            grid[i][j]=='0'
        )
        {
            return;
        }
        grid[i][j]='0';
        mydbs(grid,i+1,j,row,col);
        mydbs(grid,i-1,j,row,col);
        mydbs(grid,i,j+1,row,col);
        mydbs(grid,i,j-1,row,col);
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
         int row=grid.size();
         int col =grid[0].size();
         int nums=0;
         for (int i=0;i<row;i++)
         {
             for(int j=0;j<col;j++)
             {
                 if(grid[i][j]=='1')
                 {
                     nums++;
                     mydbs(grid,i,j,row,col);
                 }
             }
         }
         return nums;

    }
};

//广度优先算法
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
        queue<pair<int,int>> q;
        int row=grid.size();
        int col =grid[0].size();
        int nums=0;
        for (int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    nums++;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty())
                    {
                        auto cur=q.front();
                        q.pop();
                        int x=cur.first;
                        int y = cur.second;
                        if(x-1>=0&&grid[x-1][y]=='1')
                        {
                            grid[x-1][y]=0;
                            q.push({x-1,y});
                        }
                        if(x+1<row&&grid[x+1][y]=='1')
                        {
                            grid[x+1][y]=0;
                            q.push({x+1,y});
                        }
                        if(y-1>=0&&grid[x][y-1]=='1')
                        {
                            grid[x][y-1]=0;
                            q.push({x,y-1});
                        }
                        if(y+1<col&&grid[x][y+1]=='1')
                        {
                            grid[x][y+1]=0;
                            q.push({x,y+1});
                        }
                    }
                }
            }
        }
        return nums;

    }
};

//同化法
class UnionFind{
public:
    vector<int> root;
    int count=0;
    UnionFind(vector<vector<char>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        count = row*col;
        root.resize(row * col);
        for(int i = 0;i<row*col;i++)
        {
            root[i]=i;
        }
    }
    int find(int x)
    {
        if(x==root[x])
        {
            return x;
        }
        else
        {
            root[x] = find(root[x]);
            return root[x];
        }
    }
    void unite(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if(rootx!=rooty)
        {
            root[rootx]=rooty;
            count--;
        }
    }
    int getcount(){
        return count;
    }

};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
         if(grid.empty())
         {
             return 0;
         }
        int row = grid.size();
        int col = grid[0].size();
        int waters=0;
        UnionFind uf(grid);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='0')
                {
                    waters++;
                }
                else
                {
                    vector<vector<int>> d={{0,1},{0,-1},{1,0},{-1,0}};
                    for(auto a:d)
                    {
                        int x=i+a[0];
                        int y =j+a[1];
                        if(x>=0&&x<row&&y>=0&&y<col&&grid[x][y]=='1')
                        {
                            uf.unite(x*col+y,i*col+j);
                        }
                    }
                }
            }
        }
        return uf.getcount()-waters;
    }
};


