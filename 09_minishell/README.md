## :notebook_with_decorative_cover: minishell

```
  __  __ ___ _  _ ___ ___ _  _ ___ _    _
 |  \/  |_ _| \| |_ _/ __| || | __| |  | |
 | |\/| || || .` || |\__ \ __ | _|| |__| |__
 |_|  |_|___|_|\_|___|___/_||_|___|____|____| @yechoi @jwon

```

#### :page_facing_up: Program name

- **`minishell`**

#### :page_facing_up: Description

- Write a shell (like a bash)

#### :page_facing_up: Mandatory part

- Show a prompt when waiting for a new command
- Search and launch the right executable (based on the PATH variable or by using relative or absolute path) like in bash
- It must implement the builtins like in bash:
  - `echo` with option `’-n’`
  - `cd` with only a relative or absolute path
  - `pwd` without any options
  - `export` without any options
  - `unset` without any options
  - `env` without any options and any arguments
  - `exit` without any options
- `;` in the command should separate commands like in bash
- `'` and `"` should work like in bash except for multiline commands
- Redirections `<` `>` `“>>”` should work like in bash except for file descriptor aggregation

------

#### :page_facing_up: Screenshot
