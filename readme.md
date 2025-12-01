TODO:

Exercise 1:

* menu for pausing the game(may use the Screen.draw() after closing menu)
* make better room map
* display  player status with inventory(size 1) messages hints etc…
* add(see in the pdf in info folder)

  > must:
  > * two players
  > * walls
  > * keys
  > * doors
  >
  > select 3 to add:
  > * bomb
  > * switch
  > * obstacle(block you can’t go through
  > * riddle
  > * torch(if selected you need to add also dark rooms)
  > * spring

check it for windows(make the unix like systems optional in compilation)

General Notes:

* It's recommended that every element in the game will be a unique object (even doors etc.).
* I think that with a little work we can make the code a lot more intuitive and easy to use/modify 
  (Kirsh hinted it's gonna be necessary).
  Example - in player.h -> public -> void keyCheck(char key), what's keyCheck? if I'm new to the code or want to use this 
  function - isn't there a better name for this function that'll be more intuitive (like isKeyPressed or whatever)?
* It's required to create a legend on the screen that contains the held items of each player. it should be inside the 80*25
  screen.