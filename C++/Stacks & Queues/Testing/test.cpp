#include <bits/stdc++.h>
#include "List.h"
#include "Node.h"
#include "ListQueue.h"
#include "ListStack.h"
using namespace std;

int main() {
    // Create a stack of strings
    ListStack<string> stack;
    // push 5 strings onto the stack
    stack.push("hello");
    stack.push("world");
    stack.push("!");
    stack.push("this");
    stack.push("is");
    // Print the stack
    stack.print("stack");
}

// size = 5, values = hello world ! this is


// size = 5, values = is this ! world hello