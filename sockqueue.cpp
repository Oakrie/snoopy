#include <netinet/ip.h>    //Provides declarations for ip header
#include <queue>
#include <sys/socket.h> 
#include <thread>
#include "sockqueue.h"



struct IPPACK *sockqueue::pop(){
    //TODO: When multithread add mutex
    struct IPPACK *ret = que.front();
    que.pop();
    return ret;
}

void sockqueue::push(struct IPPACK *ip){
    //TODO: When multithread add mutex
    que.push(ip);
}

int sockqueue::size(){
    return que.size();
}
