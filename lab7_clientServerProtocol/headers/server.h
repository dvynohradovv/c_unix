#if !defined SERVRELATED_
#define SERVRELATED_

#define PERM_FILE S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#define FOUND "File was found."
#define NOTFOUND "File wasn't found."

int SERVER();
void check_if_ret(int rd_desc);
void check_if_written(int wr_desc);
void check_if_fifo_created(int created);
void check_if_fifo_opened(int opened);

#endif
