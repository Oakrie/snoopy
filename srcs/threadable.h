#ifndef THREADLIST
#define THREADLIST

#include <vector>
#include <thread>
#include "defines.h"

class executioner{
public:
	executioner(){}
	virtual ~executioner(){}
	virtual void EXECRUN(){}
};

#define MAGIC_WORD_FOR_THREAD \
public: void EXECRUN() \
{ \
	try \
	{ \
		run(); \
	} \
	catch(...) \
	{ \
		throw; \
	} \
}


class threadable: virtual public executioner{
    public:
        threadable();
        ~threadable();
        std::thread start();
		void stop();
    private:
		std::thread *_thr;
        static void *_run(threadable *thread);
};

#endif
