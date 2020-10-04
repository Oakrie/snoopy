/*===================================================================
  =                                                                 =
  =                           **MACROS**                            =
  =                                                                 =
  ===================================================================*/


#define BUF_SIZE 65536 //2^16 
#define IPV4 0x04 // start 4 bits of IPv4 Packet

#define VER_POS 0 //VERSION and IHL chunk position
#define PROTO_POS 9 //Protocol version chunk position

#define SRC_IP_POS //Source IP chunk position
#define DST_IP_POS //Destination IP chunk position

enum IPPROTO {
  ICMP = 1,
  IGMP,
  TCP = 6,
  UDP	=17
};