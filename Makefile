all: clear pointers linkedlist

pointers:
	@echo "============================================="
	@echo "			       ponteiros					"
	@echo "============================================="
	@echo -e "\nCompilando o exemplo de ponteiros. Programas pointers."
	gcc  Pointers.c -o pointers
	chmod +x pointers

linkedlist:
	@echo "============================================="
	@echo "			       LISTAS					     "
	@echo "============================================="
	@echo "compilando o exemplo de lista simplesmente encadeada"
	gcc LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	chmod +x linkedlist

clear:
	@echo ""
	@echo "============================================="
	@echo "			     Removendo Programas				"
	@echo "============================================="
	@echo -e "\nRemovendo todos os arquivos compilados"
	rm -f pointers linkedlist