#include "ThreadPool.h"
#include <iostream>

unsigned int __stdcall ThreadPoolSpinner(void *v)
{
	ThreadPool *t = (ThreadPool*)v;
	Task *task = 0;

	while(t->Alive())
	{
		while(t->Alive() && !(task=t->GetTask())); // this spins till we have a task (hence we must also check the task list is alive)

		if(!task) break;

		task->Run();
	}

	return 0;
};

ThreadPool::ThreadPool() : alive(true)
{
	taskList.reserve(INITIAL_TASK_LIST_SIZE); // initially we can hold up to INITIAL_TASK_LIST_SIZE tasks in the list (avoids having to allocate memory when we create a task)
};

ThreadPool::~ThreadPool()
{
	SigKill(); // make sure all threads have stopped
};

int ThreadPool::GetNumThreads() { return threads.size(); };

bool ThreadPool::Alive()
{
	return alive;
}

int ThreadPool::InitPool(int threadCount)
{
	if(threads.size() == threadCount) return -1; // already initialised, dont reinit

	// otherwise there is < or > the thread count we want, so kill all the current threads (if any) and reset
	SigKill();

	int createdThreadCount = 0;

	// create the threads in suspended mode first. We will then start them up all at once
	for(int i=0;i<threadCount;++i)
	{
		ThreadHandle th = (ThreadHandle)_beginthreadex(0, 0, ThreadPoolSpinner, this, CREATE_SUSPENDED, 0);
		if(th)
		{
			threads.push_back(th);
			++createdThreadCount;

			alive = true; // wake up if we can create at least 1 thread
		}
	}

#ifdef _DEBUG
	std::cout << "Threads created: " << createdThreadCount << std::endl;
#endif

	for(unsigned int i=0;i<threads.size();++i) ResumeThread(threads[i]);

	return createdThreadCount;
};

bool ThreadPool::AddTask(Task k)
{
	if(!k.funcPointer) return false;

	Lock();
	taskList.push_back(k);
	//taskList.push(k);
	Unlock();
	return true;
};

Task* ThreadPool::GetTask()
{
	Task *t = 0;

	Lock();
	if(taskList.size())
	{
		t = &taskList.back();
		taskList.pop_back();
		//t = &taskList.front();
		//taskList.pop();
	}
	Unlock();

	return t;
};

bool ThreadPool::TasksAvailable()
{
	Lock();
	bool f = taskList.size()>0;
	Unlock();
	return f;
};

void ThreadPool::FinishAllTasks()
{
	while(TasksAvailable());
};

void ThreadPool::SigKill()
{
	alive = false; // with this set to false the threads will now exit (once they have completed their current jobs)

	// wait for all threads to end (if quick tasks they made have ended already, but we'll wait for them anyway)
	if(threads.size())
	{
		WaitForMultipleObjects(threads.size(), &threads[0], TRUE, INFINITE);
		for(unsigned int i=0;i<threads.size();++i) CloseHandle(threads[i]);
		threads.clear();
	}

	//taskList.clear(); //<- dont clear the task list, this way we can reinitialise the pool with new threads which will complete any previous tasks :)
};