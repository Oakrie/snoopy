#ifndef SNOOPY
#define SNOOPY
#include <vector>
#include <thread>
#include "threadable.h"

class snoopy{
    public:
        snoopy();
        ~snoopy();
        void addProcess(threadable *processThread);
        void start();
    private:
        std::vector<std::thread> threadlist;
        std::vector<threadable *> threadablelist;
        int numThreads;

};


#endif
