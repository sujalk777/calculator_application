# Calculator Application

## Overview
This repository contains a C++ implementation of a calculator application. The project utilizes various data structures such as linked lists and stacks to efficiently handle and evaluate mathematical expressions.

## Features
- Supports basic arithmetic operations.
- Utilizes both array-based and linked list-based stack implementations.
- Implements a custom linked list for efficient data management.
- Modularized code structure with separate header and source files.

## File Structure

### **Source Files**
- `main.cpp` - Entry point of the application, responsible for handling user input and executing operations.
- `list.cpp` - Implements a linked list structure used for data management.
- `node.cpp` - Defines the node structure used in the linked list.
- `stack_a.cpp` - Implements a stack using an array-based approach.
- `stack_b.cpp` - Implements a stack using a linked list approach.
- `stack_c.cpp` - Implements another variation of a stack with custom optimizations.

### **Header Files**
- `list.h` - Declares the `List` class and its methods.
- `node.h` - Declares the `Node` class structure.
- `stack_a.h` - Declares the `StackA` class and its methods.
- `stack_b.h` - Declares the `StackB` class and its methods.
- `stack_c.h` - Declares the `StackC` class and its methods.

## How to Run
1. Clone this repository:
   ```bash
   git clone https://github.com/Plutonium17/COL106-A2.git
   cd COL106-A2
   ```
2. Compile the code using a C++ compiler:
   ```bash
   g++ main.cpp list.cpp node.cpp stack_a.cpp stack_b.cpp stack_c.cpp -o calculator
   ```
3. Run the compiled program:
   ```bash
   ./calculator
   ```

## Contributing
If you find any bugs or have suggestions for improvements, feel free to fork the repository and submit a pull request.

