#ifndef SNOOPY
#define SNOOPY
#include <vector>

#include "threadable.h"

class snoopy{
    public:
        snoopy();
        ~snoopy();

        void start();
    private:
        void addProcess(threadable *processThread);
        std::vector<threadable *> threadlist;

};


#endif
