#include <iostream>
#include <map>
#include <list>

using namespace std;

template<class T>
class Graph{
    map<T, list<T>>l;
    
    public:
        void addEdge(T x, T y, bool directed = true){
            l[x].push_back(y);
            if(!directed) l[y].push_back(x);
        }
        
        bool cycle_helper(T node, map<T, bool> &visited, T parent){
            visited[node] = true;
            
            for(auto nbr: l[node]){
                if(!visited[nbr]){
                    //go and recursively visit the neighbour
                    bool cycle_nila = cycle_helper(nbr, visited, node);
                    
                    if(cycle_nila) return true;
                    
                }
                
                if (nbr != parent) return true;
            }
            return false;
        }
        
        bool contains_cycle(){
            //check for cycle in directed graph
            map<T, bool> visited;
            
            for(auto i : l){
                T node = i.first;
                visited[node] = false;
            }
            
            return cycle_helper(0, visited, -1);
        }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);
    g.addEdge(3, 4, false);
    g.addEdge(4, 0, false);
    
    if (g. contains_cycle()) cout << "yes undirected graph contains cycle\n";
    else cout << "No it doesn't contain a cycle\n";
    return 0;
}
