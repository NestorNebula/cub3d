/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:28:40 by nhoussie          #+#    #+#             */
/*   Updated: 2026/02/15 14:59:11 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/**
 * Checks if an integer represents an alphabetical character.
 *
 * @param c An integer 
 * @return 0 if the integer is non-alphabetical, > 0 otherwise
 */
int		ft_isalpha(int c);

/**
 * Checks if an integer represents a digit character.
 *
 * @param c An integer 
 * @return 0 if the integer isn't a digit , > 0 otherwise
 */
int		ft_isdigit(int c);

/**
 * Checks if an integer represents an alphanumeric character.
 *
 * @param c An integer 
 * @return 0 if the integer isn't alphanumeric , > 0 otherwise
 */
int		ft_isalnum(int c);

/**
 * Checks if an integer represents an ASCII character.
 *
 * @param c An integer 
 * @return 0 if the integer isn't an ASCII character, > 0 otherwise
 */
int		ft_isascii(int c);

/**
 * Checks if an integer represents a printable character.
 *
 * @param c An integer 
 * @return 0 if the integer isn't a printable character, > 0 otherwise
 */
int		ft_isprint(int c);

/**
 * Calculates the length of a string.
 * 
 * @param s A pointer to a string
 * @return The number of bytes in the string pointed to by s,
 * excluding the terminating null byte
 */
size_t	ft_strlen(const char *s);

/**
 * Fills memory with a constant byte.
 *
 * @param s A pointer to a chunk of memory
 * @param c A byte
 * @param n The number of bytes that must be filled
 * @return A pointer to the given chunk of memory
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * Zeroes a byte string.
 *@
 * @param s A pointer to a chunk of memory
 * @param n The number of bytes to fill with zeroes
 */
void	ft_bzero(void *s, size_t n);

/**
 * Copies memory area.
 * The source and the destination mustn't overlap.
 * Use ft_memmove if the memory areas do overlap.
 *
 * @param dest A pointer to a chunk of memory
 * @param src A pointer to a chunk of memory
 * @param n The number of bytes to copy
 * @return A pointer to the destination string
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * Copies memory area.
 *
 * @param dest A pointer to a chunk of memory
 * @param src A pointer to a chunk of memory
 * @param n The number of bytes to copy
 * @return A pointer to the destination string
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * Copies string.
 *
 * @param dst A pointer to a string
 * @param src A pointer to a string
 * @param siz The maximum number of bytes to copy,
 * including the terminating null byte
 * @return The length of the source string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t siz);

/**
 * Concatenates strings.
 *
 * @param dst A pointer to a string
 * @param src A pointer to a string
 * @param siz The size of the destination string
 * @return The initial length of the destination string plus
 * the length of the source string
 */
size_t	ft_strlcat(char *dst, const char *src, size_t siz);

/**
 * Converts an alphabetical character to uppercase.
 *
 * @param c An integer
 * @return The converted character if the given integer was alphabetical,
 * the given integer otherwise
 */
int		ft_toupper(int c);

/**
 * Converts an alphabetical character to lowercase.
 *
 * @param c An integer
 * @return The converted character if the given integer was alphabetical,
 * the given integer otherwise
 */
int		ft_tolower(int c);

/**
 * Locates a character in the given string, going forward.
 *
 * @param s A pointer to a string
 * @param c An integer
 * @return A pointer to the first matched character if found,
 * a NULL pointer otherwise
 */
char	*ft_strchr(const char *s, int c);

/**
 * Locates a character in the given string, going backward.
 *
 * @param s A pointer to a string
 * @param c An integer
 * @return A pointer to the first matched character if found,
 * a NULL pointer otherwise
 */
char	*ft_strrchr(const char *s, int c);

/**
 * Compares two strings.
 *
 * @param s1 A pointer to a string
 * @param s2 A pointer to a string
 * @param n The maximum number of bytes to compare
 * @return 0 if the strings are equal,
 * < 0 if the first string is less than the second one,
 * > 0 if the first string is greater than the second one.
 * These return values only correspond to the first n bytes of each string
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);


/**
 * Scans a chunk of memory for a character.
 *
 * @param s A pointer to a chunk of memory
 * @param c An integer
 * @param The maximum number of bytes to scan
 * @return A pointer to the matching byte if found, a null pointer otherwise
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * Compares memory areas.
 *
 * @param s1 A pointer to a chunk of memory
 * @param s2 A pointer to a chunk of memory
 * @param n The number of bytes to compare
 * @return 0 if the chunks of memory are equal,
 * < 0 if the first chunk of memory is less than the second one,
 * > 0 if the first chunk of memory is greater thatn the second one.
 * These return values only correspond to the first n bytes of each chunk
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * Locates a substring in a string.
 *
 * @param big A pointer to a string
 * @param little A pointer to a string
 * @param len The number of characters to search in the string
 * @return If the substring is an empty string, returns the string.
 * A pointer to the first occurrence of the substring in string if found,
 * a NULL pointer otherwise
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * Converts a string to an integer.
 *
 * @param nptr A pointer to a string
 * @return The converted value, 0 on error
 */
int		ft_atoi(const char *nptr);

/**
 * Allocates dynamic memory and zeroes its content.
 *
 * @param nmemb The number of elements
 * @param size The number of bytes needed for one element
 * @return A pointer to the allocated memory on success,
 * a NULL pointer otherwise
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**
 * Duplicates a string.
 *
 * @param s A pointer to a string
 * @return A pointer to the duplicated string on success,
 * a NULL pointer otherwise.
 */
char	*ft_strdup(const char *s);

/**
 *  Allocates memory (using malloc(3)) and returns a substring from
 *  the string 's'.
 *  The substring starts at index 'start' and has a maximum length of 'len'.
 *
 *  @param s The original string from which to create the substring
 *  @param start The starting index of the substring within 's'
 *  @param len The maximum length of the substring
 *  @return The substring. NULL if the allocation fails
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 *  Allocates memory (using malloc(3)) and returns a new string,
 *  which is the result of concatenating 's1' and 's2'.
 *
 *  @param s1 The prefix string
 *  @param s2 The suffix string
 *  @return The new string. NULL if the allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 *  Allocates memory (using malloc(3)) and returns a copy of 's1'
 *  with characters from 'set' removed from the beginning and the end.
 *
 *  @param s1 The string to be trimmed
 *  @param set The string containing the set of characters to be removed
 *  @return The trimmed string. NULL if the allocation fails
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 *  Allocates memory (using malloc(3)) and returns an array of strings
 *  obtained by splitting 's' using the character 'c' as a delimiter.
 *  The array must end with a NULL pointer.
 *
 *  @param s The string to be split
 *  @param c The delimiter character
 *  @return The array of new strings resulting from the split.
 *  NULL if the allocation fails
 */
char	**ft_split(char const *s, char c);

/**
 *	Allocates memory (using malloc(3)) and returns a string representing
 *	the integer received as an argument.
 *
 *	@param n The integer to convert
 *	@return The string representing the integer. NULL if the allocation fails
 */
char	*ft_itoa(int n);

/**
 *  Applies the function f to each character of the string s,
 *  passing its index as the first argument and
 *  the character itself as the second.
 *  A new string is created (using malloc(3)) to store
 *  the results from the successive applications of f.
 *
 *  @param s The string to iterate over
 *  @param f The function to apply to each character
 *  @return The string created from the successive applications of 'f'.
 *  Returns NULL if the allocation fails
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 *  Applies the function 'f' to each character of the string passed as argument,
 *  passing its index as the first argument.
 *  Each character is passed by address to 'f' so it can
 *  be modified if necessary.
 *
 *  @param s The string to iterate over
 *  @param f The function to apply to each character
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 *  Outputs the character 'c' to the specified file descriptor.
 *
 *  @param c The character to output
 *  @param fd The file descriptor on which to write
 */
void	ft_putchar_fd(char c, int fd);

/**
 *  Outputs the string 's' to the specified file descriptor.
 *
 *  @param s The string to output
 *  @param fd The file descriptor on which to write
 */
void	ft_putstr_fd(char *s, int fd);

/**
 *  Outputs the string 's' to the specified file descriptor
 *  followed by a newline.
 *
 *  @param s The string to output
 *  @param fd The file descriptor
 */
void	ft_putendl_fd(char *s, int fd);

/**
 *  Outputs the integer 'n' to the specified file descriptor
 *
 *  @param n The integer to output
 *  @param fd The file descriptor on which to write
 */
void	ft_putnbr_fd(int n, int fd);

/**
 *	Allocates memory (using malloc(3)) and returns a new node.
 *	The 'content' member variable is initialized with
 *	the given parameter 'content'.
 *	The variable 'next' is initialized to NULL.
 *
 *	@param content The content to store in the new node
 *	@return A pointer to the new node
 */
