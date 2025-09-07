main: main.c
	gcc -std=c99 -Iexternal/simple-linear-regression -Iexternal/polyfit/inc -o main main.c external/polyfit/src/polyfit.c

clean:
	rm -f main
