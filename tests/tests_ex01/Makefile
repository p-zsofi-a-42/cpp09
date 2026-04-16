#----------------------------------FILES----------------------------------------
SRC_EXP	=	expected_generator.cpp

OBJ_DIR		= build
OBJ_EXP 	= $(addprefix $(OBJ_DIR)/, $(SRC_EXP:.cpp=.o))
#----------------------------COMPILER SETTINGS----------------------------------
PROG_EXP		= expected_generator

CXX				= c++
C_FLAGS			= -g -Wall -Wextra -Werror -std=c++98 $(DEP_FLAGS)

#---------------------------------COLORS----------------------------------------
GREEN_B	= "\033[1;32m"
ENDCLR	= "\33[m"

#---------------------------------TARGETS---------------------------------------
all:	$(PROG_EXP)

#---deletes all object files and file called log
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf *.expected
#---calls clean target then deletes PROG_NAME
fclean:		clean
	@rm -f $(PROG_EXP)
#---rebuilds everything by calling fclean and then all
re:		fclean all
#---lists all targets that are not files and ensures executions of commands
.PHONY:	all clean fclean re

#---------------------------------LINKING---------------------------------------
$(PROG_EXP):	$(OBJ_DIR) $(OBJ_EXP)
	@rm -f $(PROG_EXP)
	$(CXX) $(C_FLAGS) $(OBJ_EXP) -o $(PROG_EXP)
	@echo "Compilation complete: "$(GREEN_B)$(PROG_EXP)$(ENDCLR)

#---------------------------------OBJ_EXP---------------------------------------
$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(C_FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
