#include "snoopy.h"
#include "threadable.h"

snoopy::snoopy(){

}

snoopy::~snoopy(){
    
}

void snoopy::addProcess(threadable *processThread){
    threadlist.push_back(processThread);
}


void snoopy::start(){
    for(int i=0; i<threadlist.size(); i++){
        threadlist[i]->start();
    }
    //keep main thread from terminating
    while(1);
}
