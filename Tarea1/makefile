oscilador.pdf : plot.py a.out
	python plot.py

a.out : Fermi.c
	gcc -lm Fermi.c
	time ./a.out 1 > tiempo.txt
	time ./a.out 2 >> tiempo.txt
	time ./a.out 4 >> tiempo.txt

clean :
	rm -rf oscilador.pdf a.out energias.txt posiciones.txt energias.pdf movimiento.gif temp/
