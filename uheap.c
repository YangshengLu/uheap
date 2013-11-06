#include "uheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

heap *__uheap_init_mem (size_t type_len,size_t max_size)
{
        assert (max_size > 0);
        assert (type_len > 0);
        int total = max_size * type_len + sizeof(heap);
        heap *p = malloc (total);
        assert(p);
        memset (p, 0, total);
        p->max_size  = max_size;
        p->size = 0;
        p->type_len = type_len;
        return p;
}

void uheap_insert (uheap *h, void *elem)
{
        int sz = h->size++;
        if (h->size >= h->max_size)
                heap_expand (&h, HEAP_DEFAULT_INCR);    
        while (sz > 0) {
                // min heap
                if (((p->cmpfunc)(__get_elem(h, __uheap_parent(sz))), __get_elem(h, sz)) > 0 ){ 
                        memmove(__get_elem(h, sz), __get_elem(h, __uheap_parent(sz)), h->type_len);
                        // h->arr[sz] = h->arr[(sz - 1)/2];
                        sz = __uheap_parent(sz);
                } else {
                        memmove(__get_elem(h, sz), elem, h->type_len);
                        //h->arr[sz] = n;
                        return;
                }
        }
        memmove(h->arr, elem, h->type_len);
}

void heap_remove (uheap *h, int *n)
{
        h->size--;
        memmove(n, h->arr, h->elem_type);
        //*n = h->arr[0];
        //h->arr[0] = h->arr[h->size];
        memmove(h->arr, __get_elem (h, h->size), h->elem_type);
        //h->arr[h->size] = 0;
        memset()
        int i = 1;
        int cv = h->arr[0];
        while (i < h->size) {
                if (i < (h->size - 1) && h->arr[i] > h->arr[i+1])
                        i++;
                if (h->arr[i] < cv) {
                        h->arr[(i - 1)/2] = h->arr[i];
                        h->arr[i] = cv;
                        i = i * 2 + 1;
                } else {
                        return;
                }
        }
}

void heap_expand (heap **hp, int incr) {
        assert (incr > 0);
        int sz = (*hp)->max_size + incr;
        heap *tmp_heap = realloc (*hp, sizeof(heap) + sz * ((*hp)->type_len) );
        assert (tmp_heap);
        tmp_heap->max_size = sz;
        *hp = tmp_heap;
}
