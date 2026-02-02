# Program 2 - Infix to Postfix Converter

## What it does
Takes an infix expression (like A+B*C) and converts it to postfix (ABC*+). Also evaluates numeric expressions.

## Data Structure

Just using a simple character array as stack with a top pointer.

```c
char stack[MAX];
int top = -1;
```

## Functions

**Stack operations:**
- `push()` - adds character to stack
- `pop()` - removes and returns top character
- `peek()` - returns top without removing
- `isEmpty()` - checks if stack is empty

**Helper functions:**
- `isOperator()` - checks if character is +, -, *, /
- `precedence()` - returns precedence (*, / have 2, +, - have 1)

**Main functions:**
- `infixToPostfix()` - does the conversion
- `evaluatePostfix()` - calculates result for numeric expressions

## How conversion works

1. Scan the infix expression left to right
2. If operand (letter/digit) - add directly to output
3. If '(' - push to stack
4. If ')' - pop everything until '(' and add to output
5. If operator - pop operators with higher/equal precedence, then push current operator
6. After scanning, pop all remaining operators

## How evaluation works

1. Scan postfix expression
2. If digit - push to integer stack
3. If operator - pop two operands, do operation, push result
4. Final value in stack is answer

## Sample Output

```
Infix to Postfix Converter
==========================

Infix:    A+B*C
Postfix:  ABC*+

Infix:    (A+B)*C
Postfix:  AB+C*

Infix:    2+3*4
Postfix:  234*+
Result:   14

Infix:    (2+3)*4
Postfix:  23+4*
Result:   20
```

## Example

For `2+3*4`:
- Scan 2: output = "2"
- Scan +: push to stack
- Scan 3: output = "23"
- Scan *: higher precedence than +, push
- Scan 4: output = "234"
- Pop all: output = "234*+"
- Result: 2 + (3*4) = 2 + 12 = 14

## Compile and Run

```bash
gcc prog_2.c -o prog_2
./prog_2
```

## Limitations
- Only works with single digit numbers
- No power operator
- Only basic operators