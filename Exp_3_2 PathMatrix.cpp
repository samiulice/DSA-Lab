#include <bits/stdc++.h>
#define max 10
using namespace std;

void floydWarshall(int adj[max][max], int n) {
    int path[max][max], i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if(adj[i][j] == 0){
                path[i][j] = 0;
            }
            else{
                path[i][j] = 1;
            }
        }
    }
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j= 0; j < n; j++) {
                path[i][j] = path[i][j] || (path[i][k] && path[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << path[i][j] << " ";
        }
        cout << endl;
    }

}

int main() {
    
    int n;
    //cout << "Number of vertices: ";
    cin >> n;
    int adj[max][max];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> adj[i][j];
        }
    }
    floydWarshall(adj, n);
    return 0;
}
