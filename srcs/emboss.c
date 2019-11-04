/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emboss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 20:31:52 by mmaaouni          #+#    #+#             */
/*   Updated: 2019/03/04 01:22:09 by mmaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	apply_emboss(unsigned char **strp, unsigned char *gauss, int i, int j)
{
	unsigned char	*str;

	str = *strp;
	str[4 * (i + 800 * j) + 1] = 2 * (gauss[4 * (i + 1 + 800 * j) + 1] -
	2 * gauss[4 * (i - 1 + 800 * j) + 1] + gauss[4 * (i + 1 + 800 * (j + 1))
	+ 1] + gauss[4 * (i + 1 + 800 * (j - 1)) + 1]) - gauss[4 * (i - 1 + 800
	* (j + 1)) + 1] - gauss[4 * (i - 1 + 800 * (j - 1)) + 1];
	str[4 * (i + 800 * j)] = 2 * (gauss[4 * (i + 1 + 800 * j)]
	- 2 * gauss[4 * (i - 1 + 800 * j)] + gauss[4 * (i + 1 + 800 * (j + 1))]
	+ gauss[4 * (i + 1 + 800 * (j - 1))]) - gauss[4 * (i - 1 + 800 * (j + 1))]
	- gauss[4 * (i - 1 + 800 * (j - 1))];
	str[4 * (i + 800 * j) + 2] = 2 * (gauss[4 * (i + 1 + 800 * j) + 2]
	- 2 * gauss[4 * (i - 1 + 800 * j) + 2] + gauss[4 * (i + 1 + 800
	* (j + 1)) + 2] - gauss[4 * (i + 1 + 800 * (j - 1)) + 2]) - gauss[4 * (i - 1
	+ 800 * (j + 1)) + 2] - gauss[4 * (i - 1 + 800 * (j - 1)) + 2];
}

void	emboss(unsigned char **strp, int mag)
{
	unsigned char	*gauss;
	int				i;
	int				j;
	int				k;

	k = 0;
	gauss = (unsigned char *)malloc(sizeof(unsigned char) * 800 * 800 * 4);
	while (k < mag)
	{
		j = 0;
		copy_image(strp, &gauss);
		while (j < 800)
		{
			i = 0;
			while (i < 800)
			{
				if (i != 0 && i != 799 && j != 0 && j != 799)
					apply_emboss(strp, gauss, i, j);
				i++;
			}
			j++;
		}
		k++;
	}
}
