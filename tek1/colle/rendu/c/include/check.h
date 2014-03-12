/*
** check.h for Colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 22:22:51 2012 thomas fontaine
** Last update Thu Apr 26 22:26:07 2012 thomas fontaine
*/

#ifndef __CHECK_H__
# define __CHECK_H__
# define IS_NUM(x)       (((x < '0') || (x > '9')) ? -1 : 0)

int     check_user(int ac, char **av);

#endif
