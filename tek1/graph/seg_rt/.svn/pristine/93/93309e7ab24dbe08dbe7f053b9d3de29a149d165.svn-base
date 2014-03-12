/*
** aff.c for aff in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 14:24:01 2012 harold ozouf
** Last update Fri May 25 13:45:39 2012 ronan guiho
*/

#include	<unistd.h>
#include	<stdio.h>

#include	"parse.h"
#include	"aff.h"
#include	"my.h"

void	print_usage(void)
{
  my_putstr("USAGE\n");
  my_putstr("--mode -arg...\n");
  my_putstr("   client: --client\n");
  my_putstr("   \t-i:\tserver ip\n");
  my_putstr("   \t-p:\tport\n");
  my_putstr("   \t-t:\tnumber of thread\n");
  my_putstr("   server: --server\n");
  my_putstr("   \t-p:\tport\n");
  my_putstr("   \t-m:\tyou disable the rt display\n");
  my_putstr("   \t-e:\texport the result (you can specify a file)\n");
  my_putstr("   \t-v:\tdescribe the scene\n");
  my_putstr("   normal: without marker\n");
  my_putstr("   \t-m:\tyou disable the rt display\n");
  my_putstr("   \t-e:\texport the result (you can specify a file)\n");
  my_putstr("   \t-v:\tdescribe the scene\n");
  my_putstr("   \t-t:\tnumber of thread\n");
}

void	print_choice(t_info *inf)
{
  printf("port: %d\nthread: %d\nxml: %s\n", inf->port, inf->nbr_thread, inf->xml);
  if (inf->type == TYPE_SERVER)
    printf("\tmode SERVER\n");
  else if (inf->type == TYPE_NORMAL)
    printf("\tmode NORMAL\nmute: %d\nverbose: %d\nexport %s\n", NORMAL->mute, NORMAL->verbose, NORMAL->exp);
  else if (inf->type == TYPE_CLIENT)
    printf("\tmode CLIENT\nip: %d.%d.%d.%d\n", CLIENT->ip_server->octet[0], CLIENT->ip_server->octet[1], CLIENT->ip_server->octet[2], CLIENT->ip_server->octet[3]);
  else
    printf("BIZARD\n");
}
