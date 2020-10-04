#include<netinet/ip_icmp.h>   //Provides declarations for icmp header
#include<netinet/udp.h>   //Provides declarations for udp header
#include<netinet/tcp.h>   //Provides declarations for tcp header
#include<netinet/ip.h>    //Provides declarations for ip header
#include<netinet/if_ether.h>  //For ETH_P_ALL
#include<net/ethernet.h>  //For ether_header
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/ioctl.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>


class socklisten{

    public:
        socklisten();
        ~socklisten();
        void run();

    private:
        void process_packet();
        unsigned char *buf;
        socklen_t *addrlen;
        struct sockaddr *addr;


        uint32_t ICMP_count;
        uint32_t IGMP_count;
        uint32_t TCP_count;
        uint32_t UDP_count;
        uint32_t np_count;
};

