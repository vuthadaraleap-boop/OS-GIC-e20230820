# Class Activity 3 — Socket Communication & Multithreading

- **Student Name:** Vutha Daraleap
- **Student ID:** e20230820
- **Date:** November 17, 2026

---

## Task 1: TCP Socket Communication (C)

### Compilation & Execution

![Socket exchange](screenshots/task1_socket_exchange.png)

### Answers

1. **Role of `bind()` / Why client doesn't call it:**
   > `bind()` assigns a specific local IP address and port number to the server's socket so clients know where to connect. The client does not call `bind()` because the OS automatically assigns an available ephemeral port when `connect()` is called.

2. **What `accept()` returns:**
   > `accept()` returns a new socket file descriptor dedicated to communicating with that specific connected client, whereas the original server socket continues listening for new incoming connections.

3. **Starting client before server:**
   > Starting the client before the server causes `connect()` to fail immediately with `connect: Connection refused` because no process is listening on the target port.

4. **What `htons()` does:**
   > `htons()` (Host to Network Short) converts a 16-bit port number from host byte order (Little-Endian on x86) to network byte order (Big-Endian) so different systems interpret the port number identically.

5. **Socket call sequence diagram:**
   > Server: `socket() -> bind() -> listen() -> accept() -> read() -> send() -> close()`
   > Client: `socket() -> connect() -> send() -> read() -> close()`

---

## Task 2: POSIX Threads (C)

### Output — Without Mutex (Race Condition)

![Threads output](screenshots/task2_threads_output.png)

### Output — With Mutex (Correct)

_(Included in screenshot above)_

### Answers

1. **What is a race condition?**
   > A race condition happens when multiple threads read and write `shared_counter` concurrently without synchronization. Because `shared_counter++` is non-atomic (load, increment, store), concurrent updates overwrite each other and produce a lower count than 400,000.

2. **What does `pthread_mutex_lock()` do?**
   > `pthread_mutex_lock()` ensures mutual exclusion by allowing only one thread at a time to enter the critical section and increment `shared_counter`, blocking other threads until `pthread_mutex_unlock()` is called.

3. **Removing `pthread_join()`:**
   > Without `pthread_join()`, the `main` thread does not wait for worker threads to finish; it immediately prints an incomplete counter and exits the process, terminating all running threads prematurely.

4. **Thread vs Process:**
   > Processes have separate virtual address spaces, whereas threads exist within the same process and share code, global data, heap memory, and open files, while each thread maintains its own private stack, registers, and program counter.

---

## Task 3: Java Multithreading

### ThreadDemo Output

![Java threading](screenshots/task3_java_output.png)

### RunnableDemo Output

_(Included in screenshot above)_

### PoolDemo Output

_(Included in screenshot above)_

### Answers

1. **Thread vs Runnable:**
   > Extending `Thread` subclasses the `Thread` class directly, while `Runnable` separates the task from the thread runner. `Runnable` is preferred when a class needs to extend another class or when submitting tasks to an `ExecutorService`.

2. **Pool size limiting concurrency:**
   > `Executors.newFixedThreadPool(2)` creates only 2 worker threads, so at most 2 tasks execute simultaneously while the remaining 4 tasks wait in the pool's queue until a thread becomes free.

3. **thread.join() in Java:**
   > `thread.join()` pauses the `main` thread until the child thread completes. Removing it causes `main` to print `"all threads finished"` before the worker threads finish counting.

4. **ExecutorService advantages:**
   > `ExecutorService` reuses a fixed pool of threads instead of repeatedly creating and destroying OS threads, reducing memory/CPU overhead and preventing system exhaustion under heavy loads.

---

## Task 4: Observing Threads

### Linux — `ps -eLf` Output

See `task2_threads/result_observe_linux.txt`.

### Linux — htop Thread View

![htop threads](screenshots/task4_htop_threads.png)

### Windows — Task Manager

![Task Manager threads](screenshots/task4_taskmanager_threads.png)

### Answers

1. **LWP column meaning:**
   > LWP stands for Light Weight Process and represents the kernel thread ID (TID) scheduled by the Linux kernel for each thread belonging to the process (PID).

2. **/proc/PID/task/ count:**
   > There are 5 entries in `/proc/<PID>/task/`, which matches the 1 main thread plus the 4 worker threads created by the program.

3. **Extra Java threads:**
   > `java.exe` shows more than 3 threads because the JVM creates internal background threads for Garbage Collection (GC), JIT compilation, signal handling, and reference cleanup.

4. **Linux vs Windows thread viewing:**
   > Linux (`ps -eLf`, `/proc/<PID>/task/`, `htop`) provides more granular per-thread detail (individual LWP IDs, states, and CPU usage) directly from the command line, while Windows Task Manager shows the total thread count per process in the Details tab.

---

## Reflection

> Working with TCP sockets and multithreading demonstrated how processes communicate across endpoints and how the OS schedules concurrent threads within a single address space. Observing race conditions firsthand and inspecting LWP entries in `/proc` clarified why synchronization primitives like mutexes and thread pools are essential for reliable concurrent systems.
