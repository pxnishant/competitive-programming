#include<bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define fr(n) for(long long i=0;i<n;i++)
#define f first
#define s second
using namespace std;
const int N = 1e5 + 7;

vector<int> parent(N);
vector<int> sizes(N);

void make(int v) {
    parent[v] = v;
    sizes[v] = 1;
}

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void Union(int a, int b) {
    a = find(a); b = find(b);
    if (a!=b) {
        if (sizes[a] > sizes[b]) swap(a, b);
        parent[a] = b;
        sizes[b] += sizes[a];
    }
}

int main() {
    quick;
    
}