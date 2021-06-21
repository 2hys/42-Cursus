/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 15:09:48 by jiychoi           #+#    #+#             */
/*   Updated: 2021/06/22 04:59:18 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

# include <signal.h>
# include <unistd.h>
# include "../libft/libft.h"

struct sigaction	sigact_cli_connect;
struct sigaction	sigact_cli_length;
struct sigaction	sigact_cli_string;

#endif