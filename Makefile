CL = client
SV = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

OBJC = client.c
OBJS = server.c

all:$(SV) $(CL) 

$(SV): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
$(CL): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $@

clean:
	$(RM) $(CL) $(SV)
fclean: clean

re: fclean all