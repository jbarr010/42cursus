/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarredo <jbarredo@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:32:29 by jbarredo          #+#    #+#             */
/*   Updated: 2021/08/20 16:44:56 by jbarredo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>

int	ft_isalpha(int c);
int	ft_isdigit (int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_strlen(const char *c);
void *ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t ds);
size_t	ft_strlcat(char *dst, const char *src, size_t ds);
int	ft_toupper(int c);
int	ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int	ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
int	ft_atoi(char *str);
char	*ft_strnstr(const char *h, const char *n, size_t len);

#endif
