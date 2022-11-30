/**
 * Definitions for helper functions that simulate a page table.
 *
 * @author Luis A. Gonzalez, Acuna
 * @version 11.28.2022
 */
/*
enum replacement_algorithm {
    FIFO=0,
    LRU,
    MFU
};
*/
#include <PageTable.h>

#define PAGE_TABLE_SIZE 512

struct page_table_entry {
    unsigned short dirty_valid_bit; //set to zero at creation time
    int page_id;
    int frame_assignment;

};

struct page_table {
    int page_count;
    int frame_count;
    enum replacement_algorithm algo_mode;
    int debug_mode;
    struct page_table_entry table_entries[PAGE_TABLE_SIZE];
};

/**
 * Simulates an instruction accessing a particular page in the page table.
 *
 * @param pt A page table object.
 * @param page The page being accessed.
 */
void page_table_access_page(struct page_table *pt, int page)
{
    //this function needs to create page_table_entry's for each page in the page table
    struct page_table_entry* entry = (struct page_table_entry*)malloc(sizeof(struct page_table_entry*));
    entry->page_id = page;
    entry->dirty_valid_bit = 0b01;

    //this function needs to differentiate between the different algorithms using pt->algo_mode
    switch(pt->algo_mode) {

        case FIFO:
            break;
        case LRU:
            break;
        case MFU:
            break;
    }
}

/**
 * Creates a new page table object. Returns a pointer to created page table.
 *
 * @param page_count Number of pages.
 * @param frame_count Numbers of frames.
 * @param algorithm Page replacement algorithm
 * @param verbose Enables showing verbose table contents.
 * @return A page table object.
 */
struct page_table* page_table_create(int page_count, int frame_count, enum replacement_algorithm algorithm, int verbose)
{
    struct page_table* pt = (struct page_table*)malloc(sizeof(struct page_table*));

    pt->page_count = page_count;        //printf("page count: %d\n", pt->page_count);
    pt->frame_count = frame_count;      //printf("frame count: %d\n", pt->frame_count);
    pt->algo_mode = algorithm;          //printf("algorithm: %d\n", pt->algo_mode);
    pt->debug_mode = verbose;           //printf("verbose: %d\n", pt->debug_mode);

    return pt;
}

/**
 * Destorys an existing page table object. Sets outside variable to NULL.
 *
 * @param pt A page table object.
 */
void page_table_destroy(struct page_table** pt)
{
    free(*pt);
    *pt = NULL;
}

/**
 * Displays page table replacement algorithm, number of page faults, and the
 * current contents of the page table.
 *
 * @param pt A page table object.
 */
void page_table_display(struct page_table* pt)
{
    char placeholder[] = "placeholder";
    printf("====Page Table====\n");
    printf("Mode: %s\n", placeholder);
    printf("Page Faults: %s\n", placeholder);
    printf("page frame | dirty valid\n");
    printf("%4d %5d | %5d %5d", 0, 0, 0, 0);
}

/**
 * Displays the current contents of the page table.
 *
 * @param pt A page table object.
 */
void page_table_display_contents(struct page_table *pt)
{
    char placeholder[] = "placeholder";
    printf("====Page Table====\n");
    printf("Mode: %s\n", placeholder);
    printf("Page Faults: %s\n", placeholder);
    printf("page frame | dirty valid\n");
    printf("%4d %5d | %5d %5d", 0, 0, 0, 0);

}