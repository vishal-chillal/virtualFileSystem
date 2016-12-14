exe : myReadWrite.o initFS.o readFS.o shell.o
	gcc -o exe myReadWrite.o initFS.o readFS.o shell.o

shell.o : shell.c
	gcc -Wall -Werror -g -c shell.c

myReadWrite.o : myReadWrite.c
	gcc -Wall -Werror -g -c myReadWrite.c


initFS.o : initFS.c
	gcc -Wall -Werror -g -c initFS.c

readFS.o : readFS.c
	gcc -Wall -Werror -g -c readFS.c

woosh :
	rm *.~ *.o exe
clr :
	rm myFileSystem.fs

g :
	ghex myFileSystem.fs
