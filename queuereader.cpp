#include "queuereader.h"
#include <thread>

reader::reader(sockqueue *s, threadlist *t){
    _thr = t;
    _que = s;
    currpack = new struct IPPACK;
    loggerNew = false;
    customNew = false;
    _thr->attatch(this);
}

reader::~reader(){
    if(currpack != nullptr)
        delete currpack;
}

void reader::run(){
    std::thread logThread(&reader::sendlogger, this);
    loggerNew = true;
    logThread.join();
}

void reader::sendlogger(){
    while(1){
        while(!loggerNew);
        printf("Gamer time logger \n");
        loggerNew = false;
    }
}
