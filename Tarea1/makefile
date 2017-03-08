oscilador.pdf : plot.py a.out
	python plot.py

a.out : Fermi.c
	gcc Fermi.c -lm -fopenmp
	(time ./a.out 1) > tiempo.txt>&1
	(time ./a.out 2) >> tiempo.txt>&1
	(time ./a.out 4) >> tiempo.txt>&1

clean :
	rm -rf oscilador.pdf a.out energias.txt posiciones.txt energias.pdf movimiento.gif temp/
