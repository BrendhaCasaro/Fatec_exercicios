target =

help:
	@echo "Use: make run TARGET=<nome_do_arquivo_sem_extensao>"
	@echo "Exemplo: make run TARGET=Cap2"

run:
	@if [ -z "$target" ]; then \
		echo "Erro: TARGET não definido. Use target=<nome_do_arquivo_sem_extensao>"; \
		exit 1; \
	fi

	gcc -o $(target) $(target).c && ./$(target) && rm $(target)
