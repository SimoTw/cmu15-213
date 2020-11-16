#include <stdio.h>

int conditional(int cond, int t, int f) {
    int mask = (cond << 31) >> 31;
    return (t & mask) | (f & ~mask);  
}

int main() {
     int expect3 = conditional(1, 3, 2);
     int expect2 = conditional(0, 3, 2);
     printf("expect3: %d, expect2: %d\n", expect3, expect2);
} 
