
//this is sol given by me on gfg for topo sort using dfs
class Solution {
  public:
  unordered_map<int,list<int>> adjlst;
  unordered_map<int,bool> visited;
  
      void topodfs(int src,stack<int> &st){
          
          visited[src]=true;
          
          for(auto nbr:adjlst[src]) if(!visited[nbr]) topodfs(nbr, st);
          
          
          
          
          st.push(src);
      }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adjlst[u].push_back(v);
        }
        
        
        stack<int> st;
        
        
        vector<int> ans;
        
        for(int i=0; i<V; i++) if(!visited[i]) topodfs(i,st);
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
            
        }
        
        return ans;
        
        
        
        
        
        
    }
};