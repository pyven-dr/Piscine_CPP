CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

DFLAGS = -MD -MP

INCLUDE_DIR = include

IFLAGS = -I $(INCLUDE_DIR)

SRC = main.cpp \
	  Bureaucrat.cpp \
	  AForm.cpp \
	  ShrubberyCreationForm.cpp \
	  RobotomyRequestForm.cpp \
	  PresidentialPardonForm.cpp \
	  Intern.cpp

BUILD_DIR = .build

OBJ = $(addprefix $(BUILD_DIR)/, $(SRC:.cpp=.o))

DEP = $(OBJ:.o=.d)

SRC_DIR = src

NAME = Bureaucrat

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

-include $(DEP)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: FORCE
FORCE:

.PHONY: re
re: fclean
	$(MAKE) all
