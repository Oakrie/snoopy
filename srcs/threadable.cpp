#include "threadable.h"
#include "snoopylistener.h"
#include <iostream>

threadable::threadable(){

}   

threadable::~threadable(){
    
}

void threadable::start(){
    std::thread(&threadable::_run, this, this);
}


void *threadable::_run(void *thread){
    static_cast<executioner*>(thread)->EXECUTE();
    return 0;
}
