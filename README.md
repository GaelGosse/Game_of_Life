# Game of Life

Simple Conway's game of life coded in C with SDL2

![til](./preview.gif)

## Install and launch

in the repository, launch in the console
```
make
```
it will create an executable, that you can launch :
```
./game_of_life
```

## How to Play

<kbd> ‎ Mouse click ‎ </kbd> : make a cell alive or dead, long click while moving to affect more cells <br>
<kbd> ‎ Space ‎ </kbd> : play/pause the simulation <br>
<kbd> ‎ ⬆ ‎ </kbd> : Increase the time between each frame <br>
<kbd> ‎ ⬇ ‎ </kbd> : Decrease the time between each frame <br>
<kbd> ‎ R ‎ </kbd> : Remove every alive cells <br>
<kbd> ‎ H ‎ </kbd> : Display stats <br>
<kbd> ‎ M ‎ </kbd> : Move <br>

## Road map

✅ Display grid <br>
✅ Alive/Dead cells <br>
✅ Play & Pause features <br>
✅ Change frame rate <br>
✅ Reset map button <br>
✅ Display frame rate <br>
✅ Modifications in real time <br>

✅ Infinite map (camera view) <br>
✅ draw map with px not cell <br>

✅ key lock/unlock : move in map <br>
✅ Zoom in/Out <br>

Display stats :<br>
✅	- generation number <br>
✅	- alived cells <br>
✅	- dead cells <br>
✅	- total cells <br>
⬜	- coordinates on maps <br>
⬜	- zoom level <br>

⬜ change macro in header file to variables<br>
⬜ Define map size with arg <br>
⬜ Copy/paste features <br>
⬜ draw lines feature <br>
⬜ Pattern generator feature <br>

⬜ Heat map <br>
	create another copy map
	add one to a cell each generation when

⬜ Achievments (structures, pattern, etc...) <br>
	start an offline wiki db where each row of structures has 1 if achieved and 0 not

⬜ Improve graphic with life (when structures disappear fireworks) <br>
	make drops/sparks comes out from cell or structures : pixels move in opposite direction of origin

