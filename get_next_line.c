#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static char *read_line(int fd, char *line)
{
    //leak
    char *buffer;
    ssize_t size;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return NULL;
    size = 1;
    while(!ft_strchr(line, '\n') && size != 0)
    {
        size = read(fd, buffer, BUFFER_SIZE);
        if (size == -1)
        {
                free(line);
                free(buffer);
                return NULL;
        }
        buffer[size] = '\0';
        line = ft_strjoin(line, buffer);
    }
    free(buffer);
    return (line);
}
static char *set_line(char *line)
{
     char *tmp_line;
    size_t i;

    i = 0;
    if (line[i] == '\0')
        return (NULL);
    while (line[i] && line[i] != '\n')
        i++;
    if (line[i] == '\n')
        i++;
    tmp_line = malloc(sizeof(char) * (i + 1));
    if(!tmp_line)
        return NULL;
    i = 0;
    while(line[i] && line[i] != '\n')
    {
        tmp_line[i] = line [i];
        i++;
    }
    if (line[i] == '\n')
        tmp_line[i++] = '\n';
    tmp_line[i] = '\0';
    return(tmp_line);
}
static char *clean_line(char *line)
{
    size_t i;
    size_t j;
    size_t t;
    char* cl_line;
    
    i = 0;
    while(line[i] != '\n' && line[i])
        i++;
    if(line [i] == '\n' && line[i])
        i++;
    t = 0;
    cl_line = malloc (sizeof(char) * (ft_strlen(line)- i + 1));
    if (!cl_line)
        return NULL;
    j = 0;
    while(line[i])
    {
        cl_line[j] = line[i];
        i++;
        j++;
    }
    cl_line[j] = '\0';
    free(line);
    return(cl_line);

}
char *get_next_line(int fd)
{
    static char *line;
    char *tmp_line;
    //char *c_line;

    if (fd < 0 || BUFFER_SIZE < 0)
        return NULL;
    line = read_line(fd, line);
    if(!line)
        return NULL;
    tmp_line = set_line(line);
    //if(!tmp_line)
    //    return NULL;
    line = clean_line(line);
    //if(!c_line)
    //{
    //    free(tmp_line);
    //    return NULL;
    //}
    //line = c_line;
    return (tmp_line);
}

int main()
{
  int fd = open("deneme.tcy", O_RDONLY);
    char *str;
    str = get_next_line(fd);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fd);
    }
    close(fd);
    return 0;
    
}