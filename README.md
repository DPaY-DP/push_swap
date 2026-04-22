*This project has been created as apart of the 42 curriculum by dpfannen.*

<h1 align="center">42 Project: push_swap</h1>

<p align="center">
  <i>A highly optimized sorting algorithm project using two stacks (a and b) and a limited set of operations.</i><br>
</p>

---

##  Description

The **push_swap** project challenges you to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

The primary goal is to sort a given sequence of numbers within `stack a` in ascending order, utilizing a secondary auxiliary stack (`stack b`).

## Operations
The sorting must be achieved exclusively using the following operations:

### Swap Operations
| Instruction | Action |
| :--- | :--- |
| `sa` | **swap a:** Swap the first 2 elements at the top of stack a. (Does nothing if there is only one or no element). |
| `sb` | **swap b:** Swap the first 2 elements at the top of stack b. (Does nothing if there is only one or no element). |
| `ss` | `sa` and `sb` at the same time. |

### Push Operations
| Instruction | Action |
| :--- | :--- |
| `pa` | **push a:** Take the first element at the top of b and put it at the top of a. (Does nothing if b is empty). |
| `pb` | **push b:** Take the first element at the top of a and put it at the top of b. (Does nothing if a is empty). |

### Rotate Operations
| Instruction | Action |
| :--- | :--- |
| `ra` | **rotate a:** Shift up all elements of stack a by 1. The first element becomes the last one. |
| `rb` | **rotate b:** Shift up all elements of stack b by 1. The first element becomes the last one. |
| `rr` | `ra` and `rb` at the same time. |

### Reverse Rotate Operations
| Instruction | Action |
| :--- | :--- |
| `rra` | **reverse rotate a:** Shift down all elements of stack a by 1. The last element becomes the first one. |
| `rrb` | **reverse rotate b:** Shift down all elements of stack b by 1. The last element becomes the first one. |
| `rrr` | `rra` and `rrb` at the same time. |

---

## Instructions
1. Compile the program using the `make` command in your terminal.
2. Execute the compiled `./push_swap` binary followed by the numbers you wish to sort.
3. Arguments can be passed as individual numbers separated by spaces, or as a single space-separated string.

**Example Use Cases:**
```bash
# Passing numbers individually
./push_swap 3 51 2 55

# Passing numbers as a string
./push_swap "-1 1 4"

# Mixed arguments
./push_swap 3 51 "-1 1 4" 2 55
```

The output will be the precise list of sequential operations required to sort the given sequence in ascending order.

---

## Resources
- [Doubly Linked List in C (GeeksforGeeks)](https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/)  
- [Fastest Sorting Algorithms Overview](https://builtin.com/machine-learning/fastest-sorting-algorithm)  
- Official *42 subject PDF* for `push_swap`

## AI Usage Disclosure
- **GitHub Copilot** was primarily used to assist with debugging and code explanation during this project.
- **Specific Tasks:** Refined wording in the README, explained compilation/syntax error messages, and helped debug segmentation faults and logic flaws without forcefully inserting complete code replacements.