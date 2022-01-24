#include <bits/stdc++.h>
#include <vector>
#include <set>
#define INF 1e9+10

using namespace std;

//Dijkstra algorithm is applicable for weighted graphs only
const int N=1e5+5;
vector<pair<int,int>> graph[N];
bool vis[N];
vector<int> level(N,INF);

void Dijkstra(int source){
    set<pair<int,int>> st;
    st.insert({0,source});
    level[source]=0;
    while(!st.empty()){
        auto node = *st.begin();
        int dist = node.first;
        int vertex = node.second;
        st.erase(st.begin());
        if(vis[vertex]) continue;
        vis[vertex]=1;
        for(auto child : graph[vertex]){
            int child_v = child.first;
            int wt = child.second;
            if(dist+wt < level[child_v]){
                level[child_v] = dist+wt;
                st.insert({level[child_v],child_v});
            }
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        graph[x].push_back({y,wt});
        graph[y].push_back({x,wt});//if graph is not directed
    }
    Dijkstra(1);
    return 0;
}