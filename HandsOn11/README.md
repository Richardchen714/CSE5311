# Hands On 11

1. Implement a dynamic array (that is a C++ vector). You are only allowed to use C style arrays. Assume the datatype is an int.

This is implemented in `Vector.h` and `Vector.cpp`

2. Given a dynamic table that doubles in size when it needs more space. Find the amrotized runtime for inserting `n` elements
    1. Use the aggregate method
   2. Use the accounting method

When using **aggregate method**, Initial size = 1, When table is full, it doubles in size.

To insert `n` elements
- We copy all existing elements (i elements when we have i elements)
- Plus the cost of inserting the new element (1)

Total cost is $\sum_{i=1}^{n}1+\sum_{i=1, i=i^2}^{n}i=3n-1$

Amortized cost = Total cost / n ≈ 3 = O(1)


When using **Assigning credit**, each insertion is charged 3 units of cost (credits).
1 unit will cover the cost of the insertion itself.
2 units are saved as credits to pay for future array doublings.

Doubling Cost: When the array doubles, we need to copy all elements to the new array. This cost is covered by the credits accumulated from previous insertions:

When the array size is doubled from `k` to `2k`, there are `k` elements to copy, costing `k` units.

The 2 units saved per previous insertion provide exactly enough credit for each element to be copied during the doubling step.
Since each insertion is charged 3 units, and this is sufficient to cover both the insertion and any required doublings, the amortized cost per insertion is 3 units, or
$O(1)$.