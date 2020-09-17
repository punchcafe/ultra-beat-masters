ebm.gb : ebm.c
	gcc -o ebm.gb ebm.c

clean: 
	rm ebm.gb

run : ebm.gb
	./ebm.gb
	rm ebm.gb