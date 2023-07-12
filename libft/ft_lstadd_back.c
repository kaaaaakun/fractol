/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 11:34:31 by tokazaki          #+#    #+#             */
/*   Updated: 2023/05/30 13:46:35 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new || !lst)
		return ;
	if (*lst)
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
		return ;
	}
	*lst = new;
}
//リストの一番最後に新しい構造体を繋げる機構
//19-21:エラー処理とlistに何もなかった時の処理
//23:ダブルポインタは使いにくい*lstアドレスをtmpに入れる
//24:ft_lstlastでリストの最後の構造体のアドレスを取得
//25:最後の構造体のnextにnewの構造体のアドレスを入れる
//28:lstがなかった時はnewを先頭にして新たに作る
