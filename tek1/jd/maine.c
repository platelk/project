void my_putchar (char c)
{
  write (1,&c,1);
}
int main()
{
  int i;
  i = 'z';
  while (i >= 'a')
    {
      my_putchar (i);
      i = i - 1;
    } 
}
