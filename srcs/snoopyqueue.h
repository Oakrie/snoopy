#ifndef SOCKQUEUE
#define SOCKQUEUE

#include <netinet/ip.h>    //Provides declarations for ip header
#include <queue>
#include "defines.h"

class snoopyqueue {

    public:
        struct IPPACK *pop();
        void push(struct IPPACK *);
        int size();

    private:
        std::queue <struct IPPACK *> que;


};
#endif
