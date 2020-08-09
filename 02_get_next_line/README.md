## :notebook_with_decorative_cover: get_next_line

#### :page_facing_up: Function name

- **get_next_line**

#### :page_facing_up: ​Prototype

- ```c
  int get_next_line(int fd, char **line);
  ```

#### :page_facing_up: Turn in files

- `get_next_line.c`, `get_next_line_utils.c`, `get_next_line.h`

#### :page_facing_up: ​Description

- **Write a function which returns a line read from a file descriptor, without the newline.**

#### :page_facing_up: Parameters

- `int fd` : file descriptor for reading
- `char **line` : The value of what has been read

#### :page_facing_up: Return value

- `1 ` : A line has been read
- `0` : EOF has been reached
- `-1` : An error happened

------

#### :page_facing_up: Comments In header file ([get_next_line.h](/02_get_next_line/get_next_line.h))

- ```c
  # include <stdlib.h> /* To use 'malloc', 'free' function */
  # include <fcntl.h> /* To use 'read' function */
  # include <unistd.h> /* To use 'write' function */
  # include <limits.h> /* To use 'OPEN_MAX' defined macro */
  
  /* Libft functions */
  size_t	ft_strlen(const char *str);
  char	*ft_strdup(const char *str);
  char	*ft_strchr(const char *str, int c);
  char	*ft_substr(char const *s, unsigned int start, size_t len);
  char	*ft_strjoin(char *s1, char *s2);
  
  /* Read 'buffer' and attach it to 'store' */
  int	read_buffer(int fd, char **store);
  /* Split 'store' by newline and save it in 'line' and 'store' */
  void	split_store(char **store, char **line);
  /* Check errors, call sub functions if needed, and return the value. */
  int	get_next_line(int fd, char **line);
  ```

------

#### :page_facing_up: Example

- file.txt *(\n -> line feed)*

  ```
  "Lorem ipsum dolor sit amet,(/n)
  consectetur adipiscing elit,(/n)
  sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.(/n)
  Ut enim ad minim veniam,(/n)
  quis nostrud exercitation ullamco(/n)
  laboris nisi ut aliquip ex ea commodo consequat.(/n)
  Duis aute irure dolor in reprehenderit in(/n)
  voluptate velit esse cillum dolore eu fugiat nulla pariatur.(/n)
  Excepteur sint occaecat cupidatat non proident,(/n)
  sunt in culpa qui officia deserunt mollit anim id est laborum."
  ```

------

- main_01.c

  ```c
  #include <stdio.h>
  
  int main(void)
  {
  	int return_value;
  	int fd;
  	char *line = 0;
  
  	fd = open("./file.txt", O_RDONLY);
  	return_value = get_next_line(fd, &line);
  	printf("line %d : %s\n", idx, line);
  	free(line);
  	printf("\nreturn value = %d", return_value);
  	return (0);
  }
  ```

- a.out (`gcc gnl.c gnlutils.c gnl.h main_01.c -D BUFFER_SIZE=123`)

  ```
  line 1 : "Lorem ipsum dolor sit amet,
  
  return value = 1
  ```

------

- main_02.c

  ```c
  #include <stdio.h>
  
  int main(void)
  {
  	int return_value;
  	int fd;
  	int idx;
  	char *line = 0;
  
  	fd = open("./file.txt", O_RDONLY);
  	idx = 1;
  	while ((return_value = get_next_line(fd, &line)) > 0)
  	{
  		printf("line %d : %s\n", idx, line);
  		idx++;
  		free(line);
  	}
  	printf("line %d : %s\n", idx, line);
  	free(line);
  	printf("\nreturn value = %d", return_value);
  	return (0);
  }
  ```

- a.out (`gcc gnl.c gnlutils.c gnl.h main_02.c -D BUFFER_SIZE=123`)

  ```
  line 1 : "Lorem ipsum dolor sit amet,
  line 2 : consectetur adipiscing elit,
  line 3 : sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.
  line 4 : Ut enim ad minim veniam,
  line 5 : quis nostrud exercitation ullamco
  line 6 : laboris nisi ut aliquip ex ea commodo consequat.
  line 7 : Duis aute irure dolor in reprehenderit in
  line 8 : voluptate velit esse cillum dolore eu fugiat nulla pariatur.
  line 9 : Excepteur sint occaecat cupidatat non proident,
  line 10 : sunt in culpa qui officia deserunt mollit anim id est laborum."
  
  return value = 0
  ```



------

#### :link: Test Tools Links

- [**42TESTERS-GNL** by Mazoise](https://github.com/Mazoise/42TESTERS-GNL)

- [**gnlkiller** by DontBreakAlex](https://github.com/DontBreakAlex/gnlkiller)

- [**GNL_lover** by charMstr](https://github.com/charMstr/GNL_lover)
- [**gnl-war-machine-v2019** by Alexandre94H](https://github.com/Alexandre94H/gnl-war-machine-v2019 )

