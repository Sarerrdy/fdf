#include "fdf.h"

int validate_args(char *file)
{
    char	*file_name_len;
	char	*file_ext;

	file_ext = ft_strrchr(file, '.');
	file_name_len = file_ext - file;
	if (file_name_len < 1)
		return (0);
	if (ft_strncmp(".fdf", file_ext, ft_strlen(file_ext)) == 0)
		return (1);
	else
		return (0);
}