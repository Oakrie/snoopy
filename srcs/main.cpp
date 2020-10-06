#include<iostream>
#include "snoopylistener.h"
#include "snoopyreader.h"
#include "threadable.h"



int main() {
    sockqueue q;
    threadlist *t = new threadlist;
    socklisten s(&q, t);
    reader r(&q, t);
    t->start();
    printf("yeet\n");
    return 0;
}
