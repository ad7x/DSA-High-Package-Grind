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

    //designing BFS traversal algo
    void bfstraversal(T src){
        //adjlst use hoga but wo already data member me h to koi dikkat nhi h firse create krne ka jaroorat nhi h whi use hoyega
        //visited array banao
        unordered_map<T,bool> visited;
        //queue banao
        queue<T> q;
        q.push(src);
        visited[src]=true;
        


        while (!q.empty()){
            T frontnode =q.front();
            q.pop();
            cout<<frontnode<<" ";
       

            for (auto nbrpair:adjlst[frontnode]){
                
                T nbr=nbrpair.first;

                if(!visited[nbr]){
                    visited[nbr]=true;
                    q.push(nbr);
                }

            }
        }
        


    }


};




int main(){
    //create unweighted graph obj


    

    //weighted and dir graph creation

    Graph<int> g;

    g.addEdge(0,1,5,0);
    g.addEdge(1,2,7,0);
    g.addEdge(1,3,6,0);
    g.addEdge(2,3,8,0);
    g.addEdge(3,4,9,0);
    g.addEdge(4,5,11,0);
    g.addEdge(5,3,15,0);
    

    //printing Graph

    g.printadjlst();

    g.bfstraversal(0);


    return 0;
    
}