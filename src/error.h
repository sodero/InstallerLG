#ifndef ERROR_H_
#define ERROR_H_

#define PANIC error(__LINE__, "Internal error", __func__)

int runtime_error();
int error(int id, 
          const char *type, 
          const char *info);
#endif
