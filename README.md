# get_next_line

## Introduction
This *42* project consists in creating a function that fill a buffer of a line from the file given in argument.

Each call of the function give **the next line** of the file.

## Usage
The fuction is prototyped like this :

    int get_next_line(int fd, char **line);

* *fd* : a file descriptor
* *line* : the buffer address


### Example
    #include "get_next_line.h"

    int	main(int ac, char **av)
    {
        int		fd;
        char	*line;

        fd = open(av[1], O_RDONLY);
        while (get_next_line(fd, &line) == 1)
        {
            // Print then Free "line"
        }
        return (0);
    }
