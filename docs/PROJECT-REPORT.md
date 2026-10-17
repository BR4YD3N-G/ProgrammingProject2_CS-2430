Coding Cadets
Brayden Graham, Thaddeus Schelp, Todd Dharni
CS 2430, Semester 1, Project 2

# Introduction (1–2 paragraphs)

explain the problem and why it is interesting/relevant.

This problem is interesting because of its practical applications. Sets are applicable everywhere from music playlists on your computer, to industrial databases, search engines, and more.

# Implementation / Methods

For sets, multisets, and fuzzy sets, we used an array of 32-bit unsigned integers to represent the elements.

## Sets

In a set, each element in the array is limited to `0` or `1`.

## Multisets

In a multiset, each element in the array is an unsigned 32-bit integer.

## Fuzzy sets

In a fuzzy set, each element in the array is an unsigned normalized 32-bit fixed-point number.

We chose this representation because it allows us to keep the same data structure as used for sets and multisets, and provides higher precision than using a normal 32-bit floating-point datatype. Furthermore, conversion between the 32-bit floating-point type and the unsigned normalized 32-bit fixed point type is trivial. Converting a multiset to a set is also fairly straightforward.

# Verification Approach

explain how you tested (include at least 2–3 representative cases + at least one edge case).

- Verify the set functions behave as expected when multiset or fuzzy set data is passed in, and vice versa.

# Results

## Ordinary Sets
Let $A$ be $[1, 1, 1, 0, 1, 0, 1, 0, 0, 0]$

Let $B$ be $[0, 0, 1, 1, 1, 1, 0, 1, 0, 0]$

| Operation       | Result                           |
|-----------------|----------------------------------|
| $A^\complement$ | $[0, 0, 0, 1, 0, 1, 0, 1, 1, 1]$ |
| $A\cup B$       | $[1, 1, 1, 1, 1, 1, 1, 1, 0, 0]$ |
| $A\cap B$       | $[0, 0, 1, 0, 1, 0, 0, 0, 0, 0]$ |
| $A-B$           | $[1, 1, 0, 0, 0, 0, 1, 0, 0, 0]$ |
| $A\triangle B$  | $[1, 1, 0, 1, 0, 1, 1, 1, 0, 0]$ |

## Multiset (Bag) Operations

Let $A$ be $[3, 2, 0, 1, 0, 4, 0, 0, 0, 0]$

Let $B$ be $[1, 4, 2, 3, 0, 0, 0, 0, 0, 0]$

| Operation      | Result                           |
|----------------|----------------------------------|
| $A\cup B$      | $[3, 4, 2, 3, 0, 4, 0, 0, 0, 0]$ |
| $A\cap B$      | $[1, 2, 0, 1, 0, 0, 0, 0, 0, 0]$ |
| $A-B$          | $[2, 0, 0, 0, 0, 4, 0, 0, 0, 0]$ |
| $A\triangle B$ | $[0, 2, 2, 2, 0, 0, 0, 0, 0, 0]$ |
| $A + B$        | $[4, 6, 2, 4, 0, 4, 0, 0, 0, 0]$ |

# Discussion / Analysis

1. If you used different arrays/structures/classes to represent the different types of sets, would it be possible to have overloaded methods or operations that would provide the correct functionality regardless of whether you were using sets or multisets? Why or why not?
2. Would it be possible to use the same data set/structure/class to store sets and multisets? Why or why not?

Not only is it possible, but we chose to do this for our sets, multisets, and fuzzy sets using a vector of unsigned 32-bit integers. This works because the functions which operate on the set interpret the data inside in different ways.

- Sets treat each element as a boolean. If it is not zero, then the element is considered to be present in the set.
- Multisets treat each element as a count. The count is the number of times the element is present in the set.
- Fuzzy sets treat each element as a level of inclusivity. The level of inclusivity is $0$ when the element is $0$, and $1$ when the element is $2^{32}-1$.

3. How easy or difficult is it to determine the type of set that you need to use based on the user’s natural-language query? Why?

It is both difficult and easy. If you can extract the notion that the user wants a group of things, then a set is appropriate. If you can extract the notion that the user desires a quantity or group of quantities, then multisets are appropriate. If you can extract the notion that the user desires a percentage or ratio, or group thereof, then a fuzzy set would be appropriate. The difficult part of the problem is extracting that notion.

This is very difficult to do. You may choose to examine the query for words like 'number', 'count', 'quantity', or similar, but the user may express the desire for that kind of thing in a way that you did not expect. For example, in the queries "When is the next concert in Salt Lake City?" and "When will it rain?". The first would likely be answered using a set, and the second using a fuzzy set. The same question word is used in both queries, but they require different types of sets to answer.

An approach that overcomes this difficulty might be to use a tiny LLM whose job is to determine the form of the question and the user's desired output. The huge downside to this is the extreme cost of even lightweight LLMs.

4. Is it possible to store the data from one type of set (plain sets or multisets) in another type? Would you need to lose data in order to do so? Why?

It is possible to store the data from one type of set in another. For example, a multiset can store the data from a set. We just decide that the set is now a multiset, and that is all the conversion that needs to be done. The reverse is the same. There is a loss of data when calling the set functions with multiset. The elements of the multiset will be treated as booleans rather than counts. The same concept applies when considering fuzzy sets. To convert a fuzzy set to a count, one may want to provide some sort of conversion function. To convert it to a plain set, one may wish to specify a threshold which values must match or exceed to be considered present in the set.

5. Discuss what implications your answers to questions 1–4 have for someone trying to code an interface which would allow users to type in natural-language queries.
6. Discuss what implications your answers to questions 1–5 have for someone trying to code an interface which would allow users to access arbitrary types of data using natural language.

# Conclusion

what you learned about mapping mathematical structures to code and why user queries complicate things.

# Summary of Work Done / Lessons Learned

one short paragraph reflecting on problems, tools, and what you’d improve.

# Sources

cite any external references you used.

Full sentences and paragraphs

Grammatically correct and spell-checked

Audience is another student not in this class

Clear figure/table captions if you include tables

Professional tone
