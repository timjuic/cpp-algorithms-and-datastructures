# Multiset - Data Structure

## What is a Multiset?

A multiset (mset) is a generalization of the concept of a set. It is a collection of unordered values, where each value can appear multiple times.

## Characteristics of Multiset

- There is no order of data in a multiset
- Value in a multiset can appear multiple times
- For each value we can find its count, if count is 0, then value is not included in the multiset

# Implementation

Data structure is an array which will contain values and a variable that holds the number of used positions in the array. Note that this is a static array meaning its number of elements cannot be changed during execution. Thats extra variable is needed.

## Methods

Method name | Description | Complexity
---- | ---- | ----
IsEmpty() | Returns true if multiset is empty, false if its not | O(1)
IsElement(x) | Takes a value as a parameter. Returns true if value exists in multiset, otherwise false | O(n)
Count(x) | Takes a value as a parameter. Returns how many times value appears in multiset | O(n)
Insert(x) | Takes a value as a parameter. Adds the value to the end of the multiset | O(n)
Delete(x) | Takes a value as a parameter. Deletes the first occurrence of the value in the multiset.  | O(n)


