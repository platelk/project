/*
** puterror.h for puterror in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 17:10:02 2012 harold ozouf
** Last update Sun Apr 15 16:52:20 2012 harold ozouf
*/

#ifndef		__PUT_ERROR_H__
# define	__PUT_ERROR_H__

#include	"token.h"

#define		NULL_CMD	"Invalid null command"
#define		UNMATCH		"Unmatched"
#define		TOO_MANY	"Too many"
#define		MISSING_N	"Missing name for redirect"
#define		AMB_OUT		"Ambiguous output redirect"
#define		AMB_IN		"Ambiguous input redirect"

t_bool	puterror(char *err, char *content);

#endif
