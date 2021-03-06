/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_left.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tishj <tishj@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/05 20:44:53 by tishj         #+#    #+#                 */
/*   Updated: 2021/03/06 18:41:12 by tishj         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "reigns.h"
#include <unistd.h>

int	key_left(t_reigns* reigns, t_vec* input, char *buf)
{
	(void)buf;
	(void)input;
	if (reigns->input.nav.cursor.x <= 0 && !reigns->input.nav.cursor.y)
		return (RD_IDLE);
	update_cursor(reigns, -1, 0);
	termcmd(MOVE_COLROW, reigns->nav.cursor.x, reigns->nav.cursor.y, 1);
	return (RD_IDLE);
}
