/* This file was automatically generated.  Do not edit! */
#pragma once

#include <stddef.h>
#include <stdint.h>

void unalignedCpy(void *dest, void *src, size_t n);
void unalignedSet32(void *dest, uint32_t value);
uint32_t unalignedGet32(void *src);
void unalignedSet8(void *dest, uint8_t value);
uint8_t unalignedGet8(void *src);
#define INTERFACE 0
