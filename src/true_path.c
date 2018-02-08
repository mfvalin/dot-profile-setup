#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
int main(int argc , char **argv){
  int i;
  char resolved[MAXPATHLEN];
  char *newline;
  char *path_status;

  if ( argc <2  || ( argc >=1 && *argv[1] == '-' && *(argv[1]+1) == 'h') ){
    fprintf(stderr,"Usage: %s [-n] path\n",argv[0]);
    fprintf(stderr,"      output on stdout will be the true_path with links resolved\n");
    fprintf(stderr,"Usage: %s [-n] path1 .... pathn\n",argv[0]);
    fprintf(stderr,"      output on stderr will be the true_paths with links resolved\n");
    exit(1);
    }
  if( *argv[1] == '-' && *(argv[1]+1) == 'n' ) { newline="\n"; argc-- ; argv++ ; }
  else newline="";

  if ( argc <2 ) exit(1);

  for (i=1;i<argc;i++) {
    path_status=realpath(argv[i],resolved);
    if (path_status==(char*) NULL) {
      fprintf(stderr,"Probleme avec le path %s\n", argv[1]);
      return 1;
    }
    else {
      if (argc==2)
	printf("%s%s",resolved,newline);
      else
	fprintf(stderr,"%s -> %s\n", argv[i], resolved);
    }
  }

  return 0;
}
