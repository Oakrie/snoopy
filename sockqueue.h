#ifndef SOCKQUEUE
#include <netinet/ip.h>    //Provides declarations for ip header
#include <queue>
#include "defines.h"


class sockqueue{

    public:
        IPPACK *pop();
        void push(IPPACK *);
        int size();

    private:
        std::queue <IPPACK *> que;


};
#endif
