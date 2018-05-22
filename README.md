# Ocasio
Ocasio is a game-engine based on SFML (http://www.sfml-dev.org/)

It currently has following features:
- a Texture loader for easy loading and indexing of textures
- a font loader, its a port of the Texture loader for fonts
- a RenderObject, is has following properties
-- a RenderingThread, to Optimise Performance, rendering is done in a Seperate thread from the Gamelogic
-- Storing of pointers to drawables, so you can just add them once and forget about them (or remove them later if you so wish)
- an Animation Framework, it allows loading of Tilemaps and special .anim Files to create animated sprites with loopable or non loopable animations
- a Textf Object, its based on printf, in that it allows for strings with placeholders to be set and then variables added with fill those placeholders

Im currently working on following fetures:
- A Tilemap loader to be used for creating levels
- A Level Class with prerednering of levels
