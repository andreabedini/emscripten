
#ifndef _NET_NETINET_IN_H
#define _NET_NETINET_IN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <arpa/inet.h>
#include <stdint.h>

enum {
    IPPROTO_IP = 0,
#define IPPROTO_IP              IPPROTO_IP
    IPPROTO_HOPOPTS = 0,
#define IPPROTO_HOPOPTS         IPPROTO_HOPOPTS
    IPPROTO_ICMP = 1,
#define IPPROTO_ICMP            IPPROTO_ICMP
    IPPROTO_IGMP = 2,
#define IPPROTO_IGMP            IPPROTO_IGMP
    IPPROTO_IPIP = 4,
#define IPPROTO_IPIP            IPPROTO_IPIP
    IPPROTO_TCP = 6,
#define IPPROTO_TCP             IPPROTO_TCP
    IPPROTO_EGP = 8,
#define IPPROTO_EGP             IPPROTO_EGP
    IPPROTO_PUP = 12,
#define IPPROTO_PUP             IPPROTO_PUP
    IPPROTO_UDP = 17,
#define IPPROTO_UDP             IPPROTO_UDP
    IPPROTO_IDP = 22,
#define IPPROTO_IDP             IPPROTO_IDP
    IPPROTO_TP = 29,
#define IPPROTO_TP              IPPROTO_TP
    IPPROTO_DCCP = 33,
#define IPPROTO_DCCP            IPPROTO_DCCP
    IPPROTO_IPV6 = 41,
#define IPPROTO_IPV6            IPPROTO_IPV6
    IPPROTO_ROUTING = 43,
#define IPPROTO_ROUTING         IPPROTO_ROUTING
    IPPROTO_FRAGMENT = 44,
#define IPPROTO_FRAGMENT        IPPROTO_FRAGMENT
    IPPROTO_RSVP = 46,
#define IPPROTO_RSVP            IPPROTO_RSVP
    IPPROTO_GRE = 47,
#define IPPROTO_GRE             IPPROTO_GRE
    IPPROTO_ESP = 50,
#define IPPROTO_ESP             IPPROTO_ESP
    IPPROTO_AH = 51,
#define IPPROTO_AH              IPPROTO_AH
    IPPROTO_ICMPV6 = 58,
#define IPPROTO_ICMPV6          IPPROTO_ICMPV6
    IPPROTO_NONE = 59,
#define IPPROTO_NONE            IPPROTO_NONE
    IPPROTO_DSTOPTS = 60,
#define IPPROTO_DSTOPTS         IPPROTO_DSTOPTS
    IPPROTO_MTP = 92,
#define IPPROTO_MTP             IPPROTO_MTP
    IPPROTO_ENCAP = 98,
#define IPPROTO_ENCAP           IPPROTO_ENCAP
    IPPROTO_PIM = 103,
#define IPPROTO_PIM             IPPROTO_PIM
    IPPROTO_COMP = 108,
#define IPPROTO_COMP            IPPROTO_COMP
    IPPROTO_SCTP = 132,
#define IPPROTO_SCTP            IPPROTO_SCTP
    IPPROTO_UDPLITE = 136,
#define IPPROTO_UDPLITE         IPPROTO_UDPLITE
    IPPROTO_RAW = 255,
#define IPPROTO_RAW             IPPROTO_RAW
    IPPROTO_MAX
};

#define INET_ADDRSTRLEN 16
#define INET6_ADDRSTRLEN 46

#define INADDR_ANY 0
#define INADDR_LOOPBACK 0x7f000001 /* 127.0.0.1 */

struct in_addr {
  unsigned long s_addr;
};

struct sockaddr_in {
  int            sin_family;
  unsigned short sin_port;
  struct in_addr sin_addr;
  char           sin_zero[6];
};

struct in6_addr {
  union {
    uint8_t _s6_addr8[16];
    uint16_t _s6_addr16[8];
    uint32_t _s6_addr32[4];
  } _u;
#define s6_addr _u._s6_addr8
#define s6_addr16 _u._s6_addr16
#define s6_addr32 _u._s6_addr32
};

extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;
extern const struct in6_addr in6addr_linklocal_allnodes;
extern const struct in6_addr in6addr_linklocal_allrouters;
extern const struct in6_addr in6addr_interfacelocal_allnodes;
extern const struct in6_addr in6addr_interfacelocal_allrouters;
extern const struct in6_addr in6addr_sitelocal_allrouters;

#define IN6ADDR_ANY_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } } }
#define IN6ADDR_LOOPBACK_INIT { { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }
#define IN6ADDR_LINKLOCAL_ALLNODES_INIT \
	{ { { 0xff,2,0,0,0,0,0,0,0,0,0,0,0,0,0,1 } } }
#define IN6ADDR_LINKLOCAL_ALLROUTERS_INIT \
	{ { { 0xff,2,0,0,0,0,0,0,0,0,0,0,0,0,0,2 } } }

struct sockaddr_in6 {
  int             sin6_family;
  unsigned short  sin6_port;
  int             sin6_flowinfo;
  struct in6_addr sin6_addr;
  int             sin6_scope_id;
};

struct ip_mreq {
  struct in_addr imr_multiaddr;
  struct in_addr imr_interface;
};

#define IP_PMTUDISC_DONT          0
#define IP_PMTUDISC_WANT          1
#define IP_PMTUDISC_DO            2
#define IP_PMTUDISC_PROBE         3

