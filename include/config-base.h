#ifndef __CR_CONFIG_BASE_H__
#define __CR_CONFIG_BASE_H__

#define PAGE_ALLOC_COSTLY_ORDER 3 /* from the kernel source code */
struct kernel_pipe_buffer {
        struct page *page;
        unsigned int offset, len;
        const struct pipe_buf_operations *ops;
        unsigned int flags;
        unsigned long private;
};

/*
 * The kernel allocates the linear chunk of memory for pipe buffers.
 * Allocation of chunks with size more than PAGE_ALLOC_COSTLY_ORDER
 * fails very often, so we need to restrict the pipe capacity to not
 * allocate big chunks.
 */
#define PIPE_MAX_SIZE ((1 << PAGE_ALLOC_COSTLY_ORDER) * PAGE_SIZE /	\
			sizeof(struct kernel_pipe_buffer))

/* The number of pipes for one chunk */
#define NR_PIPES_PER_CHUNK 8


#endif
