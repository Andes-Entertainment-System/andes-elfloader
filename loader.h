#pragma once

#include <stdint.h>
#include <stdio.h>

#define LOADER_FD_T void *
#define ELFLOADER_EXPORT_SYMBOL(name) {#name, (void *)name}

struct ELFLoaderSymbol_t {
  const char *name; /*!< Name of symbol */
  void *ptr;        /*!< Pointer of symbol in memory */
};
typedef struct ELFLoaderSymbol_t ELFLoaderSymbol_t;

struct ELFLoaderEnv_t {
  const ELFLoaderSymbol_t *exported; /*!< Pointer to exported symbols array */
  unsigned int exported_size;        /*!< Elements on exported symbol array */
};
typedef struct ELFLoaderEnv_t ELFLoaderEnv_t;

struct ELFLoaderSection_t {
  void *dataHeap;
  void *dataExec;
  int secIdx;
  size_t size;
  off_t relSecIdx;
  struct ELFLoaderSection_t *next;
};
typedef struct ELFLoaderSection_t ELFLoaderSection_t;

struct ELFLoaderContext_t {
  LOADER_FD_T fd;
  void *exec;
  void *text;
  const ELFLoaderEnv_t *env;

  size_t e_shnum;
  off_t e_shoff;
  off_t shstrtab_offset;

  size_t symtab_count;
  off_t symtab_offset;
  off_t strtab_offset;

  ELFLoaderSection_t *section;
};
typedef struct ELFLoaderContext_t ELFLoaderContext_t;

void *elfLoaderGetFunc(ELFLoaderContext_t *ctx, const char *funcname);
ELFLoaderContext_t *elfLoaderInitLoadAndRelocate(LOADER_FD_T fd, const ELFLoaderEnv_t *env);
void elfLoaderFree(ELFLoaderContext_t *ctx);
void *elfLoaderGetTextAddr(ELFLoaderContext_t *ctx);
