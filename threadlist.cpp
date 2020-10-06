#include "threadlist.h"
#include "socklisten.h"
#include "queuereader.h"
#include <iostream>

threadlist::threadlist(){
}   

threadlist::~threadlist(){
}


void threadlist::attatch(threadlist* tl){
    classes.push_back(tl);
}

void threadlist::start(){
    for(int i = 0; i < classes.size(); i++){
        t.push_back(std::thread(&threadlist::run, this, classes[i]));
    }
    for(int i = 0; i < classes.size(); i++){
        t[i].join();
    }
}


void threadlist::run(threadlist *that){
    printf("what\n");
    that->start();
    while(1);
}
