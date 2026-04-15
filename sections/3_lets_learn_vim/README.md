# Getting comfortable with a text editor: vim basics

Welcome to the third section for CSE 13s! 

Today we will get into the details of learning vim, which is the officially
recommended, but not required, editor for this class. You might already be using
vim! Today we'll show you some more vim ideas -- a goal of this class is to help
you understand the flavor of vim, so you'll know what it's about and why you
might want to adopt it.

These instructions are more or less based on MIT's [Missing
Semester](https://missing.csail.mit.edu/) coursework, particularly the
[third session](https://missing.csail.mit.edu/2020/editors/).

At this point, you should already have your Linux environment set up for the
course; you've been using it for the first two homeworks. But if you need more
help, please ask the course staff for help in the discord.

----

*Instructions for the TAs:*  Live-code the exercises here, taking suggestions
from the class as you go! Let's practice using vim!

Also, make sure that everybody has an opportunity to do the attendance quiz!

----

# Why vim?

A question people ask pretty often about CSE 13s, is "do I *have* to use vim?"

Alex might say something like "look, you don't *have* to do anything. But aren't
you here to learn stuff? Don't you want to learn this?"

There's a real answer to this question, though: No. You do not have to use
vim. Lots of people do this class just fine without vim. And there are so many
great ways to edit text out there, and most of them work on Linux, or Mac, or
Windows.

**Actually though, why vim?**

Have you seen what it looks like when somebody good at vim is editing text?
Stuff is just happening on the screen, and it looks like magic. It's not obvious
how they're even doing it.

It's not magic -- it's a little programming language with very quick keyboard
shortcuts. vim is expressive, and it grows with you, and you can configure it to
your heart's content.
You can always add more techniques to your vim repertoire, and once they get
into your muscle memory, you will edit faster in more different situations.

And in some sense that's your job, as a software developer -- editing text.

One other potentially helpful use case -- vim works even when you don't have a
graphical interface. Say you have to connect to a remote computer over `ssh` and
edit a file over there. vim works just fine in this case too! If you imagine
that you'll be doing system administration or DevOps type tasks, this isn't
hypothetical -- this kind of thing happens fairly frequently!

OK great; let's learn some vim.

# vim is *modal*

So vim is always in a specific *mode*. You start out in *normal* mode, and this
is where you'll spend most of your time. You'll switch between modes quite a lot
though.

  * Normal mode: for moving around the file and issuing *commands*
  * Insert mode: for inserting text (the "type stuff" mode)
  * visual mode: there are several variants of this, regular visual mode, visual
    line mode, and visual block mode. They let you select lots of text,
    typically so you can delete it or copy it.
  * command mode: for typing commands (like :wq)
  * there are more modes, too, such as "replace" mode, which overwrites existing
    text instead of inserting it.

You'll spend most of your time in either "normal" mode or "insert" mode.

Helpfully, vim tells you which mode you're in. If it says nothing at the bottom,
you are in *normal mode*. Otherwise, it will tell you which mode you're in, like
`-- INSERT --`.

The basic thing you want to know -- if you want to go back to normal mode, hit
Escape.

Many vim users (including Alex) remap their capslock key to be Escape because
they press it so often. Who needs capslock when you could be using vim more
ergonomically?

# inserting text

Once you're in *insert mode*, it's your time to shine! Type that text. Write
your program, or your novel, or whatever.

There are several ways to get into insert mode from normal mode:

  * `i` -- insert where you currently are
  * `A` (for "append") -- start insert mode at the end of the current line
  * `o` -- insert a fresh line, after the current line
  * `O` -- insert a fresh line, but *before* the current line

# moving around

When you're in normal mode, you can easily move around.

  * h, j, k, l  -- move around one at a time. h, j, k, l are left, down, up, and
    right respectively. You should try to use these by default rather than the
    arrow keys, so you don't have to move your right hand from the home row.
  * moving by a word at a time: `w` to go to the next word, `b` to go backwards
    to the beginning of a word, `e` to go to the end of a word
  * moving withing a line: Lines: `0` (beginning of line), `^` (first non-blank
    character), `$` (end of line)
  * moving relative to the screen: H (top of screen), M (middle of screen), L
    (bottom of screen)
  * moving relative to the file: gg (beginning of file), G (end of file)
  * going to a particular line number
    * :{number}<Enter> (this is a command, so you enter *command mode* and then
      hit Enter to do the command)
    * {number}G   (go to a specific line)
  * finding matching parentheses or braces: `%`
  * searching:  hit `/` and then you can start typing a *regular expression*
    (more about these later in the class) or just some text, to find that text
    in the file. Once you've found a match, hit `N` to go to the next match.

# grabbing areas of the file with visual mode

  * `v` to enter Visual mode
  * `V` to enter Visual Line mode (for selecting whole lines)
  * `Ctrl+V` to enter Visual Block mode (for selecting rectangular areas; this
    happens sometimes but honestly it's less common)

Once you've selected an area, you can apply a command to it! Try `y` for
example, to "yank" that area, which is the same as copying it. Then you can
paste what you copied with `p`.

# undoing mistakes and redoing to undo your undos

  * `u` to undo your previous command -- you can undo entire "inserts"! Those
    are just one command.
  * `Ctrl+R` to redo.

# vim is a little programming language

vim commands that you enter in *normal mode* can be thought of as a little
programming language, and you can script them in a few different ways.

Notably, if you want to do a command several times, you can often specify how
many times; many commands also take a *motion* or can be applied over a
*selection*. These will grow with you over time. The more time you spend with
vim, the more natural it will be to compose these things on the fly.

Here are some examples!

  * 3w: move 3 words forward
  * 5j: move 5 lines down
  * 7dw: delete 7 words
  * 1G, qg G: linewrap the whole file
  * (silly example) 1G, g~G -- swap the case of everything in the whole file

# saving your work

To save (*write*) the current file, you'll enter the "w" command, by typing `:w`
and then hitting enter.

If you want to write to a *different file name*, you can type ":w newfilename",
which will save a copy of the current file into "newfilename" (you can of course
use a different filename, whatever you want) 


# exiting vim

A common joke that's not particularly funny and has been played out for decades
is "I don't know how to quit vim". Don't be that person.

You have options!

  * :q (hit enter) -- this enters *command mode* for a moment and closes the
    current *window*, which is a view onto a *buffer*. If you only have one
    window open, this exits vim, if you have nothing to save.
  * :wq (hit enter) -- this writes the current file and then closes the window.
  * :q! (hit enter) -- this exits the current window, even if you haven't saved
  * :qa or :qa!  -- this exits *all windows* even if you have multiple windows.
  * `ZZ` -- in normal mode, this saves the current

# getting help

vim comes with extensive documentation, and you can look up most commands in vim
with ":help".

# configuring your vim

vim is configured by putting different vim commands in your "~/.vimrc" file.

What the heck is "~/.vimrc" ?

It's a *hidden file* (in the sense that it starts with a `.`) in your home
directory, which is a little script that vim runs when it starts up.

You can use it to configure lots of things about your vim; a good starting point
is to look at other people's vimrc files and see what they've put in there.

Here are some configurations that Alex uses. If your TA is a vim enthusiast, ask
what they have in theirs! Comments in vimrc files start with a `"`.

```
set ruler          " show the cursor position all the time
set textwidth=80   " try to keep text at a max of 80 columns wide
set colorcolumn=+1 " highlight column after 'textwidth'
hi ColorColumn ctermbg=darkgrey   " highlight it in dark grey
```

There's a lot more. You can also add vim plugins. It's quite extensible.
[Check out the MIT
notes](https://missing.csail.mit.edu/2020/editors/#extending-vim) for an
explanation on how to do this if you're interested.


# Other editors to consider
An alternative that we're not talking about much in this class, and it's
interesting that it gets much less attention these days, is
[Emacs](https://en.wikipedia.org/wiki/Emacs). That's something that Alex also
feels you should learn about. It's interesting and it's part of the culture, and
lots of people (including UC Santa Cruz faculty) use Emacs all the time instead
of vim.

There are lots of other editors as well (foreshadowing??), and also things that
you might want to describe more as IDEs (integrated development environments)
rather than text editors -- these are great for many purposes, and lots of
people love Visual Studio Code, IntelliJ IDEA, PyCharm, Eclipse, Android Studio,
and so forth. Most of these, including [VS Code](https://code.visualstudio.com/)
work on Linux too.

# Exercises

  * Mess with all of the commands listed here in this document.
  * Create a "~/.vimrc" file and put some commands in it. Exit your vim and
    restart! Why not try different color schemes with ":set colorscheme" ?
  * run `vimtutor` on your computer for a detailed tutorial. If you don't have
    it installed already, do `$ sudo apt install vimtutor` at your command
    prompt.

# I need more

If you want to learn more, here are some more resources for you!

  * [MIT Missing Semester: editors](https://missing.csail.mit.edu/2020/editors/)
    -- there's some more stuff in here.
  * *Learning the vi and Vim Editors* by Arnold Robbins and Elbert Hannah,
    [available for free to you online](https://go.oreilly.com/university-of-california-santa-cruz).

This is enough for today though.
