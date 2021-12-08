#include <iostream>
#include <map>
#include <list>
#include <stack>

using namespace std;

template <class T>
class Graph{
    map<T, list<T>>g;
    
    public:
        void addEdge(T nodeX, T nodeY){
            g[nodeX].push_back(nodeY);
            g[nodeY].push_back(nodeX);
        }
        
        void dfs(T src){
            map<T, bool>visited;
            
            for(auto i : g){
                auto node = i.first;
                visited[node] = false;
            }
            
            stack<T>st;
            st.push(src);
            T temp;
            
            while(!st.empty()){
                temp = st.top();
                cout << temp << " ";
                visited[temp] = true;
                st.pop();
                
                for(auto nbr : g[temp]){
                    if(!visited[nbr]){
                        st.push(nbr);
                        break;
                    }
                }
            }
        }
};

int main() {
    Graph<char>graph;
    graph.addEdge('A', 'B');
    graph.addEdge('A', 'C');
    graph.addEdge('B', 'D');
    graph.addEdge('D', 'C');
    graph.addEdge('C', 'E');
    graph.addEdge('E', 'F');
    
    graph.dfs('A');
    
   return 0;
}
