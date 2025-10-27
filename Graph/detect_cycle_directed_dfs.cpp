#include<iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include<vector>

class Solution {
  public:
    unordered_map<int,list<int>> adjlst;
    
    bool checkcycledfs(int src,unordered_map<int,bool> &visited, unordered_map<int,bool> &pvisited){
        visited[src]=true;
        pvisited[src]=true;
        
        for(auto nbr:adjlst[src]){
            if(!visited[nbr]) checkcycledfs(nbr,visited,pvisited);
            
            if(visited[nbr] && pvisited[nbr]) return true;
        }
        
        pvisited[src]=false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjlst[u].push_back(v);
        }
        
        unordered_map<int,bool> visited;
        unordered_map<int,bool> pvisited;
        
        for(auto i=0;i<V;i++){
            if(!visited[i]) if(checkcycledfs(i,visited,pvisited)) return true;
            
        }
        
        
        return false;
    }
};