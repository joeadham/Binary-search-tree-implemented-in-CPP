# Binary search tree implemented in C++

### The methods implemented are as follows:

- Search returns true if element is found, else returns false
- Size returns the number of elements found in the tree
- All traversal functions print the tree to the standard output.
- The input format  is as follows
  - first line: two numbers, **tree_size** **number_of_operations**
  - second line: **tree_size** elements, the initial elements to be inserted in the tree
  - **number_of_operations** lines: operations to be done on the tree, operations can be one of the following
    - 1 element --> insert element in the tree
    - 2 element --> search for element
    - 3 1 --> in_order_rec    ||  3 2 --> in_order_it
    - 4 1 --> pre_order_rec   ||  4 2 --> pre_order_it
    - 5 1 --> post_order_rec   ||  5 3 --> post_order_it
    - 6 --> breadth
    - 7 --> size
