# Concurrency

## Concurrent linked lists

In this directory are three very minimal linked lists programs for the purpose of measuring the time of multi-threaded linked lists. All three use the same list structure however one is single-threaded, or normal, to compare the others to. The others use three threads and each threads shares the task of adding nodes to the list. One list, however, is optimized.  

You can see from the plot below, as the numbers of nodes gets higher, there is a larger and larger time disparity between the lists.   
<br>
## Timing of inserting nodes to head of a linked list
![list plot](listplot.png)