#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

void prtData(Elf64_Ehdr elf_h);
void prtOsAbi(Elf64_Ehdr elf_h);
void prtMagic(Elf64_Ehdr elf_h);
void prtClass(Elf64_Ehdr elf_h);
void prtAbiVersion(Elf64_Ehdr elf_h);

#endif
