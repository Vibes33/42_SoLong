/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:32 by rydelepi          #+#    #+#             */
/*   Updated: 2025/10/23 15:35:01 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

/**
 * @details
 * @brief char -> int
 * @param char*str character string
 * @return int sign * total
 */
int				ft_atoi(const char *nptr);
/**
 * @details
 * @brief Sets everything to zero
 * @param void*s memory area address  
 * @param size_tn number of bytes to set to 0 
 * @return s (memory area)
 */
void			ft_bzero(void *s, size_t n);
/**
 * @details
 * @brief Continuous allocation (allocates and initializes to 0)
 * @param size_t count, size_t size 
 * @return ptr = malloc(total)
 */
void			*ft_calloc(size_t count, size_t size);
/**
 * @details
 * @brief is alphanumeric 
 * @param int c character to check
 * @return 1 or 0
 */
int				ft_isalnum(int c);
/**
 * @details
 * @brief is alphanumeric 
 * @param int c character to check
 * @return 1 or 0
 */
int				ft_isalpha(int c);
/**
 * @details
 * @brief is ascii 
 * @param int c character to check
 * @return 1 or 0
 */
int				ft_isascii(int c);
/**
 * @details
 * @brief is a number 
 * @param int c character to check
 * @return 1 or 0
 */
int				ft_isdigit(int c);
/**
 * @details
 * @brief is alphanumeric 
 * @param int c character to check
 * @return 1 or 0
 */
int				ft_isprint(int c);
/**
 * @details
 * @brief int -> string
 * @param int.n number to convert in string
 * @return character string 
 */
char			*ft_itoa(int n);
/**
 * @details
 * @brief scans the first n bytes of a memory area pointed to by s
 * @param const.void.*s the memory area
 * @param int.c character to find
 * @param size_t.n number of bytes to scan
 * @return pointer to the found byte
 */
void			*ft_memchr(const void *s, int c, size_t n);
/**
 * @details
 * @brief compares the first n bytes of two strings
 * @param const.void.*s1 string 1
 * @param const.void.*s2 string 2
 * @param size_t.n number of bytes to compare
 * @return int (ASCII difference between the two strings)
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @details
 * @brief copies the first n bytes of two strings
 * @param const.void.*src source
 * @param void.*dest destination
 * @param size_t.n number of bytes to copy
 * @return dest
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @details
 * @brief moves a buffer to another buffer
 * @param const.void.*src source
 * @param void.*dest destination
 * @param size_t.n number of bytes to move
 * @return dest
 */
void			*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @details
 * @brief sets the first characters of dest based on c
 * @param void.*b destination
 * @param int.c character to set
 * @param size_t.len number of characters to modify
 * @return destination (b)
 */
void			*ft_memset(void *b, int c, size_t len);
/**
 * @details
 * @brief displays a character 
 * @param char.c character to display
 * @param int.fd file descriptor, defines the output
 * @return void
 */
void			ft_putchar_fd(char c, int fd);
/**
 * @details
 * @brief defines the first n characters of dest based on c and skips a line
 * @param char.c character to be defined
 * @param int.fd file descriptor, defines the output
 * @return void
 */
void			ft_putendl_fd(char *s, int fd);
/**
 * @details
 * @brief defines the first n characters of dest based on c and skips a line
 * @param int.nb character to be defined
 * @param int.fd file descriptor, defines the output
 * @return void
 */
void			ft_putnbr_fd(int nb, int fd);
/**
 * @details
 * @brief reads a character string
 * @param char.*str character string
 * @param int.fd file descriptor, defines the output
 * @return void
 */
void			ft_putstr_fd(char *str, int fd);
/**
 * @details
 * @brief reads a character string
 * @param char.*str character string
 * @param int.fd file descriptor, defines the output
 * @return void
 */
char			**ft_split(char const *s, char c);
/**
 * @details
 * @brief Duplicates a character string in a var dest
 * @param char.src Character string to be duplicated
 * @return dest
 */
char			*ft_strdup(char *src);
/**
 * @details
 * @brief Applies a function to each byte of *s
 * @param char.s
 * @param void.(*f).(unsigned int, char *) Function to apply
 * @return void
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
/**
 * @details
 * @brief concatenates two strings
 * @param int.size 
 * @param char.const.*s1 string 1
 * @param char.const.*s2 string 2
 * @return returns a character string containing both strings
 */
