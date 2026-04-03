# Learning to use the command line: bash basics

Welcome to the second section! In this edition, we'll work on some basic skills
you'll need to work with the Linux command line, both in this class, and for
your life as a software developer.

These instructions are based pretty closely on MIT's [Missing
Semester](https://missing.csail.mit.edu/)
coursework, particularly the
[first session](https://missing.csail.mit.edu/2020/course-shell/).


At this point, you should already have your Linux environment set up for the
course; if you need help with this, please ask the course staff for help in the
discord -- also you should have gone through [the instructions
here](https://git.ucsc.edu/ajrudnic/cse-13s-resources-winter-2025/-/blob/main/sections/1_getting_started_with_linux/README.md).

----

*Instructions for the TAs:*  Live-code the exercises here, taking suggestions
from the class as you go! Let's practice using the shell!

Also, make sure to pass around an attendance sheet and get a list of everybody
who attended!

----

# Using the Shell

One of the greatest things about using Linux (or similar UNIX-type operating
systems) is also one of the potentially most intimidating, and that's the
command line, the shell. This is where we do things that look like opaque,
unintelligible magic. Why can't we just do everything with nice clickable
graphic interfaces?

Well, you can do most of what you need by pointing and clicking on stuff.

But sometimes, you want to really *express what you mean* instead of pointing
and grunting. What if what you want isn't specifically in the graphical menu?
It's time to write something new and *give the computer some commands* in an
old-school, textual way.

It's not that hard. You can do this.

In Ubuntu, by default, you're using a shell called the Bourne Again SHell,
`bash`. There are other shells, and you may eventually decide that you want to
use a different one (Macs use a similar but distinct shell called `zsh` by
default), but here we'll focus on `bash`.


# Typing commands at the prompt

First, you've got to bring up your shell. If you're using Multipass, you should
have the shell up by default. If you've got a graphical Linux set up (Ubuntu
Desktop on VirtualBox, for example), bring it up by clicking the "Show
Applications" button and clicking on Terminal.

You should be greeted with a little box with a prompt that probably ends with a
dollar sign. Alex's prompt looks like this:

```
alex@judy:~$ 
```

This is where you type your commands. There are so many possible commands. Maybe
you want to know the current date and time; you can type `date` here (and hit
enter) to get the current date and time.

You could also have `bash` print out little messages back to you.

```
  $ echo good morning
```

Here when you see instructions with a `$` in them, don't type the dollar sign.
That represents the prompt, where you start typing.

Also, the prompt gives you some useful information. Let's break down what's in
here.

It tells you ...
  * *who you are* (your username)
  * the name of the computer (you probably didn't name your computer or VM
    `judy`, but you might have), and
  * *your current working directory*. Here `~` refers to your current directory;
    this is your home directory, which is represented by a tilde.

These can all change! You might become a different user (through various means),
you might log into a different system (especially with `ssh`), and you will
almost certainly go to different directories.

Let's talk about that for a moment, going to different directories.


# Navigating in the shell

At any moment, your shell has a *current working directory*, which is your
location in the nested (hierarchical) directories on the computer or VM. You
usually start out in your *home directory* when you log in, which will be
something like `/home/sammytheslug`. We separate directories that are inside
other directories ("paths", we call this) with a `/` on Linux or a Mac. For
whatever reason, we use a `\` on Windows, but it means the same thing!

On Linux and other UNIX systems, the top of the filesystem hierarchy is called
the *root* directory, and this is denoted as `/` by itself, just the slash.

So any file path that starts with a `/` is an *absolute* path; it's the complete
location.

You can also have *relative* paths, which are relative to the current working
directory. Let's get concrete, this is very theoretical. You can do things like
this... (here the command `pwd` prints out your current working directory, and
`cd` stands for "change directory" -- that's how you go to different locations)

```
  $ pwd
  /home/alex
  $ cd ..
  $ pwd
  /home
  $ cd /
  $ pwd
  /
```

You can use `cd` to explore around everywhere on your Linux machine, checking
out all of the files that are in there.

One thing we'll talk about more soon is header files -- you can go look at all
of the header files that you have installed, like so:

```
  $ cd /usr/include
```

To see all the files that are in a given directory, use the `ls` command, short
for "list".

```
  alex@judy:~$ ls
```

To find out more about a given command, you have two broad strategies that you
can use. You can try *giving it a flag* and asking that command for help, or you
can try using the *man page*. Let's try `ls --help`.

```
  $ ls --help
```

That's a lot of options! One of the most important options for ls is `ls -l`.
You might notice that `-l` and `--help` have a different number of dashes.
Traditionally, UNIX programs have one dash for short flags and two dashes for
long flags, although this is just a tradition and not universal.

`ls -l` gives you a lot more information about all of the files -- notably, the
*permissions* on those files, whether they can be read, written, or executed,
and *by whom*.

At any moment if you want to return to your home directory, you can type one of
these commands:

```
  $ cd
  # or this works too
  $ cd ~
```

And then you're right back where you started. Throughout all your travels, your
prompt will update to say where you are. (you can also customize your prompt to
include different information, a topic for another day)


Some other handy commands you'll definitely want are...

  * `mkdir` -- making a new directory -- you'll do this every time you start a new
    homework in the class
  * `rmdir` -- used for deleting an empty directory
  * `mv`  -- used for moving or renaming files
  * `touch` -- updates a file to have been written (touched) just now, or if
    that file doesn't exist, creates an empty file
  * `cat` prints the contents of a file. If you specify multiple files, it
    con-*cat*enates all of the files specified. If you specify no input file, it
    waits for your input from the keyboard to print that to its output.
  * `cp` -- used to copy a file
  * `rm` -- used to delete a file. Be careful with this one, by default it can't
    be undone!

All of these commands take at least one *argument*, which is the file you want
to operate on. In the case of `mv` and `cp`, they take two (or more) arguments,
which are the *source* and *destination*. You can use `cp` and `mv` to put files
into directories -- if the source is a file and the destination is a directory,
then it will put the file into the specified directory.

If you want to be careful with `rm`, you can type `rm -i` instead, which will
prompt you before deleting a file.

# Exercises for getting this far!

  * Make a new directory called `sammy` in your home directory. Use `cd` to go
    into it. Use `touch` to create an empty file in that directory called
    `theslug`.

  * Do the same thing in the special directory on your computer/VM called
    `/tmp`. `/tmp` will be on your machine, and you can create files and
    directories in there.

  * Try to delete `~/sammy` with `rmdir`. It shouldn't work, because that
    directory is not empty. Then delete the file `~/sammy/theslug` with the `rm`
    command. Now you should be able to delete the `~/sammy` directory with
    `rmdir`.

# The real magic: redirecting input and output, connecting programs

## Redirecting output

Programs on UNIX have several "streams" associated with them, most importantly
their "standard input" (stdin) and "standard output" (stdout). There is also a
third stream called "standard error" (stderr) that acts in the same way as
stdout; we'll talk about it later.

By default, a program's input comes from what you type on the keyboard, but this
doesn't have to be the case. And also by default, a program's output is sent to
your terminal for you to read. We can change this too!

Like so. (example taken directly [from the MIT
course](https://missing.csail.mit.edu/2020/course-shell/), because it's good):

```
  $ echo hello > hello.txt
  $ cat hello.txt
  hello
  $ cat < hello.txt
  hello
  $ cat < hello.txt > hello2.txt
  $ cat hello2.txt
  hello
```

What's going on here? The `<` operator means "use this file as the input to this
program", and the `>` operator means "put the output of this program into this
file". And like you can see in the example here, you can do both at once!

Be careful with the `>` operator -- it will completely replace the contents of
the specified file with the output of the given command.

You can also use the `>>` operator to *append* into the specified file, rather
than blowing away the contents of the file. Like so!

```
  $ echo good afternoon > hello.txt
  $ echo good evening >> hello.txt
  $ echo hey internet >> hello.txt
  $ echo "without any further ado let's get right into it" >> hello.txt
  $ cat hello.txt
```

... and as you can see, at this point, `hello.txt` contains all four of those
messages.

## Connecting programs together

One other neat thing you can do with redirection is what's called *piping*.
Piping lets you construct chains of programs where the output of one program is
fed in as the input to a second program. And so on! You can construct chains of
arbitrary lengths in fact -- this is quite useful, and one of the most UNIX-y
things you can do.

For example, there's a little program called `wc` (short for "word count"),
which will tell you how many lines, words, and characters are in its input.
Let's say you had several text files in your directory, and you wanted to know
how many words were in all of them taken together.

Let's make another text file in your current directory...

```
  $ echo "like and subscribe" >> goodbye.txt
```

Note that `>>` works even if that file doesn't exist yet. It does now!

And then let's see how many files ending with .txt are in the current directory.
There might be two, depending on what you've been up to.

```
  $ ls *.txt
```

This `*` thing is one more thing we wanted to show you, called "globbing". It
lets you match patterns of filenames. Here it matches all of the files that end
with ".txt".

Now let's print out all of the text files in the current directory and see how
many words there are in all of them. The `wc -w` command only prints out the
number of words, rather than lines or characters.

```
  $ cat *.txt | wc -w
```

I got 18 words for my `hello.txt` and `goodbye.txt`. How many did you get?

<hr/>

For our next trick, we're going to need to install a dictionary, a list of a
bunch of words.

```
  $ sudo apt install wamerican
```

It will ask for your password, which is fine -- you'll install a bunch of stuff
with `apt`, and it needs `sudo` permissions, which are just when you become the
admin user (called "root" in UNIX) to do that. What you should know about this
command is, after this point, your dictionary is in the file
`/usr/share/dict/words`.

Once you've done this, say you're the kind of person who wants ten random words
that contain the letter 'z', in alphabetical order. You might type something
like the following:

```
  $ cat /usr/share/dict/words | grep z | shuf | head -n 10 | sort
```

Let's break down the parts here.
  * The first command prints out *all the words in the dictionary*. There are a
    bunch, like on the order of tens of thousands.
  * The second command, `grep`, filters down the input that it got and prints
    out only the words that contain lowercase `z`, then prints all of those it
    *its* output.
  * The third command, `shuf`, shuffles all the input lines it gets and prints
    them in a random order.
  * The fourth command, `head`, prints out the first *n* lines that it gets. In
    this case, this would be ten randomly chosen words that contain the letter
    `z`.
  * Finally, `sort` alphabetizes its input line-by-line and prints the sorted
    output.

That's kind of a lot! What other combinations can you do here? Could you make it
print out the *same* words every time? What would you remove to make that
happen? Could you print the words in different orders?


# This is a life skill

There is so much to take in here. We're learning and growing, though. Nobody's
born knowing this stuff, so take your time and get used to it!

If you want more to chew on, there are some harder problems to try (and a few
more concepts, like more on permissions and what it means for a file to be
*executable*) in
[the MIT version](https://missing.csail.mit.edu/2020/course-shell/). This is
enough for today though.
