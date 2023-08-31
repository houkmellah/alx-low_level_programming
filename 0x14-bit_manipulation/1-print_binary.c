#include "main.h"
/**
* print_binary - Outputs binary of a decimal number.
* @n: Decimal number.
*/
void print_binary(unsigned long int n){
int i,flag=0;
unsigned long int shift;
for(i=63;i>=0;i--){
shift=n>>i;
if(shift&1){
_putchar('1');
flag++;
}else if(flag){
_putchar('0');
}
}
if(!flag)_putchar('0');
}
