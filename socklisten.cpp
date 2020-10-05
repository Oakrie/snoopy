#include <netinet/ip.h>    //Provides declarations for ip header
#include <netinet/if_ether.h>  //For ETH_P_ALL
#include <net/ethernet.h>  //For ether_header
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#include "socklisten.h"
#include <errno.h>

#include <cstring>

extern int errno;

socklisten::socklisten(sockqueue *s, threadlist *t){
    _thr = t;
    _que = s;
    buf = new unsigned char[BUF_SIZE];   
    addrlen = new socklen_t;
    addr = new struct sockaddr;
    ICMP_count = 0;
    IGMP_count = 0;
    TCP_count  = 0;
    UDP_count  = 0;
    np_count   = 0;
    _thr->attatch(this);
}

socklisten::~socklisten(){
    delete buf;
    delete addrlen;
    delete addr;
}

void socklisten::run(){
    //open a 
    int sockfd = socket( AF_PACKET , SOCK_RAW , htons(ETH_P_ALL));
    int rc;
    while(1){
        rc = recvfrom(sockfd, buf, BUF_SIZE, 0, addr, addrlen);
        *buf = ntohl((uint32_t)*buf);

        if(rc == -1){
            std::cout <<  errno << " error reading"<< std::endl; 
            return;
        }
        process_packet();
    }
}

void socklisten::process_packet(){
    unsigned short iphdrlen;
    struct iphdr *ip = (struct iphdr*)(buf + sizeof(struct ethhdr));
    switch (ip->protocol)
    {
    case ICMP:
        /* code */
        ICMP_count++;
        load_queue(ip);
        break;
    
    case IGMP:
        /* code */
        IGMP_count++;
        load_queue(ip);
        break;
    
    case TCP:
        /* code */
        TCP_count++;
        load_queue(ip);
        break;

    case UDP:
        /* code */
        UDP_count++;
        load_queue(ip);
        break;
    
    default: //not processing it
        np_count++;
        break;
    }
    printf("ICMP: %d, IGMP: %d, TCP: %d, UDP: %d np: %d\n",ICMP_count, IGMP_count, TCP_count, UDP_count,np_count);
}

void socklisten::load_queue(struct iphdr *ip){
    struct IPPACK *packet = new struct IPPACK;
    packet->ip = new struct iphdr;
    packet->rawpack = new unsigned char [ip->tot_len-ip->ihl];
    memcpy(packet->ip, ip, sizeof(ip));
    memcpy(packet->rawpack, buf+ip->ihl, ip->tot_len-ip->ihl);
    _que->push(packet);
    
}
