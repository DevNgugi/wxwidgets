INSTALLING WXWIDGETS

```
sudo apt install build-essential
sudo apt install libgtk2.0-dev             
sudo apt install libgtk-3-dev

wget https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.5/wxWidgets-3.2.5.tar.bz2
tar -xvjf wxWidgets-3.2.5.tar.bz2

mkdir gtk-build             # the name is not really relevant
cd gtk-build
../configure                # builds unicode, shared lib
make -j3                    # use 3 cores. Set to the number of cores you have. 'make' uses 1 core
sudo make install           # some platforms require to use 'su' instead of 'sudo'
sudo ldconfig 

Test:
wx-config --version 

```

While using Vscode, I encountered this error, and solved it as such:

```
_The problem was mainly because of the VSCode's environment variable. A detailed solution is mentioned here Java: symbol lookup error: /snap/core20/current/lib/x86_64-linux-gnu/libpthread.so.0: undefined symbol: __libc_pthread_init, version GLIBC_PRIVATE_

SOLUTION:

unset GTK_PATH

```

