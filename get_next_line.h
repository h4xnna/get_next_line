/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmimouni <hmimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:17 by hmimouni          #+#    #+#             */
/*   Updated: 2024/12/22 05:34:34 by hmimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		len(char *stock_line);
char	*extract_line(char *stock_line);
char	*clear_stock(char *stock_line);
char	*get_next_line(int fd);

#endif