/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:32:20 by yotsubo           #+#    #+#             */
/*   Updated: 2024/09/30 17:32:20 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPE_H
# define ifndef PROTOTYPE_H

# include "struct.h"

void	cleanup_data(t_data *data);

t_data	*init_data(int argc, char **argv);

t_data	*init_error(t_data *data);

int	ft_isdigit(int c);

int	ft_atoi(const char *nptr);

size_t	ft_strlen(const char *s);

int	ft_isspace(char c);



#endif