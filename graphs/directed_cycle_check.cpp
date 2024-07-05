#include <iostream>
#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
 
#define int long long
#define endl "\n"
#define fr(n) for(long long i=0;i<n;i++)
#define pb push_back
#define f first
#define s second
 
const int B = 2e5 + 10;

//-------------- CSES Round Trip 2 -------------------------

 
vector<vector<int>> adj;
vector<int> parent;
vector<int> vis; /*
0 if not visited
1 is visiting
2 if dfs exited
*/
int cycle_start, cycle_end;
 
bool dfs(int node) {
    vis[node] = 1;

    for (int child : adj[node]) {   
        if (vis[child]==0) {
            parent[child] = node;
            if(dfs(child)) return true;

        }

        else if (vis[child]==1) {
            cycle_start = child;
            cycle_end = node;
            return true;
        }


    }

    vis[node] = 2;
    return false;

}

void print_cycle() {


    vector<int> cycle;


    cycle.push_back(cycle_start);

    for (int i = cycle_end; i != cycle_start; i=parent[i]) {
        cycle.push_back(i);
    }

    cycle.push_back(cycle_start);

    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << endl;
    for (auto i : cycle) cout << i << " ";

}


void solve() {

    int n, m;
    cin >> n >> m;

    vis.assign(n+1, 0);
    parent.assign(n+1, -1);
    adj.resize(n+1, vector<int>());

    cycle_start = -1, cycle_end = -1;
 
    fr(m) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }


    for (int i=1;i<=n;i++) {
        if (vis[i]==0) {
            if (dfs(i)) break;
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl; return;
    }

    else {
        print_cycle();
    }


 
 
}
 
int32_t main() {
    quick;
    solve();
    return 0;
}