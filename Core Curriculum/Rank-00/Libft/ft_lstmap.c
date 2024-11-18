#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list	*result;   
    t_list	*new;   

    if (!lst || !f || !del)
        return (NULL);

    result = NULL; 
    while (lst)
    {
        new = ft_lstnew(f(lst->content));
        if (!new) 
        {
            ft_lstclear(&result, del); 
            return (NULL);
        }
        ft_lstadd_back(&result, new); 
        lst = lst->next; 
    }
    return (result); 
}
