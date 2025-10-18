NAME = megaphone
CC = c++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98

# Directories
SRC_DIR = .
OBJ_DIR = obj

# Source files
SRCS = megaphone.cpp

# Add src/ prefix to source files
SRCS_PREFIXED = $(addprefix $(SRC_DIR)/,$(SRCS))

# Object files
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Create object directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

# Rule to build the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Default target to build everything
all: $(NAME)

# Clean up object files
clean:
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)

# Clean up object files and the executables
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

.PHONY: all clean fclean re
