
#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structures.h"

//Functions from data_sending.c [       4 functions]

int	send_bit(char unsigned bit, pid_t receiver);

int	send_byte(char unsigned byte, pid_t receiver);

int	send_integer(int unsigned quadruplet, pid_t receiver);

void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received);

//Functions from debug.c [       1 functions]

void	print_bits(t_byte byte);

//Functions from init_sigaction.c [       1 functions]

void	init_sigaction(t_sigaction *action, t_action handler);

#endif
