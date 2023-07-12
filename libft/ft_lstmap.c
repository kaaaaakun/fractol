/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 14:16:02 by tokazaki          #+#    #+#             */
/*   Updated: 2023/06/04 14:30:50 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_set;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew (f (lst->content));
	if (new_lst == NULL)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		new_set = ft_lstnew (f (lst->content));
		if (new_set == NULL)
		{
			ft_lstclear (&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back (&new_lst, new_set);
		lst = lst->next;
	}
	return (new_lst);
}
//あるリスト構造体を関数fに入れて、その値が入る別のリスト構造体を作成する
//失敗したら、全てfreeする必要がある。
//20:エラー処理
//22:new_lst初期化と構造体を１つ作成(mallocに失敗したらNULLでreturn)
//26:リストの最後まで実行
//28:構造体のmallocをとる
//31:errorだった時のfreeして、NULLをリターン
//34:構造体リストの最後にmallocしたリストを追加する
//35:次のlstに移動する
//37:新しいリスト構造体の先頭アドレスを返す
