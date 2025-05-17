#pragma once

#include <stdint.h>
#include <stdio.h>

#define LOADER_FD_T void *
#define ELFLOADER_EXPORT_SYMBOL(name) {#name, (void *)name}

typedef struct {
  const char *name; /*!< Name of symbol */
  void *ptr;        /*!< Pointer of symbol in memory */
} ELFLoaderSymbol_t;

typedef struct {
  const ELFLoaderSymbol_t *exported; /*!< Pointer to exported symbols array */
  unsigned int exported_size;        /*!< Elements on exported symbol array */
} ELFLoaderEnv_t;

typedef struct {
  void *dataHeap;
  void *dataExec;
  int secIdx;
  size_t size;
  off_t relSecIdx;
  struct ELFLoaderSection_t *next;
} ELFLoaderSection_t;

typedef struct {
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
} ELFLoaderContext_t;

void *elfLoaderGetFunc(ELFLoaderContext_t *ctx, const char *funcname);
ELFLoaderContext_t *elfLoaderInitLoadAndRelocate(LOADER_FD_T fd, const ELFLoaderEnv_t *env);
void elfLoaderFree(ELFLoaderContext_t *ctx);
void *elfLoaderGetTextAddr(ELFLoaderContext_t *ctx);
