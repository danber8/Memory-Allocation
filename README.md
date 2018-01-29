# Memory-Allocation

Problem Description

Write a C++ program that emulate the operating system’s responsibility of allocatingmemory to certain programs.  This will be a very simple page-based view of memorymanagement. On startup, your program will have some 32 pages ofcontiguous, unusedmemory. Each page will be 4 KB long.

It should then allow the users (i.e., your TAs) to “run” programs that require chunksof this memory for some period of time. It should also allow the users to “kill” programs(i.e., “Ctrl-c” or “kill -9” in most OSs) that are in progress. The pages used by programsthat are killed can then be re-used for future programs.

The purpose of this project is two-fold. First, you need to get practice with linked listsand pointers. Secondly, you should examine critically the results of different algorithmsof allocating memory on the “fragmentation” of the memory.

Details

1. (Data Structures:)  You arerequiredto implement a linked-list data structure torepresent the memory of the operating system. It is suggested that each node of thelinked list should represent some “chunk” (page) of memory.

2. One strong suggestion is to use 2 linked lists in your program: one to maintain the freespace and one to maintain the used space. Initially, the free space contains a singlenode representing the entire memory. The used list is then empty. When a program isadded, you then have to “split” the node in the free list and add a newnode to yourused list.

3. Another way: Every node in your list is a page of memory with a givensequence number(Page 0→Page 1→Page 2, etc). So, when your program starts, your free list shouldcontain all 32 pages in sequence. As more programs are added, thepages move fromthe free list into the used list. Note that the order of the lists must be maintained![Note: This approach works OK for small memory size, but it will have scalabilityissue when the main memory is reaching gigabyte range (e.g., 1GB/4KB= 250,000page-nodes)]

4. (Algorithms:)  When your OS/MM program is launched, it needs to decide whichalgorithm to allocate thecontiguousmemory for programs. To solve this issue, youarerequiredto implement the best-fit and worst-fit algorithms when choosing pages.

5. When a program is “killed”, your OS needs to reclaim that memory. This means thatyou will need to add the memory used by that program to your free list. Note that ifthere is free memory immediately adjacent to this memory, you may need to combinethem.

6. (Computation:) At any given point, the users should be able to query your OS toget the number of “fragments” in memory. You will also certainly want some way ofprinting out your memory to the screen to ease the debugging process.
