## :notebook_with_decorative_cover: cub3D

#### :page_facing_up: Program name

- **`cub3D`**

#### :page_facing_up: Description

- You must create a “realistic” 3D graphical representation of the inside of a maze from a first person perspective. 
- You have to create this representation using the Ray-Casting principles mentioned earlier.

#### :page_facing_up: Mandatory part

- You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part.
- The management of your window must remain smooth: changing to another window, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West). 5 cub3D My first RayCaster with miniLibX
- Your program must be able to display an item (sprite) instead of a wall.
- Your program must be able to set the floor and ceilling colors to two different ones.
- In case the Deepthought has eyes one day to evaluate your project, your program must save the first rendered image in bmp format when its second argument is "––save".
- If no second argument is supllied, the program displays the image in a window and respects the following rules:
  - The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
  - The W, A, S and D keys must allow you to move the point of view through the maze.
  - Pressing ESC must close the window and quit the program cleanly.
  - Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
  - If the declared screen size in the map is greater than the display resolution, the window size will be set depending to the current display resolution.
  - The use of images of the minilibX is strongly recommended.
- Your program must take as a first argument a scene description file with the .cub extension

#### :page_facing_up: Bonus list

- [x] Wall collisions.
- [x] A skybox.
- [ ] Floor and/or ceiling texture.
- [ ] An HUD.
- [x] Ability to look up and down.
- [ ] Jump or crouch.
- [ ] A distance related shadow effect.
- [x] Life bar.
- [x] More items in the maze.
- [x] Object collisions.
- [x] Earning points and/or losing life by picking up objects/traps.
- [x] Doors which can open and close.
- [x] Secret doors.
- [ ] Animations of a gun shot or animated sprite.
- [ ] Several levels.
- [x] Sounds and music.
- [ ] Rotate the point of view with the mouse.
- [ ] Weapons and bad guys to fight!

#### :page_facing_up: How to use leaks command

1. Run **cub3d**.

   ```bash
   > make
   > ./cub3D maps/map.cub
   ```

2. Find Process ID(PID).

   ```bash
   > ps
   ```

   ```bash
     PID TTY           TIME CMD
   12321 ttys001    0:00.31 -zsh
   12345 ttys001    0:02.93 ./cub3D maps/map.cub
   ```

3. Check a memory leaks.

   ```bash
   > while 1; do leaks 12345; sleep 5; clear; done
   ```

   ```bash
   Process:         cub3D [12345]
   Path:            /Volumes/VOLUME/*/cub3D
   Load Address:    0x103a7f000
   Identifier:      cub3D
   Version:         ???
   Code Type:       X86-64
   Parent Process:  zsh [12321]
   
   Date/Time:       2020-01-01 00:00:00.001 +0900
   Launch Time:     2020-01-01 00:00:00.001 +0900
   OS Version:      Mac OS X 10.14.6 (18G6020)
   Report Version:  7
   Analysis Tool:   /Applications/Xcode.app/Contents/Developer/usr/bin/leaks
   Analysis Tool Version:  Xcode 10.2.1 (10E1001)
   
   Physical footprint:         38.2M
   Physical footprint (peak):  38.3M
   ----
   
   leaks Report Version: 4.0
   Process 12345: 20837 nodes malloced for 19396 KB
   Process 12345: 0 leaks for 0 total leaked bytes.
   ```

#### :page_facing_up: Screenshot

<div align=center>
<img width="800" src="https://user-images.githubusercontent.com/61400214/89755696-4b2c0f00-db1b-11ea-9257-50cbe28eb16e.png"><br>
<img width="800" src="https://user-images.githubusercontent.com/61400214/89755708-50895980-db1b-11ea-90fc-4b6aa3d2238b.png"><br>
<img width="800" src="https://user-images.githubusercontent.com/61400214/89755709-5121f000-db1b-11ea-8307-08ba0373473c.png">
</div>