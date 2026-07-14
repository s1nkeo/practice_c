int foo(const int *a, int n) {
    int candidate = a[0];

    if (n <= 1)
        return candidate;

    int count = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == candidate)
            count++;
        else
            count--;

        if (count == 0) {
            candidate = a[i];
            count = 1;
        }
    }

    return candidate;
}
