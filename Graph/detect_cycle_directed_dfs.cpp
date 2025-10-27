#include <iostream>
using namespace std;
#include<unordered_map>
#include<list>
#include<queue>
//generalize the code of the graph 
template<typename T>

class Graph{
    public:

    unordered_map<T,list<pair<T,int>>> adjlst;
    void addEdge(T u, T v,int wt, int dir){
        if(dir==1){
            adjlst[u].push_back({v,wt});
        }
        else{
            adjlst[u].push_back({v,wt});
            adjlst[v].push_back({u,wt});

        }
    }



    void printadjlst(){
        for(auto i:adjlst){
            cout<<i.first<<" - (";
            for(auto j:i.second ){
                cout<< "{ "<<j.first<< ", "<<j.second<<" }";
            }
            cout<<")\n";
        }

        cout<<endl;
    }

    void dfstraversal(T src, unordered_map<T,bool> &visited){
        visited[src]=true;
        cout<<src<<" ";

        for(auto nbrpr:adjlst[src]){
            T child= nbrpr.first;
            if(!visited[child]){
                dfstraversal(child, visited);
                
            }
        }
    }

};

int main(){
    
    return 0;
}