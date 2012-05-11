#pragma once

#include <Windows.h>
#include <process.h>
#include <vector>

typedef void (*ThreadFuncPtr)(void*);
typedef HANDLE ThreadHandle;
typedef CRITICAL_SECTION CriticalSection;

// The main thread for threads in the thread pool. They use this to spin on the task list and pull off tasks as they
// become available
unsigned int __stdcall ThreadPoolSpinner(void *v);
static void blank(void* f){};

struct Task
{
	ThreadFuncPtr funcPointer;
	void *data;

	Task() : funcPointer(blank), data(0) {}; // rather than crashing with a null function pointer, just call a blank function
	Task(ThreadFuncPtr _thread_func, void *_task_data) : funcPointer(_thread_func), data(_task_data) {};
	~Task() {};
	void Run() { funcPointer(data); }
};

/*
* Thread Pool Algorithm:
	* Step 1: While the pool is alive
	* Step 2: Get the next task from the queue
	* Step 3: Process it
	* Step 4: Back to step 1

* Note: If you initialise the thread pool with 1 thread it is sequential. You can initialise the
* pool with as many threads as you want, but it will only create as many threads as it can.
* Call GetNumThreads() or read the returned value from InitPool(numThreadsRequested) to find how many
* threads we have created
*/
class ThreadPool
{
private:
	std::vector<ThreadHandle> threads;
	CriticalSection taskCS;

	// setting this to false will cause all running threads to finish
	// call SigKill() to set it to false and wait for the threads to finish
	bool alive;

	enum { INITIAL_TASK_LIST_SIZE = 100 };

	// Call these rather than entering/leaving critical section directly. This allows us to change the underlying locking functionality
	// without changing any other code
	inline void Lock() { EnterCriticalSection(&taskCS); }; // Note: EnterCriticalSection() is a blocking function
	inline void Unlock() { LeaveCriticalSection(&taskCS); };

public:
	std::vector<Task> taskList;

	ThreadPool();
	~ThreadPool();
	int GetNumThreads();

	// returns -1 if already initialised and current thread count == threadCount
	// returns 0 if no threads could be created, else returns the maximum number of threads
	// we could create
	int InitPool(int threadCount);

	bool Alive();

	// Added a task (function pointer and data). Returns true if added to task list
	// Returns false and doesnt add task if no function
	bool AddTask(Task k);

	// Gets the next task from the list and returns it. Returns NULL if no tasks
	Task* GetTask();

	// Note: this only tells you if there are tasks available when the function was called
	bool TasksAvailable();

	// Automatically called by destructor. Can call manually if you want to stop all threads
	// This function will wait for threads to finish then close them
	// Call InitPool(threadCount) to reset the pool
	// This shouldn't be called often, only when required (e.g. at end of app)
	void SigKill();
};