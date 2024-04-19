CL = client
SV = server

CLB = client_bonus
SVB = server_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

OBJC = client.c
OBJS = server.c

OBJCb = client_bonus.c
OBJSb = server_bonus.c

HEDER = minitalk.h
HEDER_B = minitalk_bonus.h
all:$(SV) $(CL) 

$(SV): $(OBJS) $(HEDER)
	$(CC) $(CFLAGS) $(OBJS) -o $@
$(CL): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $@

bonus : $(SVB) $(CLB)

$(SVB): $(OBJSb) $(HEDER_B)
	$(CC) $(CFLAGS) $(OBJSb) -o $@
$(CLB): $(OBJCb)
	$(CC) $(CFLAGS) $(OBJCb) -o $@
clean:
	$(RM) $(CL) $(SV) $(CLB) $(SVB)

fclean: clean

re: fclean all