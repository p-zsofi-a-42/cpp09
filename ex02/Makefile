#----------------------------------FILES----------------------------------------
SRC_MAN	=	\
			main.cpp\
			PmergeMe.cpp\
			Jacobstahl.cpp\
			pendMain.cpp\
			printer.cpp\
#			tests.cpp\

OBJ_DIR		= build
BUG_DIR		= build_debug
OBJECTS 	= $(addprefix $(OBJ_DIR)/, $(SRC_MAN:.cpp=.o))
BUG_OBJ 	= $(addprefix $(BUG_DIR)/, $(SRC_MAN:.cpp=.o))
#----automatic dependency generation----
DEP_FLAGS	= -MMD -MP
DEPS 		= $(OBJECTS:.o=.d)
BUG_DEPS 	= $(BUG_OBJ:.o=.d)

#----------------------------COMPILER SETTINGS----------------------------------
PROG_NAME		= PmergeMe
BUG_PROG_NAME	= $(PROG_NAME)_debug
CXX				= c++
C_FLAGS			= -Wall -Wextra -Werror -std=c++98 $(DEP_FLAGS)
DEBUG_FLAGS		= $(C_FLAGS) -g -fsanitize=undefined,address -DDEBUG=1

#---------------------------------COLORS----------------------------------------
GREEN_B	= "\033[1;32m"
ENDCLR	= "\33[m"

#---------------------------------TARGETS---------------------------------------
all:	$(PROG_NAME)
-include $(DEPS)
#---version with constructor logs and -g flag
debug:	$(BUG_PROG_NAME)
-include $(BUG_DEPS)
#---deletes all object files and file called log
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BUG_DIR)
	@rm -rf log
#---calls clean target then deletes PROG_NAME
fclean:		clean
	@rm -f $(PROG_NAME)
	@rm -f $(BUG_PROG_NAME)
#---runs the program after making
run:	$(PROG_NAME)
	./$(PROG_NAME)
#---rebuilds everything by calling fclean and then all
re:		fclean all
#---lists all targets that are not files and ensures executions of commands
.PHONY:	all clean fclean re run

#---------------------------------LINKING---------------------------------------
$(PROG_NAME):	$(OBJ_DIR) $(OBJECTS)
	@rm -f $(PROG_NAME)
	$(CXX) $(C_FLAGS) $(OBJECTS) -o $(PROG_NAME)
	@echo "Compilation complete: "$(GREEN_B)$(PROG_NAME)$(ENDCLR)

$(BUG_PROG_NAME):	$(BUG_DIR) $(BUG_OBJ)
	@rm -f $(BUG_PROG_NAME)
	$(CXX) $(DEBUG_FLAGS) $(BUG_OBJ) -o $(BUG_PROG_NAME)
	@echo "Compilation complete: "$(GREEN_B)$(BUG_PROG_NAME)$(ENDCLR)

#---------------------------------OBJECTS---------------------------------------
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(BUG_DIR)/%.o: %.cpp
	$(CXX) $(DEBUG_FLAGS) -c $< -o $@

$(BUG_DIR):
	@mkdir -p $(BUG_DIR)
