#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>

class Graph{
    public:

    unordered_map<int,list<int>> adjlst;
    void addEdge(int u, int v, int dir){
        if(dir==1){
            adjlst[u].push_back(v);
        }
        else{
            adjlst[u].push_back(v);
            adjlst[v].push_back(u);

        }
    }


    unordered_map<int,list<pair<int,int>>> adjlstwt;
    void addEdgewt(int u, int v,int wt, int dir){
        if(dir==1){
            adjlstwt[u].push_back({v,wt});
        }
        else{
            adjlstwt[u].push_back({v,wt});
            adjlstwt[v].push_back({u,wt});

        }
    }

    void printadjlst(){
        for(auto i:adjlst){
            cout<<i.first<<" - (";
            for(auto j:i.second ){
                cout<< j<< ", ";
            }
            cout<<")\n";
        }
    }


    void printwtadjlst(){
        for(auto i:adjlstwt){
            cout<<i.first<<" - (";
            for(auto j:i.second ){
                cout<<"{ " <<j.first<< ", "<<j.second<<"}";
            }
            cout<<")\n";
        }
    }

};




int main(){
    //create unweighted graph obj

    //unweighted and directed
    Graph g;
    //insert edge

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,3,1);
    g.addEdge(2,3,1);
    g.addEdge(5,6,1);
    g.addEdge(3,4,1);
    g.addEdge(4,5,1);
    g.addEdge(5,3,1);

    


    //unweighted and undirected
    Graph g2;
    //insert edge

    g2.addEdge(0,1,0);
    g2.addEdge(1,2,0);
    g2.addEdge(1,3,0);
    g2.addEdge(2,3,0);
    g2.addEdge(5,6,0);
    g2.addEdge(3,4,0);
    g2.addEdge(4,5,0);
    g2.addEdge(5,3,0);

    

    //weighted and dir graph creation

    Graph g3;

    g3.addEdgewt(0,1,5,1);
    g3.addEdgewt(1,2,7,1);
    g3.addEdgewt(1,3,6,1);
    g3.addEdgewt(2,3,8,1);
    g3.addEdgewt(3,4,9,1);
    g3.addEdgewt(4,5,11,1);
    g3.addEdgewt(5,3,15,1);
    

    //printing Graph

    g.printadjlst();
    cout<<endl;
    g2.printadjlst();
    cout<<endl;
    g3.printwtadjlst();
    cout<<endl;


    return 0;
    
}