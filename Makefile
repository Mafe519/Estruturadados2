all: clear pointers

pointers:
	@echo -e "\nCompilando o exemplo de ponteiros. Programas pointers."
	gcc  Pointers.c -o pointers
	chmod +x pointers

clear:
	@echo -e "\nRemovendo todos os arquivos compilados"
	rm -f pointers