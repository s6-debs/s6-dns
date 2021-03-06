/* ISC license. */

#ifndef S6DNS_RCI_H
#define S6DNS_RCI_H

#include <skalibs/stralloc.h>
#include <s6-dns/s6dns-constants.h>
#include <s6-dns/s6dns-ip46.h>
#include <s6-dns/s6dns-domain.h>

 /* rci: resolv.conf information */

typedef struct s6dns_rci_s s6dns_rci_t, *s6dns_rci_t_ref ;
struct s6dns_rci_s
{
  s6dns_ip46list_t servers ;
  stralloc rules ;
  unsigned int rulesnum ;
} ;
#define S6DNS_RCI_ZERO { .servers = S6DNS_IP46LIST_ZERO, .rules = STRALLOC_ZERO, .rulesnum = 0 }

extern s6dns_rci_t const s6dns_rci_zero ;
extern s6dns_rci_t s6dns_rci_here ;
extern int s6dns_rci_init (s6dns_rci_t *, char const *) ;
extern void s6dns_rci_free (s6dns_rci_t *) ;

#define s6dns_qualify(list, d) s6dns_domain_qualify(list, (d), s6dns_rci_here.rules.s, s6dns_rci_here.rulesnum)

#endif
