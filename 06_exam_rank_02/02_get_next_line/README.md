## :notebook_with_decorative_cover: get_next_line(exam_rank_02)

#### :page_facing_up:  subject.en.txt

- ```
  Assignment name  : get_next_line
  Expected files   : get_next_line.c get_next_line.h
  Allowed functions: read, free, malloc
  --------------------------------------------------------------------------------
  
  Write a function will store, in the parameter "line", a line that has been read from the file descriptor 0.
  
  Your function must be prototyped as follows: int get_next_line(char **line);
  Your function should be memory leak free.
  
  ```

#### :page_facing_up:  Commands

- Compile

  ```
  gcc -Wall -Werror -Wextra get_next_line.c main.c -I ./ -o get_next_line
  ```

- Test

  ```
  ./get_next_line < testfile.txt(ex. get_next.line.c)
  ```