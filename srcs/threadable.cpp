#include "threadable.h"
#include "snoopylistener.h"
#include <iostream>
#include <thread>

threadable::threadable(){
    _thr = nullptr;
}   

threadable::~threadable(){
    
}

std::thread threadable::start(){
    return std::move(std::thread(&threadable::_run, this));
}

void threadable::stop(){
    
}



void *threadable::_run(threadable *thread){
    printf("EXECU\n");
    static_cast<executioner*>(thread)->EXECRUN();
    return 0;
}
