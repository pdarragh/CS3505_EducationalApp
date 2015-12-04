########
# Libraries
########

These are the external library files required for this Qt project.

Unfortunately, due to the myriad build platforms in use by our team, this was
the best solution we could come up with. Effectively, Qt believes actual library
files to exist in this directory, but in reality we just have symbolically
linked file references instead. Since the libraries must be compiled
individually to function, this at least allows us to not have to update the Qt
build settings on each person's computer, saving a lot of hassle in the long
run.

####
# Links

Box2D                       ../../../Box2D/Box2D/Box2D/
libBox2D.a                  ../../../Box2D/Box2D/Build/Box2D/libBox2D.a
libmysqlclient_r.a          ../../../mysql/lib/libmysqlclient.a
libmysqlclient_r.dylib      ../../../mysql/lib/libmysqlclient.dylib
mysql                       ../../../mysql/lib/
mysql-include               ../../../mysql/include/

It is assumed that the locations of the desired items lies just outside the
scope of the MathleCommand root directory. That is to say that if you have your
MathleCommand repository in a folder named "Projects", your setup should be
something like this:

Projects/
    |
    |-MathleCommand/
    |   |-MathleCommand/
    |       |-libs/
    |           |-readme.txt (this file)
    |           |-libBox2D.a (e.g.)
    |-Box2D/
    |   |-Box2D/
    |       |-Build/
    |           |-Box2D/
    |               |-libBox2D.a
    |-mysql/
    |   |-lib/
    |   |-include/

Of course, whether you actually have real files in these locations is up to you.
These could also be other symlinks pointing to the correct files. But this setup
allows for sharing of Qt files in this git repository, which is what we really
wanted.
