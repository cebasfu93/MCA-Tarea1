oscilador.pdf : plot.py a.out
	python plot.py

a.out : Fermi.c
	gcc -lm Fermi.c
	time ./a.out

clean :
	rm -rf oscilador.pdf a.out energias.txt posiciones.txt energias.pdf temp/
