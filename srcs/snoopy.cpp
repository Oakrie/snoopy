#include "snoopy.h"
#include "threadable.h"

snoopy::snoopy(){
    numThreads = 0;
}

snoopy::~snoopy(){
    
}

void snoopy::addProcess(threadable *processThread){
    threadablelist.push_back(processThread);
}


void snoopy::start(){
    for(int i=0; i<threadablelist.size(); i++){
        std::thread tmpThread = threadablelist[i]->start();
        threadlist.push_back(std::move(tmpThread));
    }
    for(int i=0; i<threadlist.size(); i++){
        threadlist[i].join();
    }
    //keep main thread from terminating
    while(1);
}
