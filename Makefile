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
	gcc log.h log.c LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	chmod +x linkedlist

clear:
	@echo ""
	@echo "============================================="
	@echo "			     Removendo Programas				"
	@echo "============================================="
	@echo -e "\nRemovendo todos os arquivos compilados"
	rm -f pointers linkedlist

doublylinkedlist:
	@echo "============================================="
	@echo "			       LISTAS DUPLAS			     "
	@echo "============================================="
	@echo "compilando o exemplo de lista simplesmente encadeada"
	gcc log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o Doublylinkedlist
	chmod +x Doublylinkedlist

clear:
	@echo ""
	@echo "============================================="
	@echo "			     Removendo Programas				"
	@echo "============================================="
	@echo -e "\nRemovendo todos os arquivos compilados"
	rm -f pointers Doublylinkedlist

ListaGeneralizada:
	@echo "============================================="
	@echo "			       LISTAS					     "
	@echo "============================================="
	@echo "compilando o exemplo de lista simplesmente encadeada"
	gcc log.h log.c ListaGeneralizada.h ListaGeneralizada.c ListaGeneralizadaTeste.c -o ListaGeneralizada
	chmod +x ListaGeneralizada

clear:
	@echo ""
	@echo "============================================="
	@echo "			     Removendo Programas				"
	@echo "============================================="
	@echo -e "\nRemovendo todos os arquivos compilados"
	rm -f pointers ListaGeneralizada
