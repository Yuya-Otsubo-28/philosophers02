#include "../include/struct.h"
#include "../include/prototype.h"
#include <stdlib.h>

t_data	*init_error(t_data *data)
{
	cleanup_data(data);
	return (NULL);
}
