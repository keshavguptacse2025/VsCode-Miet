# Data Structures Lab (C Language) - MIET

A complete, clean, and highly efficient collection of 71 fundamental Data Structures and Algorithms implementations in pure C language, structured for Visual Studio and VS Code environments.

---

## 📑 Table of Contents

1. [Arrays & Matrices](#-arrays--matrices)
2. [Searching Algorithms](#-searching-algorithms)
3. [Sorting Algorithms](#-sorting-algorithms)
4. [Singly Linked List](#-singly-linked-list)
5. [Circular & Doubly Linked List](#-circular--doubly-linked-list)
6. [Stack & Recursion](#-stack--recursion)
7. [Queue & Deque](#-queue--deque)
8. [Binary Trees](#-binary-trees)
9. [Binary Search Trees (BST)](#-binary-search-trees-bst)
10. [Heaps & Priority Queues](#-heaps--priority-queues)
11. [Graphs & Graph Traversals](#-graphs--graph-traversals)
12. [Minimum Spanning Trees (MST)](#-minimum-spanning-trees-mst)
13. [Shortest Path & Closure](#-shortest-path--closure)
14. [Performance Analysis (Value Added)](#-performance-analysis-value-added)
15. [Compilation & Execution](#-compilation--execution)

---

## 📊 Arrays & Matrices

| File | Description |
| :--- | :--- |
| [`1d_array_insertion.c`](1d_array_insertion.c) | Insertion of an element at a specified index in a 1D array with bounds checking. |
| [`1d_array_deletion.c`](1d_array_deletion.c) | Deletion of an element at a given position from a 1D array. |
| [`1d_array_traversal.c`](1d_array_traversal.c) | Forward and backward linear traversal of 1D array elements. |
| [`1d_array_searching.c`](1d_array_searching.c) | Linear key search in a 1D array. |
| [`1d_array_merging.c`](1d_array_merging.c) | Two-pointer merging of two sorted 1D arrays into a combined destination array. |
| [`2d_matrix_addition.c`](2d_matrix_addition.c) | Element-wise matrix addition for 2D matrices. |
| [`2d_matrix_subtraction.c`](2d_matrix_subtraction.c) | Element-wise matrix subtraction for 2D matrices. |
| [`2d_matrix_multiplication.c`](2d_matrix_multiplication.c) | Standard matrix multiplication of two compatible 2D matrices. |
| [`matrix_transpose.c`](matrix_transpose.c) | Computation of the transpose of an $M \times N$ matrix. |

---

## 🔍 Searching Algorithms

| File | Description |
| :--- | :--- |
| [`linear_search.c`](linear_search.c) | Sequential linear search scanning unsorted/sorted arrays with $O(N)$ time complexity. |
| [`binary_search.c`](binary_search.c) | Logarithmic binary search on sorted arrays with $O(\log N)$ time complexity. |

---

## 📐 Sorting Algorithms

| File | Description |
| :--- | :--- |
| [`bubble_sort.c`](bubble_sort.c) | Bubble sort algorithm optimized with early-exit swap detection. |
| [`selection_sort.c`](selection_sort.c) | Selection sort finding minimum element in unsorted subarray. |
| [`insertion_sort.c`](insertion_sort.c) | Incremental insertion sort maintaining a sorted prefix. |
| [`merge_sort.c`](merge_sort.c) | Divide-and-conquer stable merge sort with $O(N \log N)$ performance. |
| [`quick_sort.c`](quick_sort.c) | In-place partition-based quick sort. |
| [`radix_sort.c`](radix_sort.c) | Non-comparative Least Significant Digit (LSD) Radix Sort with counting sort passes. |

---

## 🔗 Singly Linked List

| File | Description |
| :--- | :--- |
| [`singly_linked_list_insertion_beginning.c`](singly_linked_list_insertion_beginning.c) | Node insertion at the beginning (head) and display. |
| [`singly_linked_list_insertion_end.c`](singly_linked_list_insertion_end.c) | Node insertion at the end (tail) and display. |
| [`singly_linked_list_insertion_position.c`](singly_linked_list_insertion_position.c) | Node insertion at an arbitrary 1-based index and display. |
| [`singly_linked_list_deletion_beginning.c`](singly_linked_list_deletion_beginning.c) | Node deletion from the beginning (head) with memory deallocation. |
| [`singly_linked_list_deletion_end.c`](singly_linked_list_deletion_end.c) | Node deletion from the end (tail) and list update. |
| [`singly_linked_list_deletion_position.c`](singly_linked_list_deletion_position.c) | Node deletion at a specified index/position. |
| [`singly_linked_list_traversal.c`](singly_linked_list_traversal.c) | Linear sequential traversal of singly linked list nodes. |
| [`singly_linked_list_search.c`](singly_linked_list_search.c) | Value search returning 1-based node position. |
| [`singly_linked_list_count_nodes.c`](singly_linked_list_count_nodes.c) | Iterative node counting function. |
| [`singly_linked_list_reverse.c`](singly_linked_list_reverse.c) | In-place pointer reversal for singly linked lists. |
| [`polynomial_representation.c`](polynomial_representation.c) | Linked list representation of algebraic polynomials with coefficient and exponent. |
| [`polynomial_addition.c`](polynomial_addition.c) | Polynomial addition merging like terms and preserving sorted exponents. |

---

## 🔄 Circular & Doubly Linked List

| File | Description |
| :--- | :--- |
| [`circular_linked_list_insertion_beginning.c`](circular_linked_list_insertion_beginning.c) | Circular singly linked list insertion at the head. |
| [`circular_linked_list_insertion_end.c`](circular_linked_list_insertion_end.c) | Circular singly linked list insertion at the tail. |
| [`circular_linked_list_deletion_beginning.c`](circular_linked_list_deletion_beginning.c) | Circular singly linked list deletion from head. |
| [`circular_linked_list_deletion_end.c`](circular_linked_list_deletion_end.c) | Circular singly linked list deletion from tail. |
| [`doubly_linked_list_insertion_beginning.c`](doubly_linked_list_insertion_beginning.c) | Doubly linked list insertion at head with bidirectional pointer updates. |
| [`doubly_linked_list_insertion_end.c`](doubly_linked_list_insertion_end.c) | Doubly linked list insertion at tail. |
| [`doubly_linked_list_deletion_beginning.c`](doubly_linked_list_deletion_beginning.c) | Doubly linked list deletion from head. |
| [`doubly_linked_list_deletion_end.c`](doubly_linked_list_deletion_end.c) | Doubly linked list deletion from tail. |

---

## 🥞 Stack & Recursion

| File | Description |
| :--- | :--- |
| [`stack_using_array.c`](stack_using_array.c) | Fixed-capacity stack using array with `push`, `pop`, `peek`, and status checks. |
| [`stack_using_linked_list.c`](stack_using_linked_list.c) | Dynamic stack using singly linked list nodes. |
| [`infix_to_postfix.c`](infix_to_postfix.c) | Shunting-yard based conversion of infix arithmetic expressions to postfix. |
| [`postfix_evaluation.c`](postfix_evaluation.c) | Stack-based postfix expression arithmetic evaluator. |
| [`balanced_parentheses.c`](balanced_parentheses.c) | Parentheses balance verification for `()`, `{}`, and `[]`. |
| [`tower_of_hanoi.c`](tower_of_hanoi.c) | Recursive Tower of Hanoi puzzle solver printing individual disk moves. |

---

## 👥 Queue & Deque

| File | Description |
| :--- | :--- |
| [`queue_using_array.c`](queue_using_array.c) | Linear queue using fixed array with `enqueue` and `dequeue`. |
| [`queue_using_linked_list.c`](queue_using_linked_list.c) | Dynamic FIFO queue using linked list with head and tail pointers. |
| [`circular_queue.c`](circular_queue.c) | Array-based circular queue with modulo arithmetic index wrap-around. |
| [`priority_queue_linked_list.c`](priority_queue_linked_list.c) | Ascending priority queue ordered by priority values. |
| [`deque.c`](deque.c) | Double-ended queue supporting front/rear insertions and deletions. |

---

## 🌿 Binary Trees

| File | Description |
| :--- | :--- |
| [`binary_tree_creation.c`](binary_tree_creation.c) | Dynamic node allocation and structured vertical tree visualization. |
| [`preorder_traversal.c`](preorder_traversal.c) | Depth-first Preorder traversal (Root -> Left -> Right). |
| [`inorder_traversal.c`](inorder_traversal.c) | Depth-first Inorder traversal (Left -> Root -> Right). |
| [`postorder_traversal.c`](postorder_traversal.c) | Depth-first Postorder traversal (Left -> Right -> Root). |
| [`binary_tree_level_order.c`](binary_tree_level_order.c) | Breadth-first level-order traversal using an iterative queue. |

---

## 🔍 Binary Search Trees (BST)

| File | Description |
| :--- | :--- |
| [`bst_insertion.c`](bst_insertion.c) | Recursive BST insertion maintaining binary search invariants. |
| [`bst_deletion.c`](bst_deletion.c) | BST node deletion handling 0, 1, and 2 children with in-order successors. |
| [`bst_search.c`](bst_search.c) | Key search in BST returning matching node pointer. |

---

## 💎 Heaps & Priority Queues

| File | Description |
| :--- | :--- |
| [`min_heap.c`](min_heap.c) | Complete Min Heap implementation with `insert`, `extract_min`, and `min_heapify`. |
| [`max_heap.c`](max_heap.c) | Complete Max Heap implementation with `insert`, `extract_max`, and `max_heapify`. |
| [`heap_sort.c`](heap_sort.c) | In-place Heap Sort using max-heapify. |

---

## 🕸️ Graphs & Graph Traversals

| File | Description |
| :--- | :--- |
| [`adjacency_matrix.c`](adjacency_matrix.c) | Graph representation using $V \times V$ binary adjacency matrix. |
| [`adjacency_list.c`](adjacency_list.c) | Space-efficient graph representation using linked adjacency lists. |
| [`bfs.c`](bfs.c) | Breadth-First Search traversal visiting vertices layer by layer with a queue. |
| [`dfs.c`](dfs.c) | Depth-First Search traversal using recursive backtracking and a visited array. |

---

## 🌲 Minimum Spanning Trees (MST)

| File | Description |
| :--- | :--- |
| [`prims_algorithm.c`](prims_algorithm.c) | Prim's greedy algorithm finding MST from an adjacency matrix. |
| [`kruskals_algorithm.c`](kruskals_algorithm.c) | Kruskal's algorithm using Disjoint Set Union (DSU with path compression and rank). |

---

## 🛣️ Shortest Path & Closure

| File | Description |
| :--- | :--- |
| [`warshall_algorithm.c`](warshall_algorithm.c) | Warshall's algorithm computing transitive closure reachability matrix. |
| [`floyd_warshall_algorithm.c`](floyd_warshall_algorithm.c) | Floyd-Warshall algorithm computing all-pairs shortest paths. |
| [`dijkstra_algorithm.c`](dijkstra_algorithm.c) | Dijkstra's single-source shortest path algorithm on non-negative weighted graphs. |

---

## 📈 Performance Analysis (Value Added)

| File | Description |
| :--- | :--- |
| [`static_vs_dynamic_ds_analysis.c`](static_vs_dynamic_ds_analysis.c) | Microbenchmark comparing static contiguous arrays vs dynamic linked lists in runtime, memory footprint, and cache locality. |
| [`top_10_hashtags_ds_selection.c`](top_10_hashtags_ds_selection.c) | Algorithmic evaluation demonstrating why a Hash Map + Min-Heap of size $K=10$ achieves $O(N \log K)$ performance over $O(N \log N)$ sorting. |
| [`best_sorting_algorithm_student_names.c`](best_sorting_algorithm_student_names.c) | Comparative analysis of sorting algorithms for student strings, demonstrating why Merge Sort is optimal for stability and guaranteed $O(N \log N \cdot L)$ runtime. |

---
