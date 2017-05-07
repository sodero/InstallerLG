#ifndef ERROR_H_
#define ERROR_H_

int runtime_error();
int error(int id, 
          const char *type, 
          const char *info);
#endif
