/*
 * Part of DNS zone file validator `validns`.
 *
 * Copyright 2011, Anton Berezin <tobez@tobez.org>
 * Modified BSD license.
 * (See LICENSE file in the distribution.)
 *
 */
#ifndef _TEXTPARSE_H_
#define _TEXTPARSE_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct binary_data {
	int length;
	char *data;
};

int empty_line_or_comment(char *s);
char *skip_white_space(char *s);
char *extract_name(char **input, char *what);
char *extract_label(char **input, char *what, void *is_temporary);
long long extract_integer(char **input, char *what);
long extract_timevalue(char **input, char *what);
long extract_timestamp(char **input, char *what);
uint32_t extract_ip(char **input, char *what);
int extract_ipv6(char **input, char *what, struct in6_addr *addr);
struct binary_data extract_base64_binary_data(char **input, char *what);
struct binary_data extract_text(char **input, char *what);
struct binary_data extract_hex_binary_data(char **input, char *what);

/* for NSEC/NSEC3 sets */
struct binary_data new_set(void);
void add_bit_to_set(struct binary_data *set, int bit);
struct binary_data compressed_set(struct binary_data *set);

#endif
