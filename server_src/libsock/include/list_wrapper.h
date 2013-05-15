

#ifndef		LIST_WRAPPER_H_
# define	LIST_WRAPPER_H_

typedef struct	s_list
{
  struct s_list	*prev;
  struct s_list	*next;
}		t_list;

void		*list_create(size_t size);

void		*list_front(void *ptr);
void		*list_at(unsigned int pos, void *head);
void		*list_back(void *ptr);

void		*list_cpush_front(void *head, size_t size);
void		*list_cpush_insert(void *current, void *head, size_t size);
void		*list_cpush_back(void *head, size_t size);

void		*list_push_front(void *new, void *head);
void		*list_push_insert(void *new, void *current, void *head);
void		*list_push_back(void *new, void *head);

void		*list_pop_front(void *head);
void		*list_pop(void *ptr, void *head);
void		*list_pop_back(void *head);

void		*list_remove_first(void *head, void (*removeFunction)(void *ptr));
void		*list_remove(void *ptr, void *head,
			     void (*removeFunction)(void *ptr));
void		*list_remove_last(void *head, void (*removeFunction)(void *ptr));

void		*list_find_if(void *head, void *arg,
			      char (*predicate)(void *ptr, void *arg));

void		list_foreach(void *head, void *arg,
			     void (*functor)(void *ptr, void *arg));

#endif		
