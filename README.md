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
<kbd> ‎ F ‎ </kbd> : Display stats <br>
<kbd> ‎ M ‎ </kbd> : Move <br>
<kbd> ‎ H ‎ </kbd> : Display heat map <br>

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
✅	- coordinates on maps <br>
✅	- zoom level <br>

✅ Heat map v1<br>
⬜ Heat map v2 :<br>
	- algo for cooling cell
		heat map with float ?
		low level of temperature make decrease slowly
		high level of temperature decrease a bit more than the rest
	- colors blue -> green -> yellow -> orange -> red -> red/white (if the same cell stil alived after 10gen)

⬜ change macro in header file to variables<br>
⬜ draw lines feature <br>
⬜ Copy/paste features <br>
⬜ Pattern generator feature <br>

⬜ Achievments (structures, pattern, etc...) <br>
	start an offline wiki db where each row of structures has 1 if achieved and 0 not

⬜ Improve graphic with life (when structures disappear fireworks) <br>
	make drops/sparks comes out from cell or structures : pixels move in a random direction with the origin in the back

