#include "main.h"

/**
 * prtAbiVersion - printing ABI version
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtAbiVersion(Elf64_Ehdr elf_h)
{
	printf("  ABI Version:                       %d\n",
			elf_h.e_ident[EI_ABIVERSION]);
}

/**
 * prtMagic - printing magic
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtMagic(Elf64_Ehdr elf_h)
{
	int i = 0;

	printf("  Magic:   ");
	while (i < EI_NIDENT)
	{
		if (i == EI_NIDENT - 1)
			printf("%2.2x\n", elf_h.e_ident[i]);
		else
			printf("%2.2x ", elf_h.e_ident[i]);
		i++;
	}
}

/**
 * prtData - printing data
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtData(Elf64_Ehdr elf_h)
{
	printf("  Data:                              ");
	switch (elf_h.e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("NONE\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
	}
}

/**
 * prtOsAbi - printing OS/ABI
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtOsAbi(Elf64_Ehdr elf_h)
{
	printf("  OS/ABI:                            ");
	switch (elf_h.e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_AIX:
			printf("UNIX - AIX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_MODESTO:
			printf("UNIX - Modesto\n");
			break;
		case ELFOSABI_OPENBSD:
			printf("UNIX - BSD\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_h.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * prtClass - printing class
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtClass(Elf64_Ehdr elf_h)
{
	printf("  Class:                             ");
	switch (elf_h.e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("NONE\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
	}
}

