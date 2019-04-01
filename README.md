# COP3530-S19-Huffman-Algorithm

## Project Completion & Submission Guidelines and Notes

Your goal in this project is to implement the interface of a Huffman Tree class to encode and decode data based on character frequencies. To accomplish this, you will complete the function stubs provided in `huffman_tree.cpp`. If you would like to add additional helper functions or structs, you may declare them in `huffman_tree.h` and define them in `huffman_tree.cpp`. Do not change the interface of any existing functions, it will cause your project to fail the test cases we run against it. A few test cases are provided in `tests.cpp` so you can verify your interface is working properly. When we grade the projects, we will add additional tests cases to verify your implementation is correct. The provided tests are not thorough and do not guarantee your project will pass our test cases. You are encouraged to make your own tests cases. Outside of `huffman_tree.h`, `huffman_tree.cpp`, and `tests.cpp`, you should not modify any files.

Instructions are provided below so you can develop the project on your local machine. However, to make grading as uniform and easy as possible, you must SSH into storm.cise.ufl.edu and test your project there before submitting. While we do not expect any significant differences between compilers on different platforms, you never know.

To submit the project, submit **only** your `huffman_tree.cpp` and `huffman_tree.h` files to canvas. Attach each file individually, do **not** zip, tar, or compress them. We will have a script that copies your files into a clean project, adds our test cases, and runs the tests against your implementation.

## Installation & Setup

### Windows

#### Option 1: Windows Subsystem for Linux (recommended)

Note: This will only work on Windows 10. If you are using another version of Windows see option 2

1. Open PowerShell as Administrator and run:

    ```PowerShell
    Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
    ```

2. Restart your computer when prompted
3. Follow [this link](https://www.microsoft.com/store/p/ubuntu/9nblggh4msv6) to go to the Microsoft Store and click "Get" to install the Ubuntu distro.
4. Click the "Launch" button in the Windows store or launch the new "Ubuntu" app from the start menu.
5. Wait for the installation to complete
6. Follow the console prompts to create a new user and password
7. Run the following command in the terminal prompt to update your packages:

    ```bash
    sudo apt update && sudo apt upgrade
    ```

8. Run the following command to install the g++ compiler and make:

    ```bash
    sudo apt-get install build-essential
    ```

Sources:

* <https://docs.microsoft.com/en-us/windows/wsl/install-win10>
* <https://docs.microsoft.com/en-us/windows/wsl/initialize-distro>

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

4. Once complete, run the following commands to update your PATH environment variable and link g++ to g++-8:

    ```bash
    echo "PATH=\"/usr/local/bin:$PATH\"" >> ~/.bash_profile
    ```
    ```bash
    sudo ln -s /usr/local/bin/g++-8 /usr/local/bin/g++
    ```

5. Close all Terminal sessions for changes to take effect:

   * hold command and press tab to view open programs
   * while holding command key tab until Terminal instance is selected
   * press Q once Terminal icon is selected to quit all Terminal sessions

6. Reopen Terminal and test successful installation of g++ by typing g++ and ensuring you get the follwing as output:

    ```bash
    g++: fatal error: no input files
    compilation terminated.
    ```

## Usage

1. Go to to the releases page (<https://github.com/JKomskis/COP3530-S19-Huffman-Algorithm/releases>) and download the zip folder for the latest version of the project.
2. Extract the zip folder.
3. Open your terminal (Ubuntu you're on Windows and following option 1, Command Prompt if you're on Windows and following option 2, your terminal of choice if you're on Linux, or Terminal if you're on a Mac)
4. Navigate into the project folder. The "cd" command will allow you to change directories. If you want to see what is inside a directory, use the "ls" command.
5. Run "make" in the project skeleton folder to automatically build the project and run it against the test cases. If everything works properly you should see a couple commands run on the terminal. When you first start the project, running make should output "test cases:  7 |  1 passed |  6 failed \n assertions: 51 | 24 passed | 27 failed". When you finish implementing the interface properly, it should instead output "All tests passed (X assertions in X test cases)".

Note: The first build can take up to 30 seconds as it has to compile everything. Subsequent build should be much faster, as it will only recompile the files that have changed.

If you are experiencing problems compiling and running the project, run "make clean" to delete all compiled files. Then, trying running "make" again.

## Resouces

* <https://spin.atomicobject.com/2016/08/26/makefile-c-projects/>
* <https://www.gnu.org/software/make/manual/html_node/Wildcard-Function.html#Wildcard-Function>
* <https://stackoverflow.com/questions/2908057/can-i-compile-all-cpp-files-in-src-to-os-in-obj-then-link-to-binary-in>
* <https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html>
* <https://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory>
