#include <unistd.h>
#include <stdio.h>
main()
{
int nLCPU = sysconf(_SC_NPROCESSORS_ONLN);
printf("%d",nLCPU);
}
