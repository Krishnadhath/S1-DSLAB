#include <stdio.h>

typedef unsigned int Set; // 32-bit set (0–31)

// Add element to set
Set add(Set s, int x) { return s | (1U << x); }

// Remove element from set
Set removeEl(Set s, int x) { return s & ~(1U << x); }

// Check membership
int contains(Set s, int x) { return (s >> x) & 1U; }

// Union of two sets
Set setUnion(Set a, Set b) { return a | b; }

// Intersection of two sets
Set setIntersect(Set a, Set b) { return a & b; }

// Display elements
void display(Set s) {
    printf("{ ");
    for (int i = 0; i < 32; i++)
        if (contains(s, i)) printf("%d ", i);
    printf("}\n");
}

int main() {
    Set A = 0, B = 0;

    A = add(A, 1); A = add(A, 3); A = add(A, 5);
    B = add(B, 3); B = add(B, 4); B = add(B, 5);

    printf("A = "); display(A);
    printf("B = "); display(B);

    printf("A ∪ B = "); display(setUnion(A, B));
    printf("A ∩ B = "); display(setIntersect(A, B));

    A = removeEl(A, 3);
    printf("A after removing 3 = "); display(A);

    return 0;
}
