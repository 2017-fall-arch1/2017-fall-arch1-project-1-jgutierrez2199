AVL Balanced Search Tree
===

---

Description
---
This lab focuses on implementing a balanced binary search tree in C
That stores the names of employees for the ACME Company. In order to
accomplish this we will use the AVL tree data type. The reason for
keeping this tree balanced is to allow us to make insertions,
deletions, and searches in O(log n) time.

AVL Trees
---
AVL trees maintain balance in order to maintain their time
efficiency for insertions, deletions, and searches. For a small pool
of data the change is not very apparent, but for larger data sets this
optimization is important as it makes the worst case time efficiency
O(log n). In order to achieve this, the AVL tree keeps track of the
offset for each and every node. As long as the magnitude of the offset
for any node does not become more than 1, the tree should remain
balanced.

Contents
---
This directory contains:
* code that implements a binary search tree of strings
* code that balances said tree in order to optimize searching,
insertion, and deletion
* a demo program that uses the binary search tree in the context of
storing employee names

The demo program asks you if you would like to insert, delete, or
search the employee name data

This demo contains the following files:
 llist.h: header file of llist structure & "public" interface functions
 llist.c: implementation of linked list
 listDemo.c: a demonstration program that uses the linked list

How to Use:
---
To compile:
~~~
$ make
~~~

To test it, try:
~~~
$ make demo
~~~

To delete binaries:
~~~
$ make clean
~~~

##References

~~~
www.geeksforgeeks.org/avl-tree-set-1-insertion/
~~~
I used this site to read up on AVL trees. They are something I learned
about back in CS 2 but had not used since. This site was a great
resource and provided great explanations of the rotations and steps
that are needed to re-balance the tree. I was also able to mirror some
of my code after theirs, though I did not actually take it or copy
it. 