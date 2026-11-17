NAME        := ex00
CXX         := c++
CXXFLAGS    := -Wall -Wextra -Werror -std=c++98

SRC_DIR     := src
INCLUDE_DIR := include

SRC         := $(SRC_DIR)/main.cpp

OBJ_DIR     := obj
OBJ         := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re