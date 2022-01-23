#include <vector>

int find_set(int v, std::vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    int p = find_set(parent[v], parent);
    parent[v] = p;
    return p;
}

void union_sets(int a, int b, vi& parent) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        parent[b] = a;
    }
}
