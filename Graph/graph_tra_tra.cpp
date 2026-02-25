#include<iostream>
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
    //create unweighted graph obj


    

    //weighted and dir graph creation

    Graph<char> g;

    g.addEdge('A','B',5,0);
    g.addEdge('A','C',7,0);
    g.addEdge('B','D',6,0);
    g.addEdge('C','E',8,0);
    g.addEdge('C','F',9,0);
    g.addEdge('E','F',11,0);
    g.addEdge('G','H',11,0);
    g.addEdge('H','I',11,0);
    g.addEdge('J','K',11,0);

    
    

    //printing Graph

    g.printadjlst();

    unordered_map<char,bool> visited;


    // g.dfstraversal('A',visited);


    //upper code and dfs traversal will not work well if the graph has components 
    // so we will do something to make this work for all


    //for counting component we will init a valiable and increament it with each time the new unvisited comes
    int comp_count=0;

    for(char i='A'; i<'K'; i++){
        if(!visited[i]){
            g.dfstraversal(i,visited);
            comp_count++;

        }
    }

    cout<<endl<<"Total no. component of the graph are "<<comp_count;

  


    return 0;
    
}