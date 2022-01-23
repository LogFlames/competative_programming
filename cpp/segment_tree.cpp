#include <vector>

struct Tree {
    int (*fnPtr)(int, int);
    std::vector<int> s;
    int n;
    int unit;
    Tree(int n, int unit, int (*fnPtr)(int, int))
        : fnPtr(fnPtr), s(2 * n, unit), n(n), unit(unit) {}
    Tree(int n, int unit, std::vector<int> A, int (*fnPtr)(int, int))
        : fnPtr(fnPtr), s(2 * n, unit), n(n), unit(unit) {
        for(int i = 0; i < A.size(); i++) {
            s[i + n] = A[i];
        }
        for (int i = n - 1; i > 0; i--) {
            s[i] = (*fnPtr)(s[i * 2], s[i * 2 + 1]);
        }
    }
    void update(int i, int v) {
        int ind = i + n;
        s[ind] = v;
        while (ind > 1) {
            ind /= 2;
            s[ind] = (*fnPtr)(s[ind * 2], s[ind * 2 + 1]);
        }
    }
    int query(int l, int r) {
        int sl = unit, sr = unit;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l % 2) sl = (*fnPtr)(sl, s[l++]);
            if (r % 2) sr = (*fnPtr)(sr, s[--r]);
        }
        return (*fnPtr)(sl, sr);
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
