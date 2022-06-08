/**
 * @brief _strlen counts the no of chrs in a string
 * 
 * @param string the string 
 * @return ** int no of chrs in the string above
 */
int _strlen(const char *string)
{
int count = 0;
while (string[count])
	count++;

return (count);
}