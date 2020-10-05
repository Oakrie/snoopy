#include<iostream>
#include "socklisten.h"
#include "queuereader.h"
#include "threadlist.h"



int main() {
    sockqueue q;
    threadlist *t = new threadlist;
    socklisten s(&q, t);
    reader r(&q, t);
    t->start();
    printf("yeet\n");
    return 0;
}
