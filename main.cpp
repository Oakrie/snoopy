#include<iostream>
#include "socklisten.h"

int main() {
    sockqueue q;
    socklisten s(&q);
    s.run();
    return 0;
}
