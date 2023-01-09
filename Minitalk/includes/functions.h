
#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "structures.h"

//Functions from data_receiving.c [       4 functions]

int	update_message(pid_t receiver, int signal);

int	update_length(pid_t receiver, size_t *length, t_byte *received, int signal);

int	update_string(pid_t receiver, t_message *message, int signal);

void	update_byte(t_byte *msg, t_uint *bytes, int signal);

//Functions from data_sending.c [       2 functions]

int	send_string(pid_t receiver, t_byte *str);

int	send_len(pid_t pid, size_t len, t_byte *sent);

//Functions from init.c [       2 functions]

void	init_sigaction(t_sigaction *action, t_action handler);

void	init_message(t_message *message);

//Functions from printing.c [       1 functions]

void	print_message(t_message *message);

#endif
