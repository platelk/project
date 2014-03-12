void my_putchar (char c )
{
  write (1,&c, 1);
  
} 
int main()
{
  int i;
  i = 'a';
  while (i <= 'z')
    {
      my_putchar (i);
	i = i + 1;
}
}
