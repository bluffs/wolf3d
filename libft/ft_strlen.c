/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyakdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:03:31 by jyakdi            #+#    #+#             */
/*   Updated: 2016/11/04 18:03:39 by jyakdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i] != 0)
	{
		nb++;
		i++;
	}
	return (nb);
}
