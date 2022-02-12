#include <iostream>
#include <chrono>
#include <random>
#include <Header.hpp>



int search(int y, int n, int k, int* x) {
    if (k < x[y]) {
        return -1;
    }
    if (k == x[y]) {
        return y;
    }
    if (k > x[n]) {
        return -1;
    }
    int a = y;
    int b = n;
    int c;
    while (a + 1 < b) {
        c = (a + b) / 2;
        if (k > x[c]) {
            a = c;
        }
        else {
            b = c;
        }
    }
    if (x[b] == k) {
        return b;
    }
    else {
        return -1;
    }
}


int prostoysearch(int* x, int n, int k) {
    for (int i = 0; i < n; i++) {
        if (x[i] == k) {
            return i;
        }
    }
    return -1;
}

void quicksort(int a, int b, int* x) {
    if (a >= b) {
        return;
    }
    int m, k, l, r;
    m = (rand()*rand()) % (b - a + 1) + a;
    k = x[m];
    l = a - 1;
    r = b + 1;
    while (1) {
        do {
            l = l + 1;
        } while (x[l] < k);

        do {
            r = r - 1;
        } while (x[r] > k);
        if (l >= r)
            break;

        std::swap(x[l], x[r]);
    }
    r = l;
    l = l - 1;
    quicksort(a, l, x);
    quicksort(r, b, x);
}

double f(double a) {
    return(a * a - 10);
}

double bisektion(double a, double b, double e) {
    double x;
    while (abs(a - b) > e) {
        x = (a + b) / 2;
        if ((x == a) && (x == b)) {
            return x;
        }
        else if (f(x) * f(a) > 0) {
            a = x;
        }
        else {
            b = x;
        }

    }
    return (a + b) / 2;
}

