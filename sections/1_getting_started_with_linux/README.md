# Getting started with Linux for CSE 13s

Hi, welcome to CSE 13s! In this guide, we'll walk you through getting your Linux
environment set up so that you can do your work for the class.

For your work here, you need an installation of Ubuntu 24.04 LTS, which is at
the moment the latest "Long-Term Service" edition of Ubuntu, a popular [Linux
distribution](https://en.wikipedia.org/wiki/Linux_distribution).


Here are the things we will set up in this guide:

  * Your Linux installation, probably with Multipass or WSL.
  * clang, the C compiler that we'll use for this class
  * git, the version control system that we'll use for this class

And then once we've done these things, we'll be ready to start learning a few
Linux command-line basics!

# Installing Linux

You have a few options here! For many people taking this class, you will want to
put Linux in what's called a *virtual machine*. We recommend that you use
Multipass or VirtualBox if you're on Windows, and Multipass or UTM if you are on
a Macintosh. These programs let you have a Linux installation inside of your
regular operating system, like a virtual computer in your real computer.

So please pick one of the following options -- you only need one of them!!

## Windows or Mac users: Installing Linux with Multipass

This is the newest option, but may be the easiest.

Note that this may not work unless your computer supports hardware
virtualization, and you may need to turn this on in your BIOS.

If you are on Windows, you will likely need to download VirtualBox first (but
Multipass is the program that you'll actually interact with -- it just uses the
VirtualBox software under the hood).

Like with VirtualBox, on a Windows computer you will need hardware
virtualization enabled! [See here for
instructions](https://13s-docs.jessie.id/vm_setup/windows.html#enable-virtualization)
on how to enable virtualization for your computer. If you have not done this,
then Multipass will silently not work and it will be distressing.

Now, [download Multipass here](https://multipass.run/), and install it as you
would any other application. If you're on a Mac, you don't need to install
VirtualBox as well.

Once you can launch Multipass, click the "Catalogue" and pick "Ubuntu 24.04,
Noble Numbat". Name your new instance something meaningful, like perhaps
"my_13s_vm" or whatever, and give it at least 2 CPU cores, at least 8 GB of ram,
and at least 20 GB of storage space. You won't need to change any other options.

This will create an *instance*, which is Multipass terminology for a virtual
machine, and you can do your work inside this instance, although it won't have
its own graphical interface by default. We'll show you how to set one up if you
really want it.

If this works for you out of the box, you are set, and you can skip down to the
"Getting Set Up" section, below...

## Windows users: Installing Windows Subsystem for Linux

The [Windows Subsystem for
Linux](https://learn.microsoft.com/en-us/windows/wsl/) is a fairly convenient
way to get a Linux environment set up on a Windows computer!

If you'd like to try it, [take a look at these instructions
here](https://documentation.ubuntu.com/wsl/en/latest/guides/install-ubuntu-wsl2/).

If you now have your Ubuntu installed in WSL, then skip down to the next
section!

## Windows users: Installing Linux with VirtualBox

First off, install the
[VirtualBox software](https://www.virtualbox.org/wiki/Downloads), which should
be fairly straightforward; just install it as you would typically install
software for your computer.

Next, you'll need to download an Ubuntu "ISO" file. Specifically for this class,
we are using **Ubuntu 24.04 LTS**, and you will want the **Desktop** edition.
You can download the Ubuntu "ISO" file. This is a virtual DVD, the file that you
would burn to a DVD or flash to a USB drive, if you wanted to make a physical
install medium.

You can [download your Ubuntu Desktop ISO
here](https://ubuntu.com/download/desktop). You do not have to sign up to their
mailing list. The file you download should be called
"ubuntu-24.04.1-desktop-amd64.iso" or something very similar. The download may
take a few minutes.

### Creating your Linux VM

Now you can start up VirtualBox!

  * Click "New" to make a new virtual machine
  * give it a name (whatever you like; how about "13s" ?)
  * change the "ISO Image" to the ISO image you just downloaded.
  * this should set the "Type", "Subtype" and "Version" appropriately.
  * check the "Skip Unattended Installation" box.
  * on the "Hardware" tab, increase the base memory to 8192 (8 gigabytes) and
    set "Processors" to 2 or 4.
  * on the "Hard Disk" tab, increase the disk size to 32 gigabytes if your
    computer has enough space.

Then select your newly configured virtual machine and click "Start" to start
your installation process!

*NOTE*: If VirtualBox complains that you do not have virtualization enabled and
refuses to start your new VM, [see here for
instructions](https://13s-docs.jessie.id/vm_setup/windows.html#enable-virtualization)
on how to enable virtualization for your computer.

Once your VM boots, you should see "Try or Install Ubuntu" as an option on the
little menu.

Once Ubuntu boots up, click the mouse and follow the menus to configure the
system to your liking (language and accessibility preferences, etc) and select
**Install Ubuntu**. You are now installing Ubuntu onto your virtual computer.

Unless you know what you're doing, pick "Interactive Installation" and "Default
selection". You can pick "Erase disk and install Ubuntu" -- this is your
*virtual disk*, not the hard drive for your actual computer.

Now let Ubuntu install!

Once it's done installing, it should give you the option to restart. Click
"Restart Now".

*NOTE:* When the message comes up that says "Please Remove the installation medium, then
press ENTER", you need to do this! Make sure to *EJECT THE ISO* at this point!
Doing this this will prevent the virtual machine from trying to boot from the
ISO image on its next boot -- you want the VM to boot from the virtual hard
drive, not the Ubuntu install ISO.

In order to do this, go to the "Devices" drop-down menu in VirtualBox, pick
"Optical Drives", and then click "Remove disk from virtual drive". Once you've
ejected the ISO image, you can restart your VM, and it should boot up and allow
you to log in!

Now skip down to the "Getting Set Up" section, below...


## Mac Users: Installing Linux with UTM

If you have an older Mac, ie, one that has an Intel chip rather than the newer
Apple Silicon (M1, M2, etc) chips, then you should actually use VirtualBox!
Follow the Windows instructions above.

Now, if you have an Apple Silicon Chip (M1 or newer), you will want to 
download an Ubuntu "ISO" file. Specifically for this class,
we are using **Ubuntu 24.04 LTS**, and you will want the **Desktop** edition,
specifically for an ARM chip, which is the particular kind of computer that
Apple Silicon is.
You can [download the Ubuntu "ISO" file
here](https://cdimage.ubuntu.com/daily-live/20240421/); you want the "Desktop"
version for
ARM, which should have a filename like "noble-desktop-arm64.iso". This is a
virtual DVD, the file that you would burn to a DVD or flash to a USB drive, if
you wanted to make a physical install medium.

At this point, you can now follow along with the older UTM instructions, except
that you are using the "Desktop" version of the ISO. Please find 
[UTM installation instructions from Jess Srivinas here](https://13s-docs.jessie.id/vm_setup/mac).

Note, however, that these instructions assume you're installing the "Server"
version of Ubuntu, but you are installing the "Desktop" version. Also you can
skip the bit about "Setup Port forwarding and SSH".


## I want to run Linux directly on the computer!

This is a thing you can do! If you know that you want to do this, you are
welcome to do it. Lots of people use Linux as their daily driver operating
system, or dual-boot Linux with something else. 

For this class, feel free to install Ubuntu 24.04 LTS (desktop edition) on your
machine. If you're the sort of person who wants to run a *different* Linux
distribution (and you have opinions already about Mint vs Arch vs Gentoo vs
NixOS...), we won't stop you but keep in mind that this is unsupported.


# Getting Set Up Now That We Have Installed Linux

If you've gotten this far, you're doing great, congratulations!

  * Once you've rebooted your VM and brought it back up, log in.
  * You can start a terminal to start entering commands by clicking the Ubuntu
    logo in the bottom-left corner and clicking "Terminal", or by pressing
    Ctrl + Alt + T. You can also tap the "Windows" button (or similar) and just
    start typing the name of a program.
  * We will spend a lot of our time in this class in the terminal.
  * One of the most important commands that you need to learn how to use is
    "apt" -- this is the package manager for Ubuntu (and similar Linux
    distributions in the Debian family)
  * You can install software that you need with "apt".


To install git, open a Terminal window and type:

```
  sudo apt install git
```

It will ask you for your password. This is normal, type your password!

Similarly, to install clang, type:

```
  sudo apt install clang
```

Now you need a text editor! The one that Alex (and Kerry) generally use is vim!
You can imagine how you might install this.

```
  sudo apt install vim
```

# Command line basics

If you've gotten this far, you are doing *great*.

Ask your TA or some of the course staff to explain how to use the following
commands.

  * `cd`
  * `ls`
  * `mkdir`
  * `rm`
  * `rmdir`
  * `touch`
  * `cat`
  * `man`

If you don't know how to use a particular command, `man` is a great way to find
out -- this gives you the documentation for that command!

In general, in Linux, if a command is running and you want to make it stop, you
can press Ctrl + C to interrupt it. For example, if you type `cat` by itself, it
will sit there seemingly forever. Stop it by pressing Ctrl + C.

As an exercise for yourself, try to make a directory, go into it, and add a file
to that directory. You can use `touch` or `gedit` to create the file! (gedit is
a simpler editor that you can use until you've learned to use vim or something
else)


# That's a lot.

There's so much to learn. We're just getting started! See you in the next
section, in person!
