#include <elf.h>
#include "main.h"

/**
 * prtMagic - printing magic
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtMagic(Elf64_Ehdr elf_h)
{
	int i = 0;

	printf("  Magic:   ");
	while(i < EI_NIDENT)
	{
		if (i == EI_NIDENT - 1)
			printf("%2.2x\n", elf_h.e_ident[i]);
		else
			printf("%2.2x ", elf_h.e_ident[i]);
		i++;
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
	switch(elf_h.e_ident[EI_CLASS])
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

/**
 * prtData - printing data
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtData(Elf64_Ehdr elf_h)
{
	printf("  Data:                              ");
	switch(elf_h.e_ident[EI_DATA])
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
 * prtVersion - printing version
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtVersion(Elf64_Ehdr elf_h)
{
	printf("  Version:                           %d", elf_h.e_ident[EI_VERSION]);
	if (elf_h.e_ident[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * prtOsAbi - printing OS/ABI
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtOsAbi(Elf64_Ehdr elf_h)
{
	printf("  OS/ABI:                            ");
	switch(elf_h.e_ident[EI_OSABI])
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
		case ELFOSABI_OPENVMS:
			printf("UNIX - VMS\n");
			break;
		case ELFOSABI_NSK:
			printf("UNIX - NSK\n");
			break;
		default:
			printf("<unknown: %x>\n", elf_h.e_ident[EI_OSABI]);
			break;
	}
}

/**
 * prtAbiVersion - printing ABI version
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtAbiVersion(Elf64_Ehdr elf_h)
{
	printf("  ABI Version:                       %d\n", elf_h.e_ident[EI_ABIVERSION]);
}

/**
 * prtType - printing types
 * elf_h: ELF_header structure
 * Return: void
 */
void prtType(Elf64_Ehdr elf_h)
{
	int i = 0;
	char *tp = (char *)&elf_h.e_type;

	printf("  Type:                              ");
	if (elf_h.e_ident[EI_DATA] == ELFDATA2MSB)
		i = 1;
	switch (tp[i])
	{
		case ET_NONE:
			printf("NONE (No file type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unkown>: %x", tp[i]);
			break;
	}
}

/**
 * main - check if elf or not
 * @argc: arg count
 * @argv: arg vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	Elf64_Ehdr elf_h;
	int file;
	ssize_t r_data;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(98);
	}
	r_data = read(file, &elf_h, sizeof(elf_h));
	if (r_data < 1 || r_data != sizeof(elf_h))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (elf_h.e_ident[0] == 0x7f && elf_h.e_ident[1] == 'E'
			&& elf_h.e_ident[2] == 'L' && elf_h.e_ident[3] == 'F')
		printf("ELF Header:\n");
	else
	{
		dprintf(STDERR_FILENO, "%s is not ELF file\n", argv[1]);
		exit(98);
	}

	prtMagic(elf_h);
	prtClass(elf_h);
	prtData(elf_h);
	prtVersion(elf_h);
	prtOsAbi(elf_h);
	prtAbiVersion(elf_h);
	prtType(elf_h);
/*	prtEntry(elf_h);*/

	return (0);
}
