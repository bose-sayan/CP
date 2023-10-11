# When?
Given some constraints and need to satisfy all of them together. If some constraint needs to be satisfied, we denote it by some **boolean** variable, and if its opposite needs to be satisfied then denote it by the negation of the boolean variable. Can be used if the problem description can be converted to a **conjunctive normal form** which has only 2 literals in each clause, such as, 
> (x1 + y1) . (x2 + y2) . (x3 + y3) ...


# Main Idea
We want to build an **implication graph**, which is a directed graph consisting of edges from some a to some b iff a -> b needs to be satisfied.
- If we have some clause of the form (x + y), add both the following edges in the graph
    - ~x -> y
    - ~y -> x
- If x and ~x are in the same strongly connected component, the constraints can't be satisfied.
- Let `id[x]` be the index of some vertex x in some valid topological ordering of the implication graph.
    - `id[x] < id[~x]` set x to F
    - `id[~x] < id[x]` set x to T
- For every x in some SCC, assign the same truth valuation to each of them.

# Clause types
Let us consider some clause (x + y)
- If x needs to be true, use (x + x)
- If y needs to be true, use (y + y)
- If one of them needs to be true, use (x + y)
- If one of them needs to be true, use (x ^ y), i.e., (~x + ~y) . (x + y)
- If both of them needs to be assigned the same valuation, use ~(x ^ y), i.e., (~x + y) . (x + ~y)