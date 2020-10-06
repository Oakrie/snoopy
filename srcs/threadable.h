#ifndef THREADLIST
#define THREADLIST

#include <vector>
#include "defines.h"

class executioner{
    public:
        virtual void EXECUTE();
    
    #define THREADER \
    public: void EXECUTE(){ \
        run(); \
    }

};


class threadable: public executioner{
    public:
        threadlist();
        ~threadlist();
        void start();
    private:
        void *_run(void *thread);
};

#endif
