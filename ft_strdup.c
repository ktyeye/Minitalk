/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:18:54 by taeykim           #+#    #+#             */
/*   Updated: 2022/09/23 01:18:58 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *str)
{
	char	*temp;
	size_t	index;

	temp = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!temp)
		return (0);
	index = 0;
	while (index < ft_strlen(str))
	{
		temp[index] = str[index];
		index++;
	}
	temp[index] = 0;
	return (temp);
}
