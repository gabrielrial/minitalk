/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grial <grial@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:55:12 by grial             #+#    #+#             */
/*   Updated: 2024/05/15 12:03:53 by grial            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_hexadecimal(unsigned int i)
{
	char	*hex;

	hex = "0123456789abcdef";
	return (hex[i]);
}