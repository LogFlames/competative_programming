#include <vector>

int find_set(int v, std::vector<int>& parent) {
    if (v == parent[v]) {
        return v;
    }
    int p = find_set(parent[v], parent);
    parent[v] = p;
    return p;
}

void union_sets(int a, int b, std::vector<int>& parent) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (a > b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
}
