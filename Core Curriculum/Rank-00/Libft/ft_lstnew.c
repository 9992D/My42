#include "Libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *result = (t_list *)malloc(sizeof(t_list));
    if (!result) 
        return (NULL);
    result->content = content;
    result->next = NULL;
    return result;
}