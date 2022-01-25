#include <bits/stdc++.h>
#include <vector>
#define INF 1e9+10

//This algorithm is used for finding shortest path between all possible vertices
//Thats why this algo is also known as all pair shortest distance
using namespace std;

const int N = 510;
int dp[N][N];
int n;//number of vertices
int m;//number of edges

void Floyd_Warshall(){
    for(int k=1 ; k<=n ; k++){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(dp[i][k]!=INF && dp[k][j]!=INF)//this check is used to avoid if one weight is negative and the other is INF i.e if path does not exist b/w any pair of i to k or k to j
                  dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
}

int main(){
    for(int i=1 ; i<N ; i++){
        for(int j=1 ; j<N ; j++){
            if(i==j) dp[i][j]=0;
            else dp[i][j]=INF;
        }
    }
    cin>>n>>m;
    for(int i=0 ; i<m ; i++){
        int x,y,wt;
        cin>>x>>y>>wt;
        dp[x][y]=wt;
    }
    Floyd_Warshall();
    return 0;
}