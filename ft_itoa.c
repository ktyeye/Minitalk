/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:18:22 by taeykim           #+#    #+#             */
/*   Updated: 2022/09/23 01:18:30 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	count_line(int n)
{
	unsigned int	index;

	index = 0;
	while (n)
	{
		n /= 10;
		index++;
	}
	return (index);
}

static void	itoc(int n, char *str, unsigned int index)
{
	if (n >= 10)
	{
		itoc(n / 10, str, index - 1);
		str[index] = (n % 10) + '0';
	}
	else
		str[index] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;

	sign = 0;
	size = count_line(n);
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		size++;
		sign = 1;
	}
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	if (sign)
		str[0] = '-';
	itoc(n, str, size - 1);
	str[size] = 0;
	return (str);
}
