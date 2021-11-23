#include <vector>

struct Tree {
    std::vector<int> s;
    int n;
    Tree(int n = 0) : s(2 * n, 0), n(n) {}
    void update(int i, int v) {
        int ind = i + n;
        s[ind] = v;
        while (ind != 0) {
            ind /= 2;
            s[ind] = s[ind * 2] + s[ind * 2 + 1];
        }
    }
    int query(int l, int r) {
        int sl = 0, sr = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l % 2 == 1) sl += s[l++];
            if (r % 2 == 1) sr += s[--r];
        }
        return sl + sr;
    }
};

int pow2roundup(int x) {
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}
