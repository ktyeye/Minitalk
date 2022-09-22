/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeykim <taeykim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 01:22:03 by taeykim           #+#    #+#             */
/*   Updated: 2022/09/23 01:22:58 by taeykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *str);
int		ft_print(const char *str);
char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
void	*ft_bzero(void *dest, size_t len);
int		ft_atoi(const char *str);

#endif