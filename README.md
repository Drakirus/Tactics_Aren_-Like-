Tactics Arena Like  [![Build Status](https://travis-ci.org/Drakirus/Tactics_Arena_Like.svg?branch=IA_lua)](https://travis-ci.org/Drakirus/Tactics_Arena_Like/branches)
==

Notre projet, qui se déroule dans le cadre de notre premier semestre de deuxième année de licence SPI, a pour but de nous faire programmer en langage C une version, fonctionnelle sur la console et qui nous est propre, de ce jeu. Notre trinôme se compose de **Champion Pierre, Laville Martin et Mok Modira**.


# Release - 2.0 "SDL"

## Source 
lien Sprites : http://www.inet2inet.com/InetSoftware/Free_Char_Anims.asp

## Instructions de compilation

### EasySDL
```
$ git clone https://github.com/DanAurea/EasySDL
$ cd EasySDL
$ git checkout 142f60c          #Project still in development

$ cmake -G"Unix Makefiles"
OR $ cmake -G"Unix Makefiles" -DForceAMD64=ON          # For arch AMD64

$ make
$ sudo make install
$ ldconfig /usr/local/lib
```
### The Game
```
$ git clone https://github.com/Drakirus/Tactics_Arena_Like.git
$ cd Tactics_Arena_Like

# L'API Lua
$ make lua           # More info below

# Le jeux
$ make

# Enjoy
$ ./bin/out
```
####Pour les plateformes diférentes de linux :
```
$ make lua plat= ↓
```
> aix bsd c89 freebsd generic linux macosx mingw posix solaris

## Documentation
```
$ make doc
```
La documentation  générée peut être retrouvée dans **./doc/html/index.html**
### Nettoyage
```
$ make clean
$ make rmdoc
$ make lua-rm
$ make mrproper
```
## Screen

Exemple 1v1 :
![1 v 1](ressources/game_player.gif)

Exemple IA v IA
![IA vs IA](ressources/game_ia.gif)

### Release - 1.0 

https://github.com/Drakirus/Tactics_Arena_Like/releases

### Release - 1.2 "lua"

https://github.com/Drakirus/Tactics_Arena_Like/raw/IA_lua/terminal.zip

### Lien Github


https://github.com/Drakirus/Tactics_Arena_Like
