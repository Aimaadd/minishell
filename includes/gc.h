/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abentaye <abentaye@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:09:37 by gmallet           #+#    #+#             */
/*   Updated: 2024/09/15 12:25:24 by abentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GC_H
# define GC_H

# include <stdlib.h>

typedef struct s_gc_node
{
	struct s_gc_node	*prev;
	struct s_gc_node	*next;
	size_t				size;
}	t_gc_node;

typedef struct s_gb
{
	t_gc_node	*fnode;
	t_gc_node	*lnode;
	size_t		tsize;
	size_t		nb_allocs;
}	t_gcan;

void	gc_init(t_gcan *gcan);
void	*gc_malloc(t_gcan *gcan, size_t size);
void	gc_free(t_gcan *gcan, void **ptr);
void	gc_clean(t_gcan *gcan);

#endif
