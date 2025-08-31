#include <stdio.h>
#include <time.h>
long tim = 10000000;
// A helper function to sleep for n nanoseconds
void sleep_ns(long ns) {
    struct timespec req;
    req.tv_sec = 0;
    req.tv_nsec = ns;
    nanosleep(&req, NULL);
}

void f() {
    volatile int x = 0;   // variable initialized
    sleep_ns(tim); 
    x = x+1;
       // sleep for 1,000,000 ns = 1 ms
}

void g() {
    f();
    sleep_ns(tim);
}

void h() {
    f();
    sleep_ns(tim);
    g();
}

int main() {
    int i;

    for (i = 0; i < 100; ++i) f();
    for (i = 0; i < 200; ++i) g();
    for (i = 0; i < 300; ++i) h();

    return 0;
}

