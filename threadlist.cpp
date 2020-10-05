#include "threadlist.h"


threadlist::threadlist(){
}   

threadlist::~threadlist(){
}


void threadlist::attatch(threadlist* tl){
    classes.push_back(tl);
}

void threadlist::start(){
    for(int i = 0; i < classes.size(); i++){
        printf("TIM\n");
        t.push_back(std::thread(&threadlist::run, classes[i]));
    }
}


void threadlist::run(){
    printf("help");

    // while(1);

}
