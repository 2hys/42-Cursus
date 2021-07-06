/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiychoi <jiychoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:59:24 by jiychoi           #+#    #+#             */
/*   Updated: 2021/07/07 01:57:04 by jiychoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_sort(t_dnode *a_head, t_dnode *b_head, t_dnode *inst_head)
{
	if (ps_lstlen(a_head, a_head) < 2)
		ps_operate_two(a_head, b_head, inst_head);
	else if (ps_lstlen(a_head, a_head) < 3)
		ps_operate_three(a_head, b_head, inst_head);
	else
		ps_operate_a(a_head, a_head, b_head, inst_head);
}

void	push_swap(t_dnode *a_head)
{
	t_dnode	*b_head;
	t_dnode	*inst_head;
	int		operation_num;

	if (!ps_init_stack_b(b_head))
		ps_print_and_exit(a_head, 0, 0, "Error");
	if (!ps_init_stack_oper(inst_head))
		ps_print_and_exit(a_head, b_head, 0, "Error");
	ps_quick_sort(a_head, a_head, b_head);
}

int	main(int argc, char *argv[])
{
	t_dnode	*a_head;

	a_head = (t_dnode *)malloc(sizeof(t_dnode));
	if (!a_head)
		ps_print_and_exit(0, 0, 0, "Error");
	if (argc > 1)
	{
		ps_init_stack_a(argc, argv, a_head);
		ps_validate_stack_a(a_head, 0, IF_DUP);
		push_swap(a_head);
	}
	return (0);
}
