#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <set>
#include <list>
#include<limits.h>

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjlst;


    void addedge(int u, int v, int dir, int wt){
        if(dir==1){
            //directed graph
            adjlst[u].push_back({v,wt});
        }

        if(dir==0){
            //undirected graph
            adjlst[u].push_back({v,wt});
            adjlst[v].push_back({u,wt});
        }
    }


    //shortest path magnitude using dijkstra's also
    void shortestpathdijkstra(int src, int dest, int n){
        vector<int> dist(n+1,INT_MAX);

        //set will contain dist, node for access and shorting
        set<pair<int,int>> st;

        dist[src]=0;
        st.insert({0,src});

        while(!st.empty()){
            auto iteratornbrpair=st.begin();
            pair<int,int> nbrpair=*iteratornbrpair;
            int top_dist=nbrpair.first;
            int top_node=nbrpair.second;
            st.erase(st.begin());

            for(auto nbr:adjlst[top_node]){
                int nbr_node=nbr.first;
                int nbr_dist=nbr.second;

                if(dist[nbr_node]>top_dist+nbr_dist){
                    auto preventry= st.find({dist[nbr_node],nbr_node});
                        if(preventry != st.end()){
                            st.erase(preventry);
                        }
                    

                    dist[nbr_node]=top_dist+nbr_dist;

                    st.insert({dist[nbr_node],nbr_node});

                }


            }


        }


        cout<<"shortest distance from "<<src<<" to "<< dest << " node is "<<dist[dest];




    }




};


int main(){
    Graph g;

    g.addedge(1,6,0,14);
    g.addedge(1,3,0,9);
    g.addedge(1,2,0,7);
    g.addedge(2,3,0,10);
    g.addedge(2,4,0,15);
    g.addedge(3,6,0,2);
    g.addedge(3,4,0,11);
    g.addedge(4,5,0,6);
    g.addedge(5,6,0,9);
    g.addedge(8,10,0,5);
    g.shortestpathdijkstra(6,4,6);
    return 0;
}