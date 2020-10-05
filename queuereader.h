#ifndef QUEUEREADER
#define QUEUEREADER
#include "sockqueue.h"
#include <thread>
#include "threadlist.h"

class reader : public threadlist{
    public:
        reader(sockqueue *s, threadlist *t);
        ~reader();
        void run();
    private:
        threadlist *_thr;
        sockqueue *_que;
        struct IPPACK *currpack;
        bool loggerNew;
        bool customNew;
        void sendlogger();
        void *sendcustom();
};


#endif