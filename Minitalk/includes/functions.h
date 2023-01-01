
#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structures.h"

//Functions from data_sending.c [       3 functions]

int	send_bit(char unsigned bit, pid_t receiver);

int	send_byte(char unsigned byte, pid_t receiver);

int	send_integer(int unsigned quadruplet, pid_t receiver);

//Functions from debug.c [       1 functions]

void	print_bits(t_byte byte);

//Functions from handlers.c [       1 functions]

void	build_message(int sig, siginfo_t *sigi, void *context);

//Functions from server.c [ 1 function]
void	update_byte(int sig, t_byte *bit, t_byte *byte, int unsigned *received);
#endif
