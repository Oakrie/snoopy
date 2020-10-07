#include<iostream>
#include "snoopy.h"
#include "snoopylistener.h"
#include "snoopyreader.h"
#include "snoopyqueue.h"
#include "threadable.h"



int main() {
    snoopyqueue q;
    snoopy *_snoopy = new snoopy;
    snoopylistener s(&q, _snoopy);
    snoopyreader r(&q, _snoopy);
    printf("yeet\n");
    _snoopy->start();
    printf("yeet\n");
    return 0;
}
