oscilador.pdf energias.pdf movimiento.gif : plot.py energias.txt posiciones.txt
	python plot.py

energias.txt posiciones.txt : a.out
	(time ./a.out 1) > tiempo.txt2>&1
	(time ./a.out 2) >> tiempo.txt2>&1
	(time ./a.out 4) >> tiempo.txt2>&1

a.out : Fermi.c
	gcc Fermi.c -lm -fopenmp

clean :
	rm -rf oscilador.pdf a.out energias.txt posiciones.txt energias.pdf movimiento.gif temp/
