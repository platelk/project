#ifndef __UTILS_H__
# define __UTILS_H__

#include <iostream>
#include <vector>

std::vector<std::string> 	split_string(const std::string &s, char delim);
std::vector<std::string> 	split_string(const std::string &s, const std::string &delim);
int			 			 	str_to_int(const std::string &s);
std::string					int_to_str(int i);
double		 			 	str_to_double(const std::string &s);
std::string					double_to_str(double i);

#endif /* !__UTILS_H__ */
