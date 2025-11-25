# Code Coverage with gcov

Minimal guide to adding code coverage to C/C++ projects.

## Quick Start

```bash
# Compile with coverage
gcc --coverage -o program source.c

# Run program
./program

# Generate text report
gcov source.c

# View report
cat source.c.gcov
```

## HTML Reports

```bash
# Install gcovr
pip install gcovr

# Generate HTML report
gcovr --html-details -o coverage.html
```

## Build System Integration

### Makefile
```makefile
ENABLE_COVERAGE ?= 0
ifeq ($(ENABLE_COVERAGE),1)
    CFLAGS += --coverage
    LDFLAGS += --coverage
endif
```

Build: `make ENABLE_COVERAGE=1`

### CMake
```cmake
option(ENABLE_COVERAGE "Enable coverage" OFF)
if(ENABLE_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()
```

Build: `cmake -DENABLE_COVERAGE=ON -B build && cmake --build build`

## Understanding Output

**.gcov file format:**
```
        5:   42:    executed_line();
    #####:   43:    not_executed();
        -:   44:    // comment
```

- Number = execution count
- `#####` = not executed
- `-` = non-executable

## Files Generated

- `.gcno` - Coverage notes (compile time)
- `.gcda` - Coverage data (runtime)
- `.gcov` - Text report

## Coverage Metrics

- **Line**: 80%+ target
- **Branch**: 70%+ target
- **Function**: 90%+ target

## For Claude Code

See SKILL.md for integration instructions.
