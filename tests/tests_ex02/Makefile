#----------------------------------FILES----------------------------------------
SRC_EXP	=	expected_generator.cpp

SRC_RND	=	random_generator.cpp

OBJ_DIR		= build
OBJ_EXP 	= $(addprefix $(OBJ_DIR)/, $(SRC_EXP:.cpp=.o))
OBJ_RND 	= $(addprefix $(OBJ_DIR)/, $(SRC_RND:.cpp=.o))
#----------------------------COMPILER SETTINGS----------------------------------
PROG_EXP		= expected_generator
PROG_RND		= random_generator

CXX				= c++
C_FLAGS			= -g -Wall -Wextra -Werror -std=c++98 $(DEP_FLAGS)

#---------------------------------COLORS----------------------------------------
GREEN_B	= "\033[1;32m"
ENDCLR	= "\33[m"

#---------------------------------TARGETS---------------------------------------
all:	$(PROG_EXP)

random:	$(PROG_RND)
#---deletes all object files and file called log
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.expected
#---calls clean target then deletes PROG_NAME
fclean:		clean
	@rm -f $(PROG_EXP)
	@rm -f $(PROG_RND)
#---rebuilds everything by calling fclean and then all
re:		fclean all
#---lists all targets that are not files and ensures executions of commands
.PHONY:	all clean fclean re

#---------------------------------LINKING---------------------------------------
$(PROG_EXP):	$(OBJ_DIR) $(OBJ_EXP)
	@rm -f $(PROG_EXP)
	$(CXX) $(C_FLAGS) $(OBJ_EXP) -o $(PROG_EXP)
	@echo "Compilation complete: "$(GREEN_B)$(PROG_EXP)$(ENDCLR)

$(PROG_RND):	$(OBJ_DIR) $(OBJ_RND)
	@rm -f $(PROG_RND)
	$(CXX) $(C_FLAGS) $(OBJ_RND) -o $(PROG_RND)
	@echo "Compilation complete: "$(GREEN_B)$(PROG_RND)$(ENDCLR)

#---------------------------------OBJ_EXP---------------------------------------
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
