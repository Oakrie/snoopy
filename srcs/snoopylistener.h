#ifndef SOCKLISTEN
#define SOCKLISTEN

#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <thread>
#include "snoopyqueue.h"
#include "threadable.h"
#include "snoopy.h"


class snoopylistener : public threadable {

    public:
        snoopylistener(snoopyqueue *s, snoopy *t);
        ~snoopylistener();
        void run();

    private:
        snoopy *_snoopy;
        snoopyqueue *_que;
        void process_packet();
        void load_queue(struct iphdr *ip);
        unsigned char *buf;
        socklen_t *addrlen;
        struct sockaddr *addr;

        uint32_t ICMP_count;
        uint32_t IGMP_count;
        uint32_t TCP_count;
        uint32_t UDP_count;
        uint32_t np_count;
};

#endif 
