/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rydelepi <rydelepi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:27:32 by rydelepi          #+#    #+#             */
/*   Updated: 2025/11/28 16:00:00 by rydelepi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

/*
** BUFFER_SIZE - Buffer size for get_next_line
** Default value is 1024 bytes, can be overridden at compile time
** with -D BUFFER_SIZE=<value>
*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/*
** ft_isalpha - Checks if character is alphabetic (a-z, A-Z)
** @c      : Character to check (as int)
** @return : 1 if alphabetic, 0 otherwise
*/
int				ft_isalpha(int c);

/*
** ft_isdigit - Checks if character is a digit (0-9)
** @c      : Character to check (as int)
** @return : 1 if digit, 0 otherwise
*/
int				ft_isdigit(int c);

/*
** ft_isalnum - Checks if character is alphanumeric
** @c      : Character to check (as int)
** @return : 1 if alphanumeric, 0 otherwise
*/
int				ft_isalnum(int c);

/*
** ft_isascii - Checks if character is in ASCII table (0-127)
** @c      : Character to check (as int)
** @return : 1 if ASCII, 0 otherwise
*/
int				ft_isascii(int c);

/*
** ft_isprint - Checks if character is printable (32-126)
** @c      : Character to check (as int)
** @return : 1 if printable, 0 otherwise
*/
int				ft_isprint(int c);

/*
** ft_memset - Fills memory with a constant byte
** @b      : Pointer to memory area
** @c      : Byte value to fill with
** @len    : Number of bytes to fill
** @return : Pointer to memory area b
*/
void			*ft_memset(void *b, int c, size_t len);

/*
** ft_memcpy - Copies memory area (no overlap handling)
** @dest   : Destination buffer
** @src    : Source buffer
** @n      : Number of bytes to copy
** @return : Pointer to dest
** Note: Use ft_memmove if memory areas may overlap
*/
void			*ft_memcpy(void *dest, const void *src, size_t n);

/*
** ft_memmove - Copies memory area (handles overlap)
** @dest   : Destination buffer
** @src    : Source buffer
** @n      : Number of bytes to copy
** @return : Pointer to dest
*/
void			*ft_memmove(void *dest, const void *src, size_t n);

/*
** ft_memchr - Locates byte in memory
** @s      : Memory area to search
** @c      : Byte to find
** @n      : Number of bytes to search
** @return : Pointer to matching byte, or NULL if not found
*/
void			*ft_memchr(const void *s, int c, size_t n);

/*
** ft_memcmp - Compares memory areas
** @s1     : First memory area
** @s2     : Second memory area
** @n      : Number of bytes to compare
** @return : 0 if identical, difference of first differing byte otherwise
*/
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** ft_strlen - Calculates length of string
** @str    : String to measure
** @return : Length of string (excluding null terminator)
*/
size_t			ft_strlen(const char *str);

/*
** ft_strchr - Locates first occurrence of character in string
** @s      : String to search
** @c      : Character to find
** @return : Pointer to character, or NULL if not found
*/
char			*ft_strchr(const char *s, int c);

/*
** ft_strrchr - Locates last occurrence of character in string
** @s      : String to search
** @c      : Character to find
** @return : Pointer to character, or NULL if not found
*/
char			*ft_strrchr(const char *s, int c);

/*
** ft_strncmp - Compares two strings up to n characters
** @s1     : First string
** @s2     : Second string
** @n      : Maximum characters to compare
** @return : 0 if equal, difference of first differing character otherwise
*/
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** ft_strlcpy - Copies string with size limit
** @dst     : Destination buffer
** @src     : Source string
** @dstsize : Size of destination buffer
** @return  : Length of src (for truncation detection)
*/
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** ft_strlcat - Concatenates strings with size limit
** @dst  : Destination buffer (must contain a string)
** @src  : Source string to append
** @size : Total size of destination buffer
** @return : Total length of string it tried to create
*/
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/*
** ft_strnstr - Locates substring in string (size limited)
** @haystack : String to search in
** @needle   : Substring to find
** @len      : Maximum characters to search
** @return   : Pointer to substring, or NULL if not found
*/
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);

