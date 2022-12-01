#include <stdio.h>
#include "c+.h"

class( Test, {
    int a;
    int b;
    int c;
}, void classnewf(Test, a, int a) { // Creates a new function
    printf("a%d\n", a);
}, void classnewf(Test, b, int b) {
    printf("b%d\n", b);
},
void classnewf(Test, showabc) {
    printf("a%d b%d c%d\n", this->a, this->b, this->c);
},
constructor(Test, int a, int b, int c) { // Creates a constructor
    Test t;
    t.a = a;
    t.b = b;
    t.c = c;
    return t;
});

int main() {
    Test t = new(Test, 1, 5, 3); // Calls the constructor
    classfunc(Test, t, a, 1); // t.a(1)
    classfunc(Test, t, b, 2); // t.b(2)
    classfunc(Test, t, showabc); // t.showabc()
}

// output:
// a1
// b2
// a1 b5 c3

