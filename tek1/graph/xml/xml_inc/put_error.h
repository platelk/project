/*
** put_error.h for put_error in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 14:43:28 2012 harold ozouf
** Last update Mon May  7 00:20:28 2012 alexis leprovost
*/


#ifndef		__PUT_ERROR_H__
# define	__PUT_ERROR_H__

#define		BAD_IP		"Bad ip format: [n.n.n.n] => [0] n [255]."
#define		NO_XML		"You must specify an xml file."
#define		NO_VALUE	"You must specify a value to the option :"

int	put_error(char *msg, char *value);


#endif
