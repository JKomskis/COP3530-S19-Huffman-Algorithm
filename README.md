# COP3530-S19-Huffman-Algorithm

## Installation & Setup

### Windows

#### Option 1: Windows Subsystem for Linux (recommended)

Note: This will only work on Windows 10. If you are using another version of Windows see option 2

1. Open PowerShell as Administrator and run:

```PowerShell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

1. Restart your computer when prompted
2. Follow [this link](https://www.microsoft.com/store/p/ubuntu/9nblggh4msv6) to go to the Microsoft Store and click "Get" to install the Ubuntu distro.
3. Click the "Launch" button in the Windows store or launch the new "Ubuntu" app from the start menu.
4. Wait for the installation to complete
5. Follow the console prompts to create a new user and password
6. Run the following command in the terminal prompt to update your packages:

```bash
sudo apt update && sudo apt upgrade
```

7. Run the following command to install the g++ compiler and make:

```bash
sudo apt-get install build-essential
```

Sources:

* https://docs.microsoft.com/en-us/windows/wsl/install-win10
* https://docs.microsoft.com/en-us/windows/wsl/initialize-distro

#### Option 2: MinGW

1. Follow [this link](https://osdn.net/projects/mingw/releases/) and download the mingw-get-setup.exe file (look for the blue button with the Windows logo and the down arrow)
2. Run the installer, and click the "Install" button.
3. On the next screen, leave the default options (you can disable the start menu shortcut or desktop shorcut options if you'd like) and click "Continue".
4. Wait for the setup process to complete and click "Continue".
5. The MinGW Installation Manager will then open. Click the checkboxes for "mingw32-base-bin", "mingw32-gcc-g++-bin", and "msys-base-bin" and click "Mark for Installation".
6. In the top menu, click "Installation">"Apply Changes". Click "Apply" to confirm the changes.
7. Open the Control Panel (you can search for this in the start menu), change the "View by:" to "Category" in the top right, click on the "System and Security" category, then click on the "System" section. On the left side, click "Advanced System Settings".
8. Click the "Environment Variables..." button, click on the "Path" entry under "User variables for your username".
9. Click "New" then "Browse...", and add the "C:\MinGW\bin" folder.
10. Repeat Step 9 for the "C:\MinGW\msys\1.0\bin" folder.
11. Click "OK" to close all the previously opened dialogs to save your new settings.

### Linux

1. Open your terminal of choice
2. Run the following command to update your packages:

```bash
sudo apt update && sudo apt upgrade
```

3. Run the following command to install the g++ compiler and make:

```bash
sudo apt-get install build-essential
```

### Mac

1. Open Terminal (command + space and type terminal)
2. Run the following command to install the Homebrew package manager for macOS: 

```bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
```
3. Once complete, run the following command to update Hombrew and install GNU compiler collection 8:

```bash
brew update && brew upgrade && brew install gcc@8
```

4. Once complete, run the following command to update your PATH environment variable and link g++ to g++-8:
 
 ```bash
 echo "PATH=\"/usr/local/bin:$PATH\"" >> ~/.bash_profile && ln -s /usr/local/bin/g++-8 /usr/local/bin/g++
 ``` 

5. Close all Terminal sessions for changes to take effect: 
- hold command and press tab to view open programs
- while holding command key tab until Terminal instance is selected
- press Q once Terminal icon is selected to quit all Terminal sessions

6. Reopen Terminal and test successful installation of g++ by typing g++ and ensuring you get the follwing as output:

```bash
g++: fatal error: no input files
compilation terminated.
```

## Usage

1. Open your terminal (Ubuntu you're on Windows and following option 1, Command Prompt if you're on Windows and following option 2, your terminal of choice if you're on Linux, or Terminal if you're on a Mac)
2. Navigate to the folder containg the project skeleton. The "cd" command will allow you to change directories. If you want to see what is inside a directory, use the "ls" command.
3. Run "make" in the project skeleton folder to automatically build the project and run it against the test cases. If everything works properly you should see a couple commands run on the terminal, and a line at the very end that says "All tests passed (1 assertion in 1 test case)".

Note: The first build can take up to 30 seconds as it has to compile everything. Subsequent build should be much faster, as it will only recompile the files that have changed.

If you are experiencing problems compiling and running the project, run "make clean" to delete all compiled files. Then, trying running "make" again.

## Resouces

* https://spin.atomicobject.com/2016/08/26/makefile-c-projects/
* https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html#Wildcard-Function
* https://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in
* https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
* https://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory
