NAME = edcare.out
COMPILER = gcc
FLAGS = -lm -pedantic -Wall

EXEC_DIR = ./bin
OBJ_DIR = ./objects

C_FILES = *.c
O_FILES = *.o

YELLOW = "\033[1;33m"
RED = "\033[1;31m" 
CYAN = "\033[1;36m"
PURPLE = "\033[1;35m"
RESET_COLOR = "\033[0m"


all: clean create_directories $(O_FILES) create_binary

%.o: ./src/%.c ./include/%.h
	@echo $(YELLOW)
	@echo Compilling $(C_FILES) files...
	@$(COMPILER) -c ./src/$(C_FILES) 
	@mv $(O_FILES) $(OBJ_DIR)
	@echo $(RESET_COLOR)

create_directories:
	@echo $(PURPLE)
	@echo Creating and organizing directories...
	@mkdir $(OBJ_DIR)
	@mkdir $(EXEC_DIR)
	@echo $(RESET_COLOR)

create_binary:
	@echo $(YELLOW)
	@echo Creating binary file...
	@$(COMPILER) -o $(EXEC_DIR)/$(NAME) $(OBJ_DIR)/$(O_FILES) $(FLAGS)
	@echo $(RESET_COLOR)

clean:
	@echo $(RED)
	@echo Cleaning tree...
	@rm -rf $(OBJ_DIR) $(EXEC_DIR) *.txt
	@echo $(RESET_COLOR)

run:
	@echo $(CYAN)
	@echo Running program...
	@echo $(RESET_COLOR)
	@./bin/$(NAME) $(r)

valgrind:
	@echo $(CYAN)
	@echo Running valgrind on $(NAME)
	@echo $(RESET_COLOR)
	@valgrind $(EXEC_DIR)/$(NAME)

again: all run