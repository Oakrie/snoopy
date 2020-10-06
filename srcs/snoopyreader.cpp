#include <thread>
#include "snoopyreader.h"


snoopyreader::snoopyreader(snoopyqueue *sq, snoopy *s){
    _snoopy = s;
    _snoopyqueue = sq;
    currpack = new struct IPPACK;
    loggerNew = false;
    customNew = false;
    // _thr->attach((void*) &reader::run, this );
}

snoopyreader::~snoopyreader(){
    if(currpack != nullptr)
        delete currpack;
}

void snoopyreader::run(){
    // std::thread logThread(&reader::sendlogger, this);
    loggerNew = true;
    logThread.join();
}

void snoopyreader::sendlogger(){
    while(1){
        while(!loggerNew);
        printf("Gamer time logger \n");
        loggerNew = false;
    }
}
