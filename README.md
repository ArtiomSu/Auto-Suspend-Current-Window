# Auto-Suspend-Current-Window
Suspend/Resume current active window using keybindings. Written in c++ for windows only as it attaches the debugger to suspend the process.

The point of this program is to be able to "pause" programs using keybindings. 

If the keybindings are matched the program will will play a windows sound and process the action.

By default the console window will be hidden when running the exe.

#### default sounds used
`C:\\Windows\\Media\\Windows Notify.wav` for toggling suspend state.

`C:\\Windows\\Media\\Speech Off.wav` for exiting this program.

# Keybindings
The default keybindings are hold `left shift + a + s + o + p` to toggle between suspending and resumming current active window.

The keybinding to exit this program is by holding `left shift + w + e + k`

# Setup
1. clone the repo
2. open the solution in visual studio
3. In `AutoSuspend.cpp` you can edit the config, comments explain what everything does.
4. In `KeyboardListner.cpp` you can edit the keybindings, uncomment `display_keys(keys)` it will help you see the number associated with each key.
5. Select Release, x64 and run the build. Your exe will be generated in x64 folder.
