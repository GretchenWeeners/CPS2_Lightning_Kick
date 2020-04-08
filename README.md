# CPS2_Lightning_Kick
CPS2 2-Player / 4-Player switch with Darksoft's CPS2 Multi-Kit support

**This will allow you to switch between 2-player and 4-player button layouts on the CPS2 (Capcom System II) arcade cabinet using either a manual switch or automatically with an Arduino and Darksoft's CPS2 Multi-Kit.**

Parts needed:

- A 4 Player arcade cabinet with a CPS2
- 4 extra arcade buttons
- 14 relays (more if you want light up buttons / accessories to switch with the relays)
- A bunch of wire
- An on/off switch
- (optional) An Arduino (for automatic switching with the CPS2 Multi-Kit)
- Patience



Instructions:
 - This assumes you are starting with a standard 4 player setup
 - Add two extra buttons each for Player 1 and Player 2 (do not connect yet)
 - Disconnect the remaining 4 action buttons for Player 1 and Player 2
 - Disconnect the following on Player 3:
		 - Joystick Right
		 - Joystick Left
		 - Joystick Up
		 - Attack
		 - Jump
		 - Coin
- Reconnect everything to relays using this schematic:
![enter image description here](https://raw.githubusercontent.com/GretchenWeeners/CPS2_Lightning_Kick/master/Schematic%20with%20switch.png)
- Test everything. If it doesn't work, check all the things
- (optional) use the additional 2 relays to hook up button lights or whatever accessories you want to switch between
- If you dont have a Multi-Kit, you are done



Additional steps for Multi-Kit: 
- Remove the switch you installed for testing, and wire up an Arduino (I used an Uno) to the relays and to the Multi-Kits' LCD as per this schematic:
![enter image description here](https://raw.githubusercontent.com/GretchenWeeners/CPS2_Lightning_Kick/master/Schematic%20with%20arduino.png)- Upload [CPS2_Lightning_Kick.ino](https://github.com/GretchenWeeners/CPS2_Lightning_Kick/blob/master/CPS2_Lightning_Kick.ino) to the arduino 
- ???
- Profit
