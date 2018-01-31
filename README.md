# F1Telemetry

A telemetry app that can be used as an overlay for streamers and gamers who play the F1 2017 video game. This app and it's developer have no ties to F1, FIA or Codemasters. The App is made for the soul purpose of capturing the udp telemetry that is broadcasted by the game and renders it on the screen.

## Video Exampele of how the overlay looks in game:
https://clips.twitch.tv/DepressedProudDiscFeelsBadMan

## App demonstration:
https://streamable.com/pzbnp

## Screen shot:
![alt text](https://i.imgur.com/VlxnhZS.png "Main view")


## How to use:

- Build with Qt 5.10 for release.

- Run the application.

- In OBS:

- Add a new window capture source to the scene.

- Chose the application from the drop down menu and press 'save'.

- Right click the new window capture source in the scene and chose 'Filters'.

- Add a color Key filter, not a chroma key, set the color to #000000.

- Adjust the smoothness and opacity to your liking & hit 'save'.

- Make sure that the application is not minimized while in use.

Enjoy. :)
