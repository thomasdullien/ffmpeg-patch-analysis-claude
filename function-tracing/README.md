# Function Call Tracing

Minimal instrumentation for C/C++ function tracing with Perfetto visualization.

## Components

1. **trace_instrument.c** - Instrumentation library
2. **trace_to_perfetto.cpp** - Converter to Perfetto format

## Quick Start

```bash
# Build instrumentation library
gcc -c -fPIC trace_instrument.c -o trace_instrument.o
gcc -shared trace_instrument.o -o libtrace.so -ldl -lpthread

# Build your program with tracing
gcc -finstrument-functions -g your_program.c -o your_program \
    -L. -ltrace -ldl -lpthread -Wl,-rpath,.

# Run (creates trace_<tid>.log files)
./your_program

# Build converter
g++ -O3 -std=c++17 trace_to_perfetto.cpp -o trace_to_perfetto

# Convert to Perfetto format
./trace_to_perfetto trace_*.log -o trace.json

# Open trace.json in https://ui.perfetto.dev
```

## Log Format

```
[seq] [timestamp] [dots] [ENTRY|EXIT!] function_name
[0] [1.000000000]  [ENTRY] main
[1] [1.000050000] . [ENTRY] helper
[2] [1.000100000] . [EXIT!] helper
[3] [1.000150000]  [EXIT!] main
```

- Dots indicate call depth
- One log per thread (trace_<tid>.log)
- Timestamp in seconds.nanoseconds

## Build System Integration

### Makefile
```makefile
CFLAGS += -finstrument-functions -g
LDFLAGS += -L. -ltrace -ldl -lpthread
```

### CMake
```cmake
add_compile_options(-finstrument-functions -g)
link_libraries(trace dl pthread)
```

## Example

See example.c for a complete working example.

## For Claude Code

See SKILL.md for integration instructions.
