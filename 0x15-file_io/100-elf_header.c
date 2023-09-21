#include "main.h"

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
 * prtType - printing types
 * @elf_h: ELF_header structure
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
 * prtEntry - printing entry address
 * @elf_h: ELF_header structure
 * Return: void
 */
void prtEntry(Elf64_Ehdr elf_h)
{
	int j = 0, l = 0;
	unsigned char *en = (unsigned char *)&elf_h.e_entry;

	printf("  Entry point address:               ");
	if (elf_h.e_ident[EI_DATA] == ELFDATA2MSB)
	{
		j = 0;
		if (elf_h.e_ident[EI_CLASS] == ELFCLASS64)
			l = 7;
		else
			l = 3;
		while (!en[j])
			j++;
		printf("%x", en[j]);
		j++;
		for (; j <= l; j++)
			printf("%02x", en[j]);
		printf("\n");
	}
	else
	{
		if (elf_h.e_ident[EI_CLASS] == ELFCLASS64)
			j = 7;
		else
			j = 3;
		while (!en[j])
			j--;
		printf("%x", en[j]);
		j--;
		for (; j >= 0; j--)
			printf("%02x", en[j]);
		printf("\n");
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
	prtEntry(elf_h);

	return (0);
}
