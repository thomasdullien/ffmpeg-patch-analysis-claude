// example.c - Simple example for function tracing

#include <stdio.h>

void helper() {
    printf("In helper\n");
}

void process() {
    helper();
}

int main() {
    process();
    return 0;
}

// To build and run:
// gcc -c -fPIC ../trace_instrument.c -o trace_instrument.o
// gcc -shared trace_instrument.o -o libtrace.so -ldl -lpthread
// gcc -finstrument-functions -g example.c -o example -L. -ltrace -ldl -lpthread -Wl,-rpath,.
// ./example
// 
// To convert to Perfetto:
// g++ -O3 -std=c++17 ../trace_to_perfetto.cpp -o trace_to_perfetto
// ./trace_to_perfetto trace_*.log -o trace.json
// Open trace.json in https://ui.perfetto.dev
