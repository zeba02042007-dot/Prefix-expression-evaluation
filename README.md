# Prefix-expression-evaluation
# Prefix Expression Evaluation Using Stack

## About the Project
This project evaluates a prefix expression using the Stack data structure in C.

## Objective
To understand the working of Stack and use it to evaluate prefix expressions.

## Data Structure Used
- Stack

## Programming Language
- C

## How It Works
1. Read the prefix expression from right to left.
2. If the symbol is an operand, push it into the stack.
3. If the symbol is an operator, pop two operands from the stack.
4. Perform the operation.
5. Push the result back into the stack.
6. The final value in the stack is the result.

## Example

Prefix Expression:
- + 5 * 2 3

Result:
- 11

## Time Complexity
O(n)

## Space Complexity
O(n)

## Conclusion
This project demonstrates how a Stack can be used to efficiently evaluate prefix expressions.
