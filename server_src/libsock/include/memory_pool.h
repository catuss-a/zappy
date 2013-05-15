

#ifndef			MY_MEMORY_POOL_H_
# define		MY_MEMORY_POOL_H_

# define LIMIT_ALLOC	(1 << 24)

typedef struct		s_mempool
{
  void			*pool;
  unsigned int		nb_block;
  size_t		block_size;
  unsigned int		*alloc;
}			t_mempool;

void		*create_memory_pool(t_mempool *mempool, size_t size,
				    size_t block_size);
void		*alloc_block_in_pool(t_mempool *mempool, unsigned int nb_block);
void		*alloc_in_pool(t_mempool *mempool, size_t size);
void		print_alloc_table(t_mempool *mempool);
void		print_block_information(t_mempool *mempool, void *ptr);
void		free_from_pool(t_mempool *mempool, void *ptr);
void		*free_block_from_pool(t_mempool *mempool, void *ptr,
				      unsigned int nb_block);
void		*realloc_block_in_pool(t_mempool *mempool, void *ptr,
				       unsigned int nb_block);
void		*realloc_in_pool(t_mempool *mempool, void *ptr, size_t size);
size_t		get_buffer_size(t_mempool *mempool, void *ptr);
unsigned int	get_nb_block_from_size(t_mempool *mempool, size_t size);
size_t		get_memory_pool_size(t_mempool *mempool);
void		clear_memory_pool(t_mempool *mempool);
void		clear_buffer_in_pool(t_mempool *mempool, void *ptr);
void		destroy_memory_pool(t_mempool *mempool);

#endif			
