all: clear pointers doublylinkedlist

pointers:
	@echo "============================================="
	@echo "			       ponteiros					"
	@echo "============================================="
	@echo -e "\nCompilando o exemplo de ponteiros. Programas pointers."
	gcc  Pointers.c -o pointers
	chmod +x pointers

doublylinkedlist:
	@echo "============================================="
	@echo "			       LISTAS					     "
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
