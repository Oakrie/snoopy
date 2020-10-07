#ifndef QUEUEREADER
#define QUEUEREADER
#include <thread>
#include "snoopy.h"
#include "threadable.h"
#include "snoopyqueue.h"

class snoopyreader : public threadable{
    MAGIC_WORD_FOR_THREAD;
    public:
        snoopyreader(snoopyqueue *sq, snoopy *s);
        ~snoopyreader();
        void run();
    private:
        snoopy *_snoopy;
        snoopyqueue *_snoopyqueue;
        struct IPPACK *currpack;
        bool loggerNew;
        bool customNew;
        void sendlogger();
        void *sendcustom();
};

#endif