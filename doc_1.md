# Program 1 - Balanced Parentheses Checker

## What it does
Checks if brackets in an expression are balanced or not. It uses stack.

## Data Structure

Stack with character array and top pointer.

```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
```

## Functions

**Stack functions:**
- `initStack()` - sets top to -1
- `push()` - adds item to stack
- `pop()` - removes and returns top item
- `isEmpty()` - checks if stack empty

**Helper functions:**
- `isOpeningBracket()` - checks if char is ( [ or {
- `isClosingBracket()` - checks if char is ) ] or }
- `isMatchingPair()` - checks if opening and closing match

**Main function:**
- `checkBalanced()` - this does the actual checking

## Algorithm

1. Go through each character
2. If opening bracket - push to stack
3. If closing bracket - pop from stack and check if they match
4. At end, stack should be empty for balanced expression

## Output

```
Checking for balanced parentheses:


Expression 1: a + (b - c) * (d
Result: NOT BALANCED

Expression 2: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Expression 3: a + (b - c)
Result: BALANCED
```

## How to run

```bash
gcc prog_1.c -o prog_1
./prog_1
```

Works fine.