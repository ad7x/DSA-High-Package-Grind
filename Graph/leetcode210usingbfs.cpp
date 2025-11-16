#include<iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <limits.h>
#include <stack>
#include<map>
#include <queue>


class Solution {
public:

    map<pair<int,int>,bool> visited;
    

    bool issafe(int newx, int newy, int n, int m, map<pair<int,int>,bool> &visited, vector<vector<char>>& grid){
        if( newx>=0 && newy>=0 && newx<n && newy<m && grid[newx][newy] !='0' && visited[{newx,newy}]==false){
            return true;
        }

        return false;

    }

    void bfs(int i,int j, int n, int m,map<pair<int,int>,bool> &visited, vector<vector<char>>& grid ){

        queue<pair<int,int>> q;

        visited[{i,j}]=true;

        q.push({i,j});

        while(!q.empty()){
            pair<int,int> fpair=q.front();
            q.pop();

            int x=fpair.first;
            int y=fpair.second;

            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};

            for(int k=0; k<4; k++){
                int newx=x+dx[k];
                int newy=y+dy[k];
                if(issafe(newx,newy,n,m,visited,grid)){

                    q.push({newx,newy});
                    visited[{newx,newy}]=true;

                }

            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        
        int count=0;
        int n=grid.size();
        int m= grid[0].size();


        map<pair<int,int>, bool> visited;

        for(int i=0;i<n; i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[{i,j}] && grid[i][j]=='1') 
                {
                    bfs(i,j,n,m,visited,grid);
                    count++;
                }
            }
        }


        return count;
        
    }

   
};


int main(){


    vector<vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','1'}
    };


    Solution s;

    cout<<s.numIslands(grid);






    return 0;
}