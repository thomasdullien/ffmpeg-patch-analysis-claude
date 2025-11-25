# Line Execution Checker

Fast tool to check if specific source lines were executed during test runs.

## Build
```bash
g++ -O3 -std=c++17 line_checker.cpp -o line-checker
```

## Usage
```bash
# Check single line
./line-checker file.c:42

# Check multiple lines
./line-checker file.c:42 main.c:100 util.c:55
```

## Output
```
file.c:42 EXECUTED (5 times)
main.c:100 NOT EXECUTED
util.c:55 EXECUTED (12 times)
```

## Exit Codes
- 0: All lines executed
- 1: One or more lines NOT executed
- 2: Error

## Prerequisites
Coverage data must exist from `gcc --coverage` build and program execution.

## Example
```bash
# Build with coverage
gcc --coverage -o example example.c

# Run program
./example

# Build tool
g++ -O3 -std=c++17 line_checker.cpp -o line-checker

# Check lines
./line-checker example.c:5
# Output: example.c:5 EXECUTED (1 time)

./line-checker example.c:9
# Output: example.c:9 NOT EXECUTED

./line-checker example.c:5 example.c:9
# Output:
# example.c:5 EXECUTED (1 time)
# example.c:9 NOT EXECUTED
```

## How It Works
1. Finds/generates `.gcov` files from coverage data
2. Parses execution counts for requested lines
3. Reports whether each line was executed

## For Claude Code
See SKILL.md for integration instructions.
