CFLAGS = -Wall -Werror -Wextra
SRCS = srcs/
FT_PRINTF = ft_printf/

all: server client

server: printf
	gcc $(CFLAGS) $(SRCS)server.c $(FT_PRINTF)libftprintf.a -o server

client: printf
	gcc $(CFLAGS) $(SRCS)client.c $(FT_PRINTF)libftprintf.a -o client

printf:
	make re -C $(FT_PRINTF)

clean:
	make clean -C $(FT_PRINTF)

fclean:
	make fclean -C $(FT_PRINTF)
	rm -f server
	rm -f client

re: fclean all

.PHONY: all server client printf clean fclean re