t_list	*ft_lstnew(void *content);

/**
 *  Adds the node 'new' at the beginning of the list
 *
 *  @param lst The address of a pointer to the first node of a list
 *  @param new The address of a pointer to the node to be added
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 *	Counts the number of nodes in the list.
 *
 *	@param lst The beginning of the list
 *	@return The length of the list
 */
int		ft_lstsize(t_list *lst);

/**
 *	Returns the last node of the list
 *
 *	@param lst The beginning of the list
 *	@return Last node of the list
 */
t_list	*ft_lstlast(t_list *lst);

/**
 *  Adds the node 'new' at the end of the list
 *
 *  @param lst The address of a pointer to the first node of a list
 *  @param new The address of a pointer to the node to be added
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 *  Takes a node as a parameter and frees its content using the function 'del'.
 *  Free the node itself but does NOT free the next node.
 *
 *  @param lst The node to free
 *  @param del The address of the function use to delete the content
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 *  Deletes and frees the given node and all its successors,
 *  using the function 'del' and free(3).
 *  Finally, set the pointer to the list to NULL.
 *
 *  @param lst The address of a pointer to a node
 *  @param del The address of the function used to delete the content of the node
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 *  Iterates trough the list 'lst' and applies the function 'f'
 *  to the content of each node.
 *
 *  @param lst The address of a pointer to a node
 *  @param f The address of the function to apply to each node's content
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 *  Iterates through the list 'lst', applies the function 'f' to
 *  each node's content, and creates a new list resulting of 
 *  the successive applications of the function 'f'.
 *  The 'del' function is used to delete the content of a node if needed.
 *
 *  @param lst The address of a pointer to a node
 *  @param f The address to the function applied to each node's content
 *  @param del The address of the function used to delete
 *  a node's content if needed
 *  @return The new list. NULL if the allocation fails
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 *  Allocates memory (using malloc(3)) and returns a string representing
 *  the integer received as an argument in the provided base.
 *
 *  @param n The integer to convert
 *  @param base The base used to convert the integer 
 *  @return The string representing the integer. NULL If the allocations fails
 */
char	*ft_itoa_base(int n, const char *base);

/**
 *  Allocates memory (using malloc(3)) and returns a string representing
 *  the unsigned integer received as an argument in the provided base.
 *
 *  @param n The unsigned integer to convert
 *  @param base The base used to convert the unsigned integer 
 *  @return The string representing the unsigned integer.
 *  NULL If the allocations fails
 */
char	*ft_uitoa_base(unsigned int n, const char *base);

/**
 *  Allocates memory (using malloc(3)) and returns a string representing
 *  the value of the pointer's received as an argument in the provided base.
 *
 *  @param n The pointer to convert
 *  @param base The base used to convert the pointer 
 *  @return The string representing the pointer's value.
 *  NULL If the allocations fails
 */
char	*ft_pitoa_base(void *p, const char *base);

/**
 *  Writes formatted output to stdout using format and others arguments.
 *
 *  @param format The format of the output
 *  @param ... Optional arguments to use in combination with the format
 *  @return The number of characters printed. -1 if an error occurs
 */
int		ft_printf(const char *format, ...);

/**
 *  Writes formatted output to a file descriptor using format
 *  and others arguments.
 *
 *  @param fd The file descriptor to which the output will be printed
 *  @param format The format of the output
 *  @param ... Optional arguments to use in combination with the format
 *  @return The number of characters printed. -1 if an error occurs
 */
int		ft_dprintf(int fd, const char *format, ...);

/**
 * Frees an array and its content.
 *
 * @param arr A pointer to the first element of an array
 * @param free_item A function that will be called for each item in the array
 */
void	ft_free_arr(void *arr, void (*free_item)(void *));

/**
 * Closes a positive file descriptor.
 *
 * @param fd An integer
 * @return 0 on success or if the given integer can't be a file descriptor,
 * -1 otherwise.
 */
int		ft_close(int fd);

/**
 *  Allocates memory (using malloc(3)) and returns an array of strings
 *  obtained by splitting 's' using a set of characters as delimiters.
 *  The array must end with a NULL pointer.
 *
 *  @param s The string to be split
 *  @param set An array of characters considered as delimiters
 *  @return The array of new strings resulting from the split.
 *  NULL if the allocation fails
 */
char	**ft_split_set(char const *s, const char *set);

#endif /* end of include guard: LIBFT_H */
