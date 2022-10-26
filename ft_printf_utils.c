/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olahrizi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:23:17 by olahrizi          #+#    #+#             */
/*   Updated: 2022/10/24 07:23:21 by olahrizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		len = ft_strlen(s);
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
	else
		len += ft_putstr("(null)");
	return (len);
}

int	ft_putnbr(int nb)
{
	int len;

	len = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		len = 11;
	}
	else if (nb < 0)
	{
		nb *= -1;
		len += ft_putchar('-');
		len += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	int len;

	len = 0;
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
		len += ft_putnbr(nb % 10);
	}
	else
	{
		len += ft_putchar(nb + '0');
	}
	return (len);
}

int	search(char *str)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_valid_base(char *str)
{
	int	i;

	i = 0;
	if (!str[0] || !str[1])
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			return (0);
		i++;
	}
	if (search(str) > 1)
		return (0);
	return (1);
}

int	ft_putnbr_base(unsigned int nb, char *base)
{
	unsigned int		len;
	int count;

	len = ft_strlen(base);
	count = 0;
	if (is_valid_base(base))
	{
		if (nb < len)
		{
			count += ft_putchar(base[nb]);
		}
		if (nb >= len)
		{
			count += ft_putnbr_base(nb / len, base);
			count += ft_putnbr_base(nb % len, base);
		}
	}
	return (count);
}

int	ft_put_adress(unsigned long nbr, char *base)
{
	unsigned long		len;
	int count;

	len = ft_strlen(base);
	count = 0;
	if (is_valid_base(base))
	{
		if (nbr < len)
		{
			count += ft_putchar(base[nbr]);
		}
		if (nbr >= len)
		{
			count += ft_put_adress(nbr / len, base);
			count += ft_put_adress(nbr % len, base);
		}
	}
	return (count);
}