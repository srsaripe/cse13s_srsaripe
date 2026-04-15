#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// area of a disk: πr²
double area_of_disk(double radius) {
    return M_PI * radius * radius;
}

// area of ring: big circle - small circle
double area_of_ring(double outer_radius, double inner_radius) {
    return area_of_disk(outer_radius) - area_of_disk(inner_radius);
}

// absolute difference
int bigger_minus_smaller(int a, int b) {
    if (a > b) {
        return a - b;
    }
    return b - a;
}

// check if x is in [lower_bound, upper_bound]
bool value_in_range(int lower_bound, int x, int upper_bound) {
    return (x >= lower_bound) && (x <= upper_bound);
}

// sum of two largest squares
int sum_of_greater_squares(int a, int b, int c) {
    int a2 = a * a;
    int b2 = b * b;
    int c2 = c * c;

    int sum = a2 + b2 + c2;

    // subtract smallest square
    if (a2 <= b2 && a2 <= c2) {
        return sum - a2;
    } else if (b2 <= a2 && b2 <= c2) {
        return sum - b2;
    } else {
        return sum - c2;
    }
}
