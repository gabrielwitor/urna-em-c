all: urna_em_c

urna_em_c: main.o eleicao.o arquivo.o
	gcc -Wall -o urna_em_c build/main.o build/eleicao.o build/arquivo.o

main.o: main.c
	gcc -c -Wall main.c
	mkdir -p build
	mv main.o build

eleicao.o: eleicao.c 
	gcc -c -Wall eleicao.c
	mkdir -p build
	mv eleicao.o build

arquivo.o: arquivo.c 
	gcc -c -Wall arquivo.c
	mkdir -p build
	mv arquivo.o build

clean:
	rm -rf build
	rm urna_em_c