#include <thread>
#include "snoopyreader.h"
#include "snoopy.h"


snoopyreader::snoopyreader(snoopyqueue *sq, snoopy *s){
    _snoopy = s;
    _snoopyqueue = sq;
    currpack = new struct IPPACK;
    loggerNew = false;
    customNew = false;
    _snoopy->addProcess((threadable *)this);
}

snoopyreader::~snoopyreader(){
    if(currpack != nullptr)
        delete currpack;
}

void snoopyreader::run(){
    // std::thread logThread(&reader::sendlogger, this);
    loggerNew = true;
    // logThread.join();
}

void snoopyreader::sendlogger(){
    while(1){
        while(!loggerNew);
        printf("Gamer time logger \n");
        loggerNew = false;
    }
}
