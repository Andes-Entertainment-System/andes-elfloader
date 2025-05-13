#include <stdint.h>
#include <stdio.h>

#if defined(__linux__)
#define LOADER_FD_T FILE *
#endif

#if !(defined(__linux__))
#define LOADER_FD_T void *
#endif

typedef struct {
  const char *name; /*!< Name of symbol */
  void *ptr;        /*!< Pointer of symbol in memory */
} ELFLoaderSymbol_t;

typedef struct {
  const ELFLoaderSymbol_t *exported; /*!< Pointer to exported symbols array */
  unsigned int exported_size;        /*!< Elements on exported symbol array */
} ELFLoaderEnv_t;

typedef struct ELFLoaderContext_t ELFLoaderContext_t;

void *elfLoaderGetFunc(ELFLoaderContext_t *ctx, const char *funcname);
ELFLoaderContext_t *elfLoaderInitLoadAndRelocate(LOADER_FD_T fd, const ELFLoaderEnv_t *env);
void elfLoaderFree(ELFLoaderContext_t *ctx);
void *elfLoaderGetTextAddr(ELFLoaderContext_t *ctx);
