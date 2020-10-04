#include<netinet/ip.h>    //Provides declarations for ip header
#include<netinet/if_ether.h>  //For ETH_P_ALL
#include<net/ethernet.h>  //For ether_header
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include <iostream>

#include "socklisten.h"
#include "defines.h"
#include <errno.h>

extern int errno;

socklisten::socklisten(){
    buf = new unsigned char[BUF_SIZE];   
    addrlen = new socklen_t;
    addr = new struct sockaddr;
    ICMP_count = 0;
    IGMP_count = 0;
    TCP_count  = 0;
    UDP_count  = 0;
    np_count   = 0;
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
    
    rc = recvfrom(sockfd, buf, BUF_SIZE, 0, addr, addrlen);
    *buf = ntohl((uint32_t)*buf);

    if(rc == -1){
        std::cout <<  errno << " error reading"<< std::endl; 
        return;
    }
    process_packet();
}

void socklisten::process_packet(){
    unsigned short iphdrlen;
    struct iphdr *ip = (struct iphdr*)(buf + sizeof(struct ethhdr));
    
    switch (ip->protocol)
    {
    case ICMP:
        /* code */
        ICMP_count++;
        break;
    
    case IGMP:
        /* code */
        IGMP_count++;
        break;
    
    case TCP:
        /* code */
        TCP_count++;
        break;

    case UDP:
        /* code */
        UDP_count++;
        break;
    
    default: //not processing it
        np_count++;
        break;
    }
    printf("ICMP: %d, IGMP: %d, TCP: %d, UDP: %d np: %d\n",ICMP_count, IGMP_count, TCP_count, UDP_count,np_count);
}

