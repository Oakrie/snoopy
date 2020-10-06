#include <netinet/ip.h>    //Provides declarations for ip header
#include <queue>
#include <sys/socket.h> 
#include <thread>
#include "snoopyqueue.h"



struct IPPACK *snoopyqueue::pop(){
    //TODO: When multithread add mutex
    struct IPPACK *ret = que.front();
    que.pop();
    return ret;
}

void snoopyqueue::push(struct IPPACK *ip){
    //TODO: When multithread add mutex
    que.push(ip);
}

int snoopyqueue::size(){
    return que.size();
}
