/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reins_print_keycodes.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/13 15:34:46 by tbruinem      #+#    #+#                 */
/*   Updated: 2021/05/18 18:45:46 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <reins_int.h>
#include <reins.h>
#include <fcntl.h>
#include <unistd.h>

int	reins_print_keycodes(t_reins *reins)
{
	static char				buf[1000 + 1];
	int		ret;

	reins_enable(reins);
	while (1)
	{
		ret = read(STDIN_FILENO, buf, 1000);
		print_keycode_formatted(buf, ret);
		util_bzero(buf, ret);
	}
	return (RD_IDLE);
}
