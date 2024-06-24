Queue works on FIFO (first in first out) principle.
Queue can be implemented by using 
    1. Arrays 
    2. Linked List data structure

Queue is a linear type of data structure

Types of queues : 
    1. Simple queue : simple queue
    2. Circular queue : when the queue is full, if the the queue has memory left in the front of it, the values get placed there instead of it being end of the queue 
    3. Priority queue : it is a binary tree data strucuture implemented using  heap data structure, where the element at root represents
    4. Dequeue (Double Ended queue) : here we can input as well as remove data at front as well end of the queue
    5. Input restricted queue : push is done at rear only but pop operation can be performed at the front and rear
    6. Output restricted queue : pop operation can be performed only at front but push operation can be performed at rear and front 

Applications of Queue:
    - Multi programming : used to organize multiple programs/applications running in the main memory
    - Network : used in networking devices like switches and router. 
    - Job Scheduling : used in executing process in an  operating system shceduler
    - Sharing resources : it is used to form waiting lists for a single shared resources for different processes

Advantages of queue: 
    - A large amount of data can be managed efficiently with ease.
    - Operations such as insertion and deletion can be performed with ease as it follows the first in first out rule.
    - Queues are useful when a particular service is used by multiple consumers.
    - Queues are fast in speed for data inter-process communication.
    - Queues can be used in the implementation of other data structures.

Diadvantages of queue: 
    - The operations such as insertion and deletion of elements from the middle are time consuming.
    - In a classical queue, a new element can only be inserted when the existing elements are deleted from the queue.
    - Searching an element takes O(N) time.
    - Maximum size of a queue must be defined prior in case of array implementation.

- Priority Queues : It is type of queue that has the first element in the data structure as the largest (max-heap priority queue) or smallest (min-heap priority queue)

    1. Max-heap priority queue : `priority_queue<data type> <name>`
    2. Min-heap priority queue : `priority_queue<data type, vector<int>, greater<int>> <name>`