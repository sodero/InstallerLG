#ifndef ERROR_H_
#define ERROR_H_

#define PANIC __LINE__, "Internal error", __func__
#define MISS 1, "Implementation missing", __func__
#define HALT -1, "Halt", __func__
#define RESET -2, "Reset", __func__

int did_error(void);
int did_halt(void);
int error(int id, 
          const char *type, 
          const char *info);
#endif
