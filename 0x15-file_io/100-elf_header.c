#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void validateElfFile(unsigned char *magicNumbers);
void displayMagicNumbers(unsigned char *magicNumbers);
void displayElfClass(unsigned char *magicNumbers);
void displayDataEncoding(unsigned char *magicNumbers);
void displayElfVersion(unsigned char *magicNumbers);
void displayAbi(unsigned char *magicNumbers);
void displayOSAbi(unsigned char *magicNumbers);
void displayFileType(unsigned int fileType, unsigned char *magicNumbers);
void displayEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers);
void closeElfFile(int fileDescriptor);

void validateElfFile(unsigned char *magicNumbers)
{
int i;
for(i = 0;i < 4;i++)
{
if(magicNumbers[i]!=127&&magicNumbers[i]!='E'&&
magicNumbers[i]!='L'&&magicNumbers[i]!='F'){
dprintf(STDERR_FILENO,"Error: Not an ELF file\n");
exit(98);
}
}
}

void displayMagicNumbers(unsigned char *magicNumbers)
{
int i;
printf(" Magic: ");
for(i = 0;i < EI_NIDENT; i++)
{
printf("%02x" , magicNumbers[i]);
if(i == EI_NIDENT-1)printf("\n");else printf(" ");
}
}

void displayElfClass(unsigned char *magicNumbers)
{
printf(" Class: ");
switch(magicNumbers[EI_CLASS]){
case ELFCLASSNONE:printf("none\n");break;
case ELFCLASS32:printf("ELF32\n");break;
case ELFCLASS64:printf("ELF64\n");break;
default:printf("<unknown: %x>\n",magicNumbers[EI_CLASS]);
}
}

void displayDataEncoding(unsigned char *magicNumbers)
{
printf(" Data: ");
switch(magicNumbers[EI_DATA]){
case ELFDATANONE:printf("none\n");break;
case ELFDATA2LSB:printf("2's complement, little endian\n");break;
case ELFDATA2MSB:printf("2's complement, big endian\n");break;
default:printf("<unknown: %x>\n",magicNumbers[EI_CLASS]);
}
}

void displayElfVersion(unsigned char *magicNumbers)
{
printf(" Version: %d",magicNumbers[EI_VERSION]);
switch(magicNumbers[EI_VERSION]){
case EV_CURRENT:printf(" (current)\n");break;
default:printf("\n");break;
}
}

void displayOSAbi(unsigned char *magicNumbers)
{
printf(" OS/ABI: ");
switch(magicNumbers[EI_OSABI]){
case ELFOSABI_NONE:printf("UNIX - System V\n");break;
case ELFOSABI_HPUX:printf("UNIX - HP-UX\n");break;
case ELFOSABI_NETBSD:printf("UNIX - NetBSD\n");break;
case ELFOSABI_LINUX:printf("UNIX - Linux\n");break;
case ELFOSABI_SOLARIS:printf("UNIX - Solaris\n");break;
case ELFOSABI_IRIX:printf("UNIX - IRIX\n");break;
case ELFOSABI_FREEBSD:printf("UNIX - FreeBSD\n");break;
case ELFOSABI_TRU64:printf("UNIX - TRU64\n");break;
case ELFOSABI_ARM:printf("ARM\n");break;
case ELFOSABI_STANDALONE:printf("Standalone App\n");break;
default:printf("<unknown: %x>\n",magicNumbers[EI_OSABI]);
}
}

void displayAbi(unsigned char *magicNumbers)
{
printf(" ABI Version: %d\n",magicNumbers[EI_ABIVERSION]);
}

void displayFileType(unsigned int fileType, unsigned char *magicNumbers)
{
if(magicNumbers[EI_DATA] == ELFDATA2MSB)
fileType >>= 8;
printf(" Type: ");
switch(fileType){
case ET_NONE:printf("NONE (None)\n");break;
case ET_REL:printf("REL (Relocatable file)\n");break;
case ET_EXEC:printf("EXEC (Executable file)\n");break;
case ET_DYN:printf("DYN (Shared object file)\n");break;
case ET_CORE:printf("CORE (Core file)\n");break;
default:printf("<unknown: %x>\n",fileType);
}
}

void displayEntryPoint(unsigned long int entryPoint, unsigned char *magicNumbers)
{
printf(" Entry point address: ");
if(magicNumbers[EI_DATA] == ELFDATA2MSB){
entryPoint=((entryPoint << 8)&0xFF00FF00)|((entryPoint >> 8)&0xFF00FF);
entryPoint=(entryPoint<<16)|(entryPoint>>16);
}
if(magicNumbers[EI_CLASS] == ELFCLASS32)
printf("%#x\n",(unsigned int)entryPoint);
else
printf("%#lx\n",entryPoint);
}

void closeElfFile(int fileDescriptor)
{
if(close(fileDescriptor) == -1)
{
dprintf(STDERR_FILENO,"Error: Can't close fd %d",fileDescriptor);
exit(98);
}
}

int main(int ac, char **av)
{
int fd;
Elf64_Ehdr header;
if(ac != 2)
{
dprintf(STDERR_FILENO,"Usage: %s file_name\n",av[0]);
exit(98);
}
fd = open(av[1],O_RDONLY);
if(fd ==- 1){
dprintf(STDERR_FILENO,"Error: Can't read file %s\n",av[1]);
exit(98);
}
if(read(fd,&header,sizeof(header)) != sizeof(header)){
dprintf(STDERR_FILENO,"Error: Can't read file %s\n",av[1]);
exit(98);
}
validateElfFile(header.e_ident);
printf("ELF Header:\n");
displayMagicNumbers(header.e_ident);
displayElfClass(header.e_ident);
displayDataEncoding(header.e_ident);
displayElfVersion(header.e_ident);
displayOSAbi(header.e_ident);
displayAbi(header.e_ident);
displayFileType(header.e_type,header.e_ident);
displayEntryPoint(header.e_entry,header.e_ident);
closeElfFile(fd);
return (0);
}
