void my_putchar (char c)
{
  write (1,&c,1);
}
int main(int ac, char **av)
{
  int i;
  i = 90;
  if (i > 0)  
    {
      my_putchar (80);
    }
  else if (i < 0 )
    {
      my_putchar (78);
    } 
  else
    my_putchar (79);
    
}
