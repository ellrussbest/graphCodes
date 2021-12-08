#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

template<class T>
class Graph{
    map<T, map<T, bool>>graph;
    
    public:
        void addEdge(T nodeX, T nodeY){
            graph[nodeX][nodeY] = graph[nodeY][nodeX] = true;
        }
        
        void bfs(T src){
            map<T, bool>visited;
            visited[src] = true;
            queue<T>q;
            q.push(src);
            
            while(!q.empty()){
                T temp = q.front();
                cout << temp << " ";
                q.pop();
               
                for(auto i : graph){
                    if(i.first == temp){
                        for(auto j : i.second){
                            if(!visited[j.first] && j.second == 1){
                                visited[j.first] = true;
                                q.push(j.first);
                            }
                        }
                    }
                }
            }
        }
        
        void dfs(T src){
            map<T, bool>visited;
            stack<T>st;
            
            st.push(src);
            
            visited[src] = true;
            
            while(!st.empty()){
                T temp = st.top();
                cout << temp << " ";
                st.pop();
                for(auto i : graph){
                   if(i.first == temp){
                        for(auto j : i.second){
                            if(!visited[j.first] && j.second == 1){
                                visited[j.first] = true;
                                st.push(j.first);
                                break;
                            }
                        }
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
    graph.addEdge('C', 'D');
    graph.addEdge('C', 'E');
    graph.addEdge('E', 'F');
    graph.bfs('A'); cout << endl;
    graph.dfs('A');
    return 0;
}
