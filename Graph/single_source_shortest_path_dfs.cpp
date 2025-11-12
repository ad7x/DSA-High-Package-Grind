#include<iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <list>
#include <limits.h>
#include <stack>




class Graph{
    public:



    unordered_map<int,list<pair<int,int>>> adjlst;
    unordered_map<int,bool> visited;

    




    void addedge(int u, int v,int dir,int weight){

        if(dir==1){
            adjlst[u].push_back({v,weight});
        }

        if(dir==0){
            adjlst[u].push_back({v,weight});
            adjlst[v].push_back({u,weight});
        }

    }


    void toposortusingdfs(int src, stack<int> &stk){
        visited[src]=true;

        for(auto nbrpair:adjlst[src]){
            if(!visited[nbrpair.first]) toposortusingdfs(nbrpair.first, stk);

        }

        stk.push(src);
    }

    void shortestpath(stack<int> st, int n){
        vector<int> dist(n,INT_MAX);

        //A
        int top=st.top();
        st.pop();
        dist[top]=0;
        //B 
        for(auto nbr:adjlst[top]){
            int nb_node=nbr.first;
            int nb_wt=nbr.second;
            //C check if dist of src + nbr distance is less then make dist[node] as update the dist[node] with the lowest value i.e dist[node]=dist[src]+nbr dist

            if(dist[top]+nb_wt<dist[nb_node]) dist[nb_node]=dist[top]+nb_wt;
        }
        
        //repeat the same for all the other nodes


        while(!st.empty()){
            top=st.top();
            st.pop();
            
             //B 
        for(auto nbr:adjlst[top]){
            int nb_node=nbr.first;
            int nb_wt=nbr.second;
            //C check if dist of src + nbr distance is less then make dist[node] as update the dist[node] with the lowest value i.e dist[node]=dist[src]+nbr dist

            if(dist[top]+nb_wt<dist[nb_node]) dist[nb_node]=dist[top]+nb_wt;
        }
        }


        for(auto i: dist){
            cout<< i<<" ";


        }
        
    }




};




int main(){
    
    stack<int> st;

    Graph g;

    g.addedge(0,1,1,5);
    g.addedge(0,2,1,3);
    g.addedge(2,1,1,2);
    g.addedge(1,3,1,3);
    g.addedge(2,3,1,5);
    g.addedge(2,4,1,6);
    g.addedge(4,3,1,1);


    g.toposortusingdfs(0,st);

    g.shortestpath(st,5);



    return 0;
}