/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:04:53 by grial             #+#    #+#             */
/*   Updated: 2024/05/07 23:13:35 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;
	char	chr;

	chr = (char) c;
	size = ft_strlen(s) + 1;
	i = 0;
	while (i < size)
	{
		if (s[i] == chr)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char	*str;
	char	to_find;
	char	*myFun;
	char	*memch;

	str = "tripouille";
	to_find = 0;

	myFun = ft_strchr(str, 't' + 256);
	memch = strchr(str, 't' + 256);

	printf("Output ft_strchr: %s\nOutpur strchr:	  %s", myFun, memch);
}*/
