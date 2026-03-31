NAME	= cub3D

SRC_DIR			= src
INC_DIR			= include
OBJ_DIR			= .obj
TEST_DIR		= test
LIBFT_DIR		= libft
LIBFT_INC_DIR	= $(LIBFT_DIR)/include
LIBFT			= $(LIBFT_DIR)/libft.a
MLX_DIR			= minilibx-linux
MLX				= $(MLX_DIR)/libmlx.a
CUT_DIR			= $(TEST_DIR)/cut
CUT_INC_DIR		= $(CUT_DIR)/include
CUT				= $(CUT_DIR)/libcut.a

SRCS_FILES		=

SRCS 			= $(addprefix $(SRC_DIR)/, $(SRCS_FILES))

OBJS			= $(SRCS:%.c=$(OBJ_DIR)/%.o)

TESTS_FILES		= read_scene.c texture_from_line.c row_from_line.c

TESTS			= $(addprefix $(TEST_DIR)/, $(TESTS_FILES))

TEST_EXECS		= $(TESTS:%.c=%.out)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -I$(INC_DIR) -I$(LIBFT_INC_DIR) -I$(MLX_DIR)
LFLAGS			= -L$(LIBFT_DIR) -L$(MLX_DIR) -lft -lmlx -lXext -lX11 -lm -lz

AR				= ar
ARFLAGS			= -r -c -s
NORMINETTE		= @norminette
RM 				= rm
RMFLAGS 		= -r -f
MKDIR			= @mkdir
MKDIRFLAGS		= -p
VALGRIND		= valgrind
VALGRIND_FLAGS	= --leak-check=full --show-leak-kinds=all --track-fds=yes \
				  --track-origins=yes --trace-childrens=yes

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(MKDIR) $(MKDIRFLAGS) $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR) --no-print-directory

fclean:
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	$(RM) $(RMFLAGS) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR) --no-print-directory

re: fclean all

leaks: $(NAME)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(NAME)

leaks_supp: $(NAME)
	$(VALGRIND) $(VALGRIND_FLAGS) --suppressions=supp.supp ./$(NAME)

sanitize: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -fsanitize=address" all

thread: fclean
	$(MAKE) CFLAGS="$(CFLAGS) -fsanitize=thread" all

checknorm:
	$(NORMINETTE) $(LIBFT_DIR)
	$(NORMINETTE) $(INC_DIR)
	$(NORMINETTE) $(SRC_DIR)

$(CUT):
	$(MAKE) -C $(CUT_DIR) --no-print-directory

$(TEST_DIR)/%.out: $(TEST_DIR)/%.c $(CUT) $(OBJS)
	$(AR) $(ARFLAGS) libcub3d.a $(OBJS)
	$(CC) $(CFLAGS) $< -o $@ $(IFLAGS) -I$(CUT_INC_DIR) -L$(CUT_DIR) \
        -L. -lcut -lcub3d

test: $(TEST_EXECS)
	@for test in $(TEST_EXECS) ; do \
		./$$test ; \
	done

test_leaks : $(TEST_EXECS)
	@for test in $(TEST_EXECS) ; do \
		$(VALGRIND) $(VALGRIND_FLAGS) ./$$test ; \
	done

fclean_test:
	$(RM) $(RMFLAGS) $(TEST_EXECS)
	$(MAKE) -C $(CUT_DIR) fclean --no-print-directory


.PHONY: all clean fclean re leaks leaks_supp sanitize thread checknorm test \
	test_leaks fclean_test \