#define IP_MULTICAST_IF 32
#define IP_MULTICAST_TTL 33
#define IP_MULTICAST_LOOP 34
#define IP_ADD_MEMBERSHIP 35
#define IP_DROP_MEMBERSHIP 36
#define IP_UNBLOCK_SOURCE 37
#define IP_BLOCK_SOURCE 38
#define IP_ADD_SOURCE_MEMBERSHIP 39
#define IP_DROP_SOURCE_MEMBERSHIP 40
#define IP_MSFILTER 41
#define MCAST_JOIN_GROUP 42
#define MCAST_BLOCK_SOURCE 43
#define MCAST_UNBLOCK_SOURCE 44
#define MCAST_LEAVE_GROUP 45
#define MCAST_JOIN_SOURCE_GROUP 46
#define MCAST_LEAVE_SOURCE_GROUP 47
#define MCAST_MSFILTER 48
#define IP_MULTICAST_ALL 49
#define IP_UNICAST_IF 50

/*
 * Tests for IPv6 address types
 */

#define	IN6_IS_ADDR_LINKLOCAL(addr) \
       	(((addr)->s6_addr32[0] & htonl(0xffc00000)) == htonl(0xfe800000))

#define	IN6_IS_ADDR_LOOPBACK(addr) \
       	(((addr)->s6_addr32[0] == 0) && ((addr)->s6_addr32[1] == 0) && \
	 ((addr)->s6_addr32[2] == 0) && ((addr)->s6_addr32[3] == htonl(1)))

#define	IN6_IS_ADDR_MULTICAST(addr) \
       	((addr)->s6_addr8[0] == 0xff)
	
#define	IN6_IS_ADDR_SITELOCAL(addr) \
       	(((addr)->s6_addr32[0] & htonl(0xffc00000)) == htonl(0xfec00000))

#define	IN6_IS_ADDR_UNSPECIFIED(addr) \
       	(((addr)->s6_addr32[0] == 0) && ((addr)->s6_addr32[1] == 0) && \
	 ((addr)->s6_addr32[2] == 0) && ((addr)->s6_addr32[3] == 0))

#define	IN6_IS_ADDR_V4COMPAT(addr) \
       	(((addr)->s6_addr32[0] == 0) && ((addr)->s6_addr32[1] == 0) && \
	 ((addr)->s6_addr32[2] == 0) && ((addr)->s6_addr32[3] & ~htonl(1)))

#define	IN6_IS_ADDR_V4MAPPED(addr) \
       	(((addr)->s6_addr32[0] == 0) && ((addr)->s6_addr32[1] == 0) && \
	 ((addr)->s6_addr32[2] == htonl(0xffff)))

#define	IN6_ARE_ADDR_EQUAL(addr1, addr2) \
       	(((addr1)->s6_addr32[0] == (addr2)->s6_addr32[0]) && \
	 ((addr1)->s6_addr32[1] == (addr2)->s6_addr32[1]) && \
	 ((addr1)->s6_addr32[2] == (addr2)->s6_addr32[2]) && \
	 ((addr1)->s6_addr32[3] == (addr2)->s6_addr32[3]))

/*
 * IPv6 Multicast scoping.  The scope is stored
 * in the bottom 4 bits of the second byte of the
 * multicast address.
 */
		     /* 0x0 */	/* reserved */
#define	IN6_NODE_LOCAL	0x1	/* node-local scope */
#define	IN6_LINK_LOCAL	0x2	/* link-local scope */
		     /* 0x3 */	/* (unassigned) */
		     /* 0x4 */	/* (unassigned) */
#define	IN6_SITE_LOCAL	0x5	/* site-local scope */
		     /* 0x6 */	/* (unassigned) */
		     /* 0x7 */	/* (unassigned) */
#define	IN6_ORG_LOCAL	0x8	/* organization-local scope */
		     /* 0x9 */	/* (unassigned) */
		     /* 0xA */	/* (unassigned) */
		     /* 0xB */	/* (unassigned) */
		     /* 0xC */	/* (unassigned) */
		     /* 0xD */	/* (unassigned) */
#define	IN6_GLOBAL	0xE	/* global scope */
		     /* 0xF */	/* reserved */

#define	IN6_MSCOPE(addr)	((addr)->s6_addr8[1] & 0x0f)

#define	IN6_IS_ADDR_MC_NODELOCAL(addr) \
       	(IN6_IS_ADDR_MULTICAST(addr) && (IN6_MSCOPE(addr) == IN6_NODE_LOCAL))
#define	IN6_IS_ADDR_MC_LINKLOCAL(addr) \
       	(IN6_IS_ADDR_MULTICAST(addr) && (IN6_MSCOPE(addr) == IN6_LINK_LOCAL))
#define	IN6_IS_ADDR_MC_SITELOCAL(addr) \
       	(IN6_IS_ADDR_MULTICAST(addr) && (IN6_MSCOPE(addr) == IN6_SITE_LOCAL))
#define	IN6_IS_ADDR_MC_ORGLOCAL(addr) \
       	(IN6_IS_ADDR_MULTICAST(addr) && (IN6_MSCOPE(addr) == IN6_ORG_LOCAL))
#define	IN6_IS_ADDR_MC_GLOBAL(addr) \
       	(IN6_IS_ADDR_MULTICAST(addr) && (IN6_MSCOPE(addr) == IN6_GLOBAL))

#ifdef __cplusplus
}
#endif

#endif

