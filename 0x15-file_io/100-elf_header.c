#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *tumbo);
void print_magic(unsigned char *tumbo);
void print_class(unsigned char *tumbo);
void print_data(unsigned char *tumbo);
void print_version(unsigned char *tumbo);
void print_abi(unsigned char *tumbo);
void print_osabi(unsigned char *tumbo);
void print_type(unsigned int e_type, unsigned char *tumbo);
void print_entry(unsigned long int e_entry, unsigned char *tumbo);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @tumbo: A pointer to an array containing the ELF file
 *
 * Description: when the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *tumbo)
{
	int a;

	for (a = 0; a < 4; a++)
	{
		while (tumbo[a] != 127 &&
		    tumbo[a] != 'E' &&
		    tumbo[a] != 'L' &&
		    tumbo[a] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF file.
 * @tumbo: A pointer to an array containing the ELF magic.
 *
 * Description: Magic numbers are good and separated by space i between them
 */
void print_magic(unsigned char *tumbo)
{
	int a;

	printf("  Magic:   ");

	for (a = 0; a < EI_NIDENT; a++)
	{
		printf("%02x", e_ident[a]);

		if (a == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the class of an ELF file.
 * @tumbo: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *tumbo)
{
	printf("  Class:                             ");

	switch (tumbo[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", tumbo[EI_CLASS]);
	}
}

/**
 * print_data - Prints the data of an ELF file.
 * @tumbo: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *tumbo)
{
	printf("  Data:                              ");

	switch (tumbo[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", tumbo[EI_CLASS]);
	}
}

/**
 * print_version - Prints the  ELF file.
 * @tumbo: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *tumbo)
{
	printf("  Version:                           %d",
	       tumbo[EI_VERSION]);

	switch (tumbo[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF
 * @tumbo: A pointer to an array 
 */
void print_osabi(unsigned char *tumbo)
{
	printf("  OS/ABI:                            ");

	switch (tumbo[EI_OSABI])
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
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", tumbo[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI of an ELF header.
 * @tumbo: A pointer to an array containing the ELF ABI
 */
void print_abi(unsigned char *tumbo)
{
	printf("  ABI Version:                       %d\n",
	       tumbo[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of ELF.
 * @e_type: The ELF type.
 * @tumbo: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *tumbo)
{
	while (tumbo[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
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
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF.
 * @e_entry: The address of the ELF entry point.
 * @tumbo: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *tumbo)
{
	printf("  Entry point address:               ");

	if (tumbo[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (tumbo[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close an ELF file.
 * @elf: The file d of the ELF file.
 *
 * Description: When the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	while (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Entry of information
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *buffer;
	int openn, readd;

	openn = open(argv[1], O_RDONLY);
	if (openn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	buffer = malloc(sizeof(Elf64_Ehdr));
	if (buffer == NULL)
	{
		close_elf(openn);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	readd = read(openn, buffer, sizeof(Elf64_Ehdr));
	if (readd == -1)
	{
		free(buffer);
		close_elf(openn);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(buffer->tumbo);
	printf("ELF Header:\n");
	print_magic(buffer->tumbo);
	print_class(buffer->tumbo);
	print_data(buffer->tumbo);
	print_version(buffer->tumbo);
	print_osabi(buffer->tumbo);
	print_abi(buffer->tumbo);
	print_type(buffer->e_type, buffer->tumbo);
	print_entry(buffer->e_entry, buffer->tumbo);

	free(buffer);
	close_elf(openn


);
	return (0);
}
