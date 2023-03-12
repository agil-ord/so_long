/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agil-ord <agil-ord@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:04:59 by agil-ord          #+#    #+#             */
/*   Updated: 2023/03/12 20:04:10 by agil-ord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//library ft_printf
# include <stdarg.h>

# include "memory_leaks.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//function tests for any character
int		ft_isalpha(int c);
//takes a single argument in the form of an integer 
//and returns the value of type int.
int		ft_isdigit(int c);
//hecks whether the argument passed is an 
//alphanumeric character (alphabet or number) or not.
int		ft_isalnum(int c);
//checks if a given character
int		ft_isascii(int c);
//checks whether a character is a printable character or not.
int		ft_isprint(int c);
//akes a string as an argument and returns its length.
size_t	ft_strlen(const char *c);
//copies the character c to the first n characters of the string
void	*ft_memset(void *b, int c, size_t len);
//function erases the data in the n bytes of the memory
//starting at the location pointed to by s, by writing zeros to that area.
void	ft_bzero(void *s, size_t len);
//copies n characters from memory area src to memory area dest.
void	*ft_memcpy(void *dst, const void *src, size_t n);
//copies n characters from str2 to str1, but for overlapping memory blocks.
void	*ft_memmove(void *dst, const void *src, size_t len);
//copies up to size - 1 characters from the NUL-terminated 
//string src to dst, NUL-terminating the result.
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size);
//function appends the NUL-terminated string src to the end of dst.
// It will append at most size - strlen(dst) - 1 bytes,
// NUL-terminating the result.
size_t	ft_strlcat(char	*dst, const char	*src, size_t	dstsize);
//function converts a lowercase alphabet to an uppercase alphabet.
int		ft_toupper(int ch);
//function is other than an uppercase alphabe
int		ft_tolower(int ch);
//searches for the first occurrence of the character c
// in the string pointed to by the argument str
char	*ft_strchr(const char *s, int c);
//searches for the last occurrence of the character c
//in the string pointed to, by the argument str.
char	*ft_strrchr(const char *s, int c);
//compares at most the first n bytes of str1 and str2.
int		ft_strncmp(const char *s1, const char *s2, size_t n);
//searches for the first occurrence of the character c
//in the first n bytes of the string pointed to, by the argument str.
void	*ft_memchr(const void *str, int c, size_t n);
//compares the first n bytes of memory area str1 and memory area str2.
int		ft_memcmp(const void *s1, const void *s2, size_t n);
//function locates the first occurrence of the null-terminated 
//string \c little in the string \c big, where not more 
//than \c len characters are searched. Characters 
//that appear after a \0 character are not searched.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
//converts the string argument str to an integer.
int		ft_atoi(const char *str);
//llocates the requested memory and returns a pointer to it. 
//The difference in malloc and calloc is that malloc does not set
// the memory to zero where as calloc sets allocated memory to zero.
void	*ft_calloc(size_t count, size_t size);
//functions are used to duplicate a string.
char	*ft_strdup(const char *s1);
//Reserve (with malloc(3)) and return a substring of the string 's'.
//The substring starts from the index 'start' 
//and has a maximum length of 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len);
//Reserve (with malloc and return a new string, 
//formed by the concatenation of 's1' and 's2'.
char	*ft_strjoin(char const *s1, char const *s2);
//Removes all characters from the string 'set' from the beginning 
//and from the end of 's1', until a character not belonging 
//to 'set' is found. The resulting string is returned 
//with a malloc reservation
char	*ft_strtrim(char const	*s1, char const	*set);
//Reserves (using malloc) an array of strings resulting from 
//separating the string 's' into substrings using 
//the character 'c' as a delimiter. The array must end 
//with a NULL pointer.
char	**ft_split(char const	*s, char c);
//Using malloc, generate a string representing the 
//integer value received as an argument. 
//Negative numbers have to be managed.
char	*ft_itoa(int n);
//To each character of the string 's', apply the
//function 'f' giving as parameters the index of 
//each character inside 's' and the character itself. 
//Generates a new string with the result of successive use of 'f'
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
//To each character of the string 's', it applies the function 'f'
// giving as parameters the index of each character within 's'
// and the address of the character itself, which can be 
// modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
//Send the character 'c' to the specified file descriptor.
void	ft_putchar_fd(char c, int fd);
//Sends the string 's' to the specified file descriptor.
void	ft_putstr_fd(char *s, int fd);
//Send the string 's' to followed by a jump
//ft_putnbr_fd to write about. given file descriptor, line.
void	ft_putendl_fd(char *s, int fd);
//Send the number 'n' to the given file descriptor.
void	ft_putnbr_fd(int n, int fd);
//Create a new node using malloc(3). The member variable 'content' 
//is initialized with the content of the 'content' parameter.
// The variable 'next', with NULL.
t_list	*ft_lstnew(void *content);
//Add the 'new' node to the beginning of the 'lst' list.
void	ft_lstadd_front(t_list **lst, t_list *new);
//Counts the number of nodes in a list.
int		ft_lstsize(t_list *lst);
//Returns the last node in the list.
t_list	*ft_lstlast(t_list *lst);
//Add the 'new' node to the end of the 'lst' list.
void	ft_lstadd_back(t_list **lst, t_list *new);
//It takes as a parameter an 'lst' node and frees the memory 
//of the content using the 'del' function given as a parameter,
// in addition to freeing the node. The memory of 'next' 
//must not be freed.
void	ft_lstdelone(t_list *lst, void (*del)(void *));
//Removes and frees the given 'lst' node and all consecutive 
//ones from that node, using the 'del' function and free.
//At the end, the pointer to the list must be NULL.
void	ft_lstclear(t_list **lst, void (*del)(void *));
//Iterates through the 'lst' list and applies 
//the 'f' function on the content of each node.
void	ft_lstiter(t_list *lst, void (*f)(void *));
//Iterates through the 'lst' list and applies the 'f' function 
//to the contents of each node. Create a list resulting
// from the correct and successive application of 
//the function 'f' on each node. The 'del' function is used 
//to remove the content of a node, if necessary.
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

//------------------------------------------------------

//My ft_printf

// int		ft_printf(char const	*str, ...);
// void	ft_putchar_printf(char c, int *pt_i);
// void	ft_putstr_printf(char *s, int *pt_i);
// void	ft_putnbr_hex_p(unsigned long long nb, char *base, int *pt_i);
// void	ft_putnbr_uns_printf(unsigned int nb, int *pt_i);
// void	ft_putnbr_printf(int nb, int *pt_i);
// void	ft_putnbr_hex_cap(unsigned int nb, char *base, int *pt_i);
#endif
