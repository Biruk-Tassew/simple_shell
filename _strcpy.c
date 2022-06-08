/**
 * @brief -_strcpy copies a string from source to a destination
 * 
 * @param dest where the string needed to be copied
 * @param src from where we copy the string
 * @return ** char* pointer to dest 
 */
char *_strcpy(char *dest, const char *src)
{
	int count = -1;

	do {
        count++;
		dest[count] = src[count];
	} while (src[count] != '\0');

	return (dest);
}