# Air Strike
#### A GBA game built with [APIagb](https://github.com/linobigatti/APIagb).

[![forthebadge](https://forthebadge.com/images/badges/compatibility-club-penguin.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/powered-by-electricity.svg)](https://forthebadge.com)

## A little introduction
I was sitting on my chair, seeing my code editor ([Notepad++](https://notepad-plus-plus.org/)), while thinking: "I need to add Window support to APIagb. Easy. But, what can the demo be?". It was a hard question. And then I realized an idea for a window demo. A plane flying above the clouds, while searching for an island to bomb, using a radar. But that idea was too much for a demo. So I created a game.

## Play the ROM
You don't need to bother compiling the game to play it, you can get the compiled ROM in [the releases section](https://github.com/LinoBigatti/air-strike/releases). The controls are the following:
**D-PAD**: Move the player or the radar.
**Start**: Alternate between the player and radar mode.
**A**: Release the bomb. (Player mode only)

## Compile from source
For compiling the game from the source, you will need:
1. [DevkitARM](https://devkitpro.org/).
2. An unix-like development enviroment, with:
	1. [GNU make](https://www.gnu.org/software/make/).
3. A copy of this repository.

### Windows

#### Installing the dependencies
First, install DevkitARM following [this guide](https://devkitpro.org/wiki/Getting_Started).
Then, install the unix-like console [CygWin](https://www.cygwin.com/). Make sure the GNU-make package is selected.
Then [clone](https://help.github.com/en/articles/cloning-a-repository) [this repository](https://github.com/linobigatti/Air-Strike).

#### Building the code

Open **CygWin** and write:
```bash
cd path/to/the/directory/with/the/source
```

Then, run make:
```
make
```

That's it!

### Ubuntu and other unix-based systems

#### Installing the dependencies
First, install DevkitARM following [this guide](https://devkitpro.org/wiki/Getting_Started).
GNU make is pre-installed in some distributions, and in others it isn't. So install it:
```bash
sudo apt-get install build-essential
```
Then clone this repository:
```
git clone https://github.com/linobigatti/Air-Strike
```

#### Building the code

Open the reminal and write:
```bash
cd path/to/the/directory/with/the/source
```

Then, run make:
```
make
```

That's it!

## Credits

### Built with
* [DevkitARM](https://devkitpro.org/)
* [C](https://en.wikipedia.org/wiki/C_%28programming_language%29)
* [APIagb](https://github.com/linobigatti/APIagb)
* [Make](https://www.gnu.org/software/make/)
* [CygWin](https://www.cygwin.com/)
* [Usenti](http://www.coranac.com/projects/usenti/)
* [Grit](www.coranac.com/projects/grit/)
* [Adobe Photoshop](https://www.adobe.com/products/photoshop.html)
* [NO$GBA](https://problemkaputt.de/gba.htm)
* [GBAFIX](https://github.com/devkitPro/gba-tools/blob/master/src/gbafix.c)
* [MapEd](http://nessie.gbadev.org/)
* [ForTheBadge](https://forthebadge.com/)

### Contributors
* [L!no](http://www.lino-bigatti.tk): The main coder of the game.
* Maddalena: Contributed with the cloud tiles.