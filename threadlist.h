#ifndef THREADLIST
#define THREADLIST
#include "defines.h"
#include <thread>
#include <mutex>
#include <vector>


class threadlist{
    public:
        threadlist();
        ~threadlist();
        void run();
        void start();
        void attatch(threadlist *t);
    private:
        std::vector<std::thread>t;
        std::vector<threadlist*>classes;
        std::mutex tmutex;
};

#endif
