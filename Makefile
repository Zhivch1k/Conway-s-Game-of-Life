######################################################################
#                                                                    #
#                        Makefile is created by                      #
#                            Andrii Nyvchyk                          #
#                       for Conway's game of life                    #
#                            implementation                          #
#                                                                    #
######################################################################

##############                Varaibles                 ##############
#                                                                    #
FILES = main game map \

SRC = $(addsuffix .cpp, $(FILES))
OBJ = $(addsuffix .o, $(FILES))

EXEC = game_of_life

FLAGS = -Wall -Wextra -Werror
#                                                                    #
######################################################################

##############                   Rules                  ##############
#                                                                    #
all: $(EXEC)

$(EXEC): $(OBJ)
		@g++ $(FLAGS) -o $(EXEC) $(OBJ)

$(OBJ): $(SRC)
		@g++ -c $(FLAGS) $(SRC)

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(EXEC)

re: fclean all
#                                                                    #
######################################################################
