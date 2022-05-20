#define MOD 1000000007

long long int mod_power(long long int a, long long int b, long long int m) {
    long long int res = 1;

    a %= m;

    while (b > 0) {
        if (b & 1) {
            res = (res * a) % m;
        }

        a = (a * a) % m;
        b = b >> 1;
    }

    return res;
}
