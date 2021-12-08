#include <iostream>
#include <map>
#include <list>

using namespace std;

template <typename T>
class Graph{
    map<T, list<T>>l;
    
    public:
        void addEdge(T x, T y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        
        /*since the map should remain the same in all the function calls, 
        we must parse it by reference i.e. we should not make a copy of the map
        because it should be common/same for all functions*/
        
        void dfs_helper(T src, map<T, bool>&visited){
            //Recursive function that will traverse the graph
            cout << src << " ";
            visited[src] = true;
            //go to all nbr of that node that is not visited
            
            for(T nbr: l[src]){
                if(!visited[nbr]){
                    dfs_helper(nbr, visited);
                }
            }
        }
        
        void dfs(T src){
            map<T, bool> visited;
            //mark all the nodes as not visited in the beginning
            for(auto p : l){
                T node = p.first;
                visited[node] = false;
            }
            //call the helper function
            dfs_helper(src, visited);
        }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    
    g.dfs(0);
    return 0;
}
