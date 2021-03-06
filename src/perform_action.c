/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perform_action.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 18:25:07 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 00:31:01 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"

t_actionf	get_action(char c)
{
	static const t_actionf	functions[128] = {
		[KEY_CTRL_D] =	&key_eof,
		[KEY_DEL] =		&key_del,
		[KEY_RIGHT] =	&key_right,
		[KEY_LEFT] =	&key_left,
		[KEY_UP] =		&key_up,
		[KEY_DOWN] =	&key_down,
		[KEY_NEWLINE] =	&key_newline,
	};

	return (functions[(int)c]);
}

int		perform_action(t_reigns* reigns, t_vec* input, char *buf)
{
	size_t					i;
	int						state;
	t_actionf				action;

	state = RD_IDLE;
	i = 0;
	while (i < 6)
	{
		action = get_action(buf[i]);
		if (action)
			state = action(reigns, input, buf + i);
		else if (!action && !(buf[i] >= 32 && buf[i] <= 126))
		{
			i++;
			continue;
		}
		else
			state = key_regular(reigns, input, buf);
		if (state != RD_IDLE)
			break ;
		i++;
	}
	return (state);
}