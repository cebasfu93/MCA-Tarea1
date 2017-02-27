oscilador.pdf : plot.py output.txt
	python plot.py

output.txt : a.out
	./a.out > output.txt

a.out : Fermi.c
	gcc -lm Fermi.c

clean :
	rm -f output.txt oscilador.pdf a.out
