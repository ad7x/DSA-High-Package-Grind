#include <iostream>
using namespace std;
#include <unordered_map>
#include<list>
#include <queue>
#include<vector>
#include<algorithm>

template <typename T>

//shortest path printing in undirected graph with unit wt using bfs
//this algo will print all the path

class Graph{
    public:
    unordered_map<T,list<pair<T,int>>> adjlst;

    void addingedges(vector<T> arr){
        for(int i=1;i<arr.size();i++){
            addEdge(arr[0],arr[i],1,1);

        }
    }

    void addEdge(T u,T v, int wt, int dir){

        if(dir==0){
            adjlst[u].push_back({v,wt});
            adjlst[v].push_back({u,wt});

        }

        else if(dir==1){
            adjlst[u].push_back({v,wt});

        }
    }


    void shortestpathbfs(T src, T dest){
        queue<T> q;
        unordered_map<T,bool> visited;
        unordered_map<T,T> parent;

        parent[src]=src;
        q.push(src);
        visited[src]=true;


        

        while (!q.empty())
        {
            
            auto frontnode=q.front();
            q.pop();

            for(auto nbrpair:adjlst[frontnode]){
                auto chld=nbrpair.first;
                if(!visited[chld]){
                    visited[chld]=true;
                    q.push(chld);
                    parent[chld]=frontnode;
                }
            }

        }

        if (visited.find(dest) == visited.end()) {
            cout << "Path from " << src << " to " << dest << " does not exist." << endl;
            return;
        }


        vector<T> shortestpath;
        while(dest!=src){
            shortestpath.push_back(dest);
            dest=parent[dest];
        }

        shortestpath.push_back(src);

        reverse(shortestpath.begin(),shortestpath.end());


        for(auto i:shortestpath){
            cout<<" -->"<< i;
        }

        cout<<endl;
        
    


    }







};

int main(){

    Graph<char> g;

   
    g.addingedges({'a','b','g'});
    g.addingedges({'b','a','c','h'});
    g.addingedges({'c','b','i','d'});
    g.addingedges({'d','c','j','e'});
    g.addingedges({'e','d','k','f'});
    g.addingedges({'f','e','l'});
    g.addingedges({'g','a','h','m'});
    g.addingedges({'h','b','g','i','n'});
    g.addingedges({'i','j','c','h','o'});
    g.addingedges({'j','d','i','p','k'});
    g.addingedges({'k','e','j','q','l'});
    g.addingedges({'l','f','k','r'});
    g.addingedges({'m','g','n','s'});
    g.addingedges({'n','h','m','t','o'});
    g.addingedges({'o','i','n','u','p'});
    g.addingedges({'p','j','o','v','q'});
    g.addingedges({'q','k','p','q','r'});
    g.addingedges({'r','l','q','x'});
    g.addingedges({'s','m','t'});
    g.addingedges({'t','s','n','u'});
    g.addingedges({'u','t','o','v'});
    g.addingedges({'v','u','p','w'});
    g.addingedges({'w','v','q','x'});
    g.addingedges({'x','w','r'});



    g.shortestpathbfs('a','x');

    cout<<"\neverything is fine\n\n";
    
    return 0;
}