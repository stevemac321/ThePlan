#include <stdio.h>
struct rect;
typedef struct rect rect;
struct rect {
    int left;
    int right;
    int top;
    int bottom;
};

bool doIntersect(const struct rect x, const struct rect y) {
    // If one rectangle is to the left of the other
    if (x.right < y.left || y.right < x.left) {
        return false;
    }

    // If one rectangle is above the other
    if (x.bottom > y.top || y.bottom > x.top) {
        return false;
    }

    return true;
}

int main() {
    rect rect1 = {0, 4, 4, 0};
    rect rect2 = {2, 6, 6, 2};
    
    if (doIntersect(rect1, rect2)) {
        puts("Rectangles intersect.\n");
    } else {
        puts("Rectangles do not intersect.\n");
    }
    
    return 0;
}
/*
Explanation:
Left/Right Check:

x.right < y.left: x is completely to the left of y.
y.right < x.left: y is completely to the left of x.
Above/Below Check:

x.bottom > y.top: x is completely above y.
y.bottom > x.top: y is completely above x.
If any of these conditions are true, the rectangles do not intersect. Otherwise, they do.

This method ensures that you cover all possible scenarios where the rectangles do not intersect, making the intersection check robust and easy to understand.
*/