/*
** ft_strdup - Duplicates a string (malloc)
** @src    : String to duplicate
** @return : Pointer to new string, or NULL on malloc failure
*/
char			*ft_strdup(const char *src);

/*
** ft_substr - Extracts substring from string (malloc)
** @s      : Source string
** @start  : Start index
** @len    : Maximum length of substring
** @return : New substring, or NULL on malloc failure
*/
char			*ft_substr(char const *s, unsigned int start, size_t len);

/*
** ft_strjoin - Concatenates two strings (malloc)
** @s1     : First string
** @s2     : Second string
** @return : New concatenated string, or NULL on malloc failure
*/
char			*ft_strjoin(char const *s1, char const *s2);

/*
** ft_strtrim - Trims characters from both ends of string (malloc)
** @s1     : String to trim
** @set    : Characters to remove
** @return : Trimmed string, or NULL on malloc failure
*/
char			*ft_strtrim(char const *s1, char const *set);

/*
** ft_strmapi - Applies function to each character (malloc)
** @s      : Source string
** @f      : Function to apply f(index, character)
** @return : New string with transformed characters
*/
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** ft_striteri - Applies function to each character in place
** @s      : String to modify
** @f      : Function to apply f(index, &character)
*/
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** ft_putstr_fd - Writes string to file descriptor
** @str    : String to write
** @fd     : File descriptor
*/
void			ft_putstr_fd(char *str, int fd);

/*
** ft_putchar_fd - Writes character to file descriptor
** @c      : Character to write
** @fd     : File descriptor
*/
void			ft_putchar_fd(char c, int fd);

/*
** ft_putendl_fd - Writes string followed by newline to file descriptor
** @s      : String to write
** @fd     : File descriptor
*/
void			ft_putendl_fd(char *s, int fd);

/*
** ft_putnbr_fd - Writes integer to file descriptor
** @nb     : Number to write
** @fd     : File descriptor
*/
void			ft_putnbr_fd(int nb, int fd);

/*
** ft_atoi - Converts string to integer
** @nptr   : String to convert
** @return : Converted integer value
** Handles whitespace, sign, and stops at first non-digit
*/
int				ft_atoi(const char *nptr);

/*
** ft_bzero - Sets memory to zero
** @s      : Memory area to zero
** @n      : Number of bytes to set
*/
void			ft_bzero(void *s, size_t n);

/*
** ft_calloc - Allocates and zeros memory
** @count  : Number of elements
** @size   : Size of each element
** @return : Pointer to allocated memory, or NULL on failure
*/
void			*ft_calloc(size_t count, size_t size);

/*
** ft_split - Splits string by delimiter (malloc)
** @s      : String to split
** @c      : Delimiter character
** @return : NULL-terminated array of strings
*/
char			**ft_split(char const *s, char c);

/*
** ft_tolower - Converts uppercase to lowercase
** @c      : Character to convert
** @return : Lowercase character, or unchanged if not uppercase
*/
int				ft_tolower(int c);

/*
** ft_toupper - Converts lowercase to uppercase
** @c      : Character to convert
** @return : Uppercase character, or unchanged if not lowercase
*/
int				ft_toupper(int c);

/*
** ft_itoa - Converts integer to string (malloc)
** @n      : Integer to convert
** @return : String representation, or NULL on malloc failure
*/
char			*ft_itoa(int n);

/*
** get_next_line - Reads a line from file descriptor
** @fd     : File descriptor to read from
** @return : Line read (including \n), or NULL on EOF/error
*/
char			*get_next_line(int fd);

/*
** ft_printf - Formatted output to stdout
** @str    : Format string
** @...    : Variable arguments
** @return : Number of characters printed, -1 on error
*/
int				ft_printf(const char *str, ...);

#endif
