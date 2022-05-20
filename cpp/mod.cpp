#define MOD 1000000007

int mod_power(int a, int b, int m) {
    int res = 1;

    a %= m;

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a *= a;
        b = b >> 1;
    }

    return res;
}
