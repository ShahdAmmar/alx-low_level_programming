/**
 * print_name - print name in specific form
 * @name: person nam
 * @f: pointer to func
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	(*f)(name);
}
