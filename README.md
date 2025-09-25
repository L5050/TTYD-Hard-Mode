# Overview
This is an open beta of a mod for the original version of Paper Mario: The Thousand Year Door, that aims to make the general experience much more difficult and rebalance some poorly done game mechanics in the original game.

# General Changes
- All standard enemies have a x2 HP and x2 attack buff
- All boss fights have custom health, defense, and attack, and reworked status vulnerabilities

# Badge Changes
- Power Rush can no longer be obtained from the Pianta Parlor and costs 3 BP
- Hammer Rattle now acts as a Power Bounce for hammer, costs 6 FP to use
- Peekaboo, Pity Flower, Quick Change, and Return Postage all cost 0 BP
- Last Stand and Pretty Lucky now cost 3 BP
- Lucky Day now costs 8 BP
- Hammer Throw now pierces defense, knocks shelled enemies over, de-wings winged enemies, and costs 1 FP and 2 BP
- Lucky Start can now only give you +FP and +HP effects to make it more consistently useful
- Power Bounce is now one frame more difficult
- Charge now caps at +5 attack for both the partner and for Mario

# Changes to Mario's hammer
- The hammer now does +2 more damage than jump does for each upgrade, to balance out that jump is buffed by badges and status effects more than hammer is
- The hammer can now target any grounded foe rather than just the most frontmost foe
- All of the above badge changes

# Changes to Mario's Special Moves
- Sweet Feast costs 4 SP instead of 5
- If Clockout's bomb lands on Mario it gives him 2 extra turns rather than timing him out. Clockout's SP has been increased to 3 SP to balance this out

# Changes to Partners
## General Changes
- All partners now have new elemental strengths and weaknesses
- Goombella and Yoshi are now weak to elemental damage
- Koops has one defense against all damage and two defense against ice damage
- Flurrie has one defense against electrical attacks
- Vivian is immune to fire based attacks and is weak to ice based attacks
- Bobbery is immune to ice based attacks and weak to fire based ones
- Mowz has one defense against standard attacks and no defense against elemental attacks
- All moves that cost more than 5 FP have been lowered to 5 FP

## Partner specific changes
- Multibonk is now one frame more difficult
- Gale Force's effectiveness was lowered by 10% across the board
- Infatuate has been lowered to one FP
- Veil no longer consumes Vivian's turn
- Fiery Jinx excites the audience more than before
- Mowz's slap now does more damage and is incapable of missing (pierces fog, invisiblility, dodgy, and veil)
- Tease has been lowered to one FP

# Boss Changes
- Most bosses have x3 HP and at least 1 defense, exceptions will be listed below
- Rawk Hawk now has 1 defense in the second phase specifically
- Macho Grubba has been made weaker to Clockout
- Doopliss has 130 HP in both chapter 4 and chapter 8, Doopliss's hammer attack does 12 damage
- Doopliss while transformed into Koops cannot be knocked over
- Cortez has 100 health per phase
- Cortez's bite attack has been made unsuperguardable to keep in theme of other bite attacks and make his 3rd phase more challenging
- Smorg has 200 HP, the Smorg and Smorg Miasmas both have 4 defense, Smorg's middle finger does 2 more damage, and the Smorg Claw does 20 damage
- Magnus Von Grapple's Audience Attack always targets Mario
- Magnus Von Grapple's rocket fists have 10 HP
- Gloomtail has 240 HP
- Marilyn has 160 HP in chapter 8
- Beldam has 120 HP in chapter 8
- Marilyn's lightning attack is now incapable of missing (pierces fog, invisiblility, dodgy, and veil, doesn't pierce shell shield though)
- Grodus has 180 HP
- Both Shadow Queen fights have 400 HP

# How to install
Go to the [releases page](https://github.com/L5050/TTYD-Hard-Mode/releases) and download the most recent release from there. You will want to take the patcher and input a vanilla TTYD rom (has to be the US version of ttyd), and it'll export a rom that has the mod inside of it. Run that rom in dolphin and you'll be able to play! You can tell if the mod is working if the title screen says "TTYD-Hard-Mode" below the TTYD graphics. Feel free to join the [discord](https://discord.gg/CeXnez2Bj7) if you need more help installing the mod or if you have feedback for me :) 

# Credits
* [PistonMiner](https://github.com/PistonMiner) for their work on the TTYD scripting disassembly, the initial code for the rel framework, and the elf2rel, gcipack, and rellink utilities. (GitHub repo for these tools [here](https://github.com/PistonMiner/ttyd-tools).)  
* [Jdaster64](https://github.com/jdaster64) for their work on various TTYD modding projects, as well as their work on the headers used in Tower of Trials, which this project makes use of.  
* [SeekyCt](https://github.com/SeekyCt) for their work on **pyelf2rel**, which adds additional functionality over the original **elf2rel**, and their help and support with SPM Hard Mode, which was the inspiration for this mod.
* [Zephiles](https://github.com/Zephiles) for the mod template this project was based on, and for work on the headers that this project makes use of.
* [Diagamma](https://git.gauf.re/antoine) for the Melvin patcher which the releases of this mod are embedded in.
* [Joby "Jorby" R](https://www.youtube.com/@JobyRJorby) for helping playtest the pre-release builds and helping brainstorm ideas, several of which made it into the mod.
* [Bringle](https://www.youtube.com/@Bringlescan) for the funny icon used in the patcher.