char			*ft_strjoin(char const *s1, char const *s2);
/**
 * @details
 * @brief concatenates elements from an array src to dest based on size
 * @param char *d destination
 * @param const.char.*s source
 * @param size_t.dstsize size of elements to concatenate
 * @return total size of the string it creates
 */
size_t			ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @details
 * @brief copies elements from an array src to dest based on size
 * @param char *dst destination
 * @param const.char.*src source
 * @param size_t.dstsize size of elements to copy
 * @return total size of the string it creates
 */
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
/**
 * @details
 * @brief Counts the number of elements in a character string.
 * @param const.char.*str Character string.
 * @return Size of src.
 */
size_t			ft_strlen(const char *str);
/**
 * @details
 * @brief compares two character strings of n characters
 * @param const.char.*s1 string 1
 * @param const.char.*s2 string 2
 * @param unsigned.int.n number of characters to compare
 * @return 0 or the ASCII difference between the characters in the two strings
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @details
 * @brief Takes a text extract from start, 
 * copying n characters
 * @param const.char.*s character string to scan
 * @param unsigned.int.start starting character for reading
 * @param size_t.len size of the string to return
 * @return a malloc sub string returning the characters 
 * from start according to n
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @details
 * @brief Applies +32 to each character c
 * @param int.c Character to be modified
 * @return Modified character
 */
int				ft_tolower(int c);
/**
 * @details
 * @brief applies -32 to each character c
 * @param int.c character to be modified
 * @return the modified character
 */
int				ft_toupper(int c);
/**
 * @details
 * @brief searches for the first occurrence of needle in h
 *  based on len
 * @param const.char.*haystack haystack
 * @param const.char.*needle needle
 * @param size_t.len number of characters to read 
 * in haystack
 * @return char , pointer to the start of the occurrence, otherwise NULL
 */
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
/**
 * @details
 * @brief Applies a function that applies the function f 
 * to the characters of a string s.
 * @param char.const.*s Character string.
 * @param char.(*f)(unsigned int, char) Function to be applied
 * to each character.
 * @return New character string with modified characters.
 */		
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @details
 * @brief returns the entire character string from the first 
 * occurrence of c 
 * @param char.const.*s character string
 * @param int.c character to find 
 * @return new character string s from 
 * the first c encountered, otherwise NULL
 */
char			*ft_strchr(const char *s, int c);
/**
 * @details
 * @brief searches for the last occurrence and returns a pointer
 * to that position 
 * @param char.const.*s character string
 * @param int.c character to find 
 * @return new character string s from 
 * the first c found, otherwise NULL
 */	
char			*ft_strrchr(const char *s, int c);
/**
 * @details
 * @brief Cleans a string (removes all characters 
 * not present in set)
 * @param char.const.*s1 character string
 * @param char.const.*set characters to be cleaned
 * @return new string containing s1 without the characters in set
 */	
char			*ft_strtrim(char const *s1, char const *set);
/**
 * @details
 * @brief Creates a new node with the t_list structure.
 * @param void.*content Content of the new node.
 * @return node
 */
t_list			*ft_lstnew(void *content);
/**
 * @details
 * @brief adds a new node at the head (new->a->b)
 * @param t_list.**lst list
 * @param t_list.*new the new head node
 * @return void
 */
void			ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @details
 * @brief adds a new node at the end (a->b->new)
 * @param t_list.**lst list of nodes
 * @param t_list.*new the new head node
 * @return void
 */
void			ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @details
 * @brief gets the last element
 * @param t_list.*lst node
 * @return lst (last element)
 */
t_list			*ft_lstlast(t_list *lst);
/**
 * @details
 * @brief counts the elements in the list
 * @param t_list.*lst node
 * @return size of the list
 */
int				ft_lstsize(t_list *lst);
/**
 * @details
 * @brief Deletes a node
 * @param t_list.*lst node
 * @param void.(*del)(void *) del function to clear the content and then the node
 * @return void
 */
void			ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @details
 * @brief Deletes the list
 * @param t_list.**lst list
 * @param void.(*del)(void *) del function to clear the content and then the node
 * @return void
 */
void			ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @details
 * @brief applies a function to each element
 * @param t_list.*lst node
 * @param void.(*f)(void *) function to apply to each element
 * @return void
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @details
 * @brief applies a function to each element and creates a 
 * new list with the results; if malloc fails, del is applied
 * @param t_list.*lst node
 * @param void.(*del)(void *) del function to delete the content 
 * and then the node
 * @param void.(*f)(void *) function to apply to each element
 * @return the new list
 */
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
