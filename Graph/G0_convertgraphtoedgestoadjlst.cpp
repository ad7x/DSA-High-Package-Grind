class Solution {
  public:
  
    
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        
        vector<vector<int>> adjlst(V);
        
        
    
        
        for(auto pr:edges){
            int u = pr.first;
            int v = pr.second;
            
            adjlst[u].push_back(v);
            adjlst[v].push_back(u);
        }
        
        return adjlst;
        
        
    }
};