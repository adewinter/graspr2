GRASPR Firmware Code
====================

Installation
------------

0. Install the [Teensy Loader program](https://www.pjrc.com/teensy/loader.html)
1. Install [PlatformIO IDE](https://docs.platformio.org/en/latest/integration/ide/vscode.html#installation). PlatformIO is a plugin for Visual Studio Code, so if you already use VSCode you'll be right at home.
2. Once it's all installed hopefully you will see a "PIO Home" tab open up when you load vscode.  In that tab, go to "Projects"
3. Click "Add Existing", select the folder where you cloned this repo and click "Open".
4. In the "PLATFORMIO: PROJECT TASKS" menu on the left hand side, navigate to 'teensy41' -> 'General' and click on 'Build'. This will compile the C code of this project into ARM compatible machine code for the teensy.  NOTE: if you do not see the "PLATFORMIO: PROJECT TASKS" menu: go to "View" (located in the top menu bar within Visual Studio Code) -> "Open View" and type "Project Tasks" and hit enter.  This should open it up for you.
5. Once everything is built successfully (prior step), click on "Upload" to upload the code to your teensy. Make sure your teensy is plugged in.

Optional:
If you want to verify the code is running you can either click on "Monitor" in the Project Tasks menu (right below the Upload option you clicked in step 5) OR you can run the [graspr python print_to_terminal](https://github.com/adewinter/graspr2-client/blob/master/bin/print_to_terminal.py) program so that it'll dump the values to your terminal. Your call!

