#ifndef ERROR_H_
#define ERROR_H_

#define PANIC __LINE__, "Internal error", __func__
#define MISS 1, "Implementation missing", __func__

int runtime_error();
int error(int id, 
          const char *type, 
          const char *info);
#endif
