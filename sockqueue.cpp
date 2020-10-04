#include <netinet/ip.h>    //Provides declarations for ip header
#include <queue>
#include <sys/socket.h> 
#include "sockqueue.h"


IPPACK *sockqueue::pop(){
    //TODO: When multithread add mutex
    IPPACK *ret = que.front();
    que.pop();
    return ret;
}

void sockqueue::push(IPPACK *ip){
    //TODO: When multithread add mutex
    que.push(ip);
}

int sockqueue::size(){
    return que.size();
}
