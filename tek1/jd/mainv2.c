void my_putchar (char c)
{
  write (1,&c,1);
}
int main()
{
  int i;
  i = 'a';
  while (i <= 'z')
    {
      if(i % 2 == 0 )
	my_putchar (i);
      else 
	my_putchar(i - 32);
      i = i + 1;
    }
}
