/*
Detect loop in a linked list
Given a linked list, check if the linked list has loop or not. Below diagram shows a linked list with a loop.


Recommended: Please solve it on “PRACTICE” first, before moving on to the solution.
Following are different ways of doing this
Use Hashing:
Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then return false and if next of current node points to any of the previously stored nodes in Hash then return true.
*/
#include <stdio.h>



