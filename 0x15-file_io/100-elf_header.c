#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void verify_elf(unsigned char *id);
void display_magic(unsigned char *id);
void display_class(unsigned char *id);
void display_data(unsigned char *id);
void display_version(unsigned char *id);
void display_abi(unsigned char *id);
void display_osabi(unsigned char *id);
void display_file_type(unsigned int type, unsigned char *id);
void display_entry(unsigned long int entry, unsigned char *id);
void close_file(int fd);

void verify_elf(unsigned char *id)
{
int i;
for (i = 0; i < 4; i++)
{
if (id[i] != 127 && id[i] != 'E' && id[i] != 'L' && id[i] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

void display_magic(unsigned char *id)
{
int i;
printf(" Magic: ");
for (i = 0; i < EI_NIDENT; i++)
{
printf("%02x", id[i]);
if (i == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}

void display_class(unsigned char *id)
{
printf(" Class: ");
switch (id[EI_CLASS])
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
printf("<unknown: %x>\n", id[EI_CLASS]);
}
}

void display_data(unsigned char *id)
{
printf(" Data: ");
switch (id[EI_DATA])
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
printf("<unknown: %x>\n", id[EI_CLASS]);
}
}

void display_version(unsigned char *id)
{
printf(" Version: %d", id[EI_VERSION]);
switch (id[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

void display_osabi(unsigned char *id)
{
printf(" OS/ABI: ");
switch (id[EI_OSABI])
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
printf("<unknown: %x>\n", id[EI_OSABI]);
}
}

void display_abi(unsigned char *id)
{
printf(" ABI Version: %d\n", id[EI_ABIVERSION]);
}

void display_file_type(unsigned int type, unsigned char *id)
{
if (id[EI_DATA] == ELFDATA2MSB)
type >>= 8;
printf(" Type: ");
switch (type)
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
printf("<unknown: %x>\n", type);
}
}

void display_entry(unsigned long int entry, unsigned char *id)
{
printf(" Entry point address: ");
if (id[EI_DATA] == ELFDATA2MSB)
{
entry = ((entry << 8) & 0xFF00FF00) |
((entry >> 8) & 0xFF00FF);
entry = (entry << 16) | (entry >> 16);
}
if (id[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)entry);
else
printf("%#lx\n", entry);
}

void close_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(98);
}
}

int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *hdr;
int fd, res;
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
hdr = malloc(sizeof(Elf64_Ehdr));
if (hdr == NULL)
{
close_file(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
res = read(fd, hdr, sizeof(Elf64_Ehdr));
if (res == -1)
{
free(hdr);
close_file(fd);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}
verify_elf(hdr->e_ident);
printf("ELF Header:\n");
display_magic(hdr->e_ident);
display_class(hdr->e_ident);
display_data(hdr->e_ident);
display_version(hdr->e_ident);
display_osabi(hdr->e_ident);
display_abi(hdr->e_ident);
display_file_type(hdr->e_type, hdr->e_ident);
display_entry(hdr->e_entry, hdr->e_ident);
free(hdr);
close_file(fd);
return (0);
}
