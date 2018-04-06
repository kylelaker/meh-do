# meh-do

Runs a single command as root, much like sudo(1) but without any checks. This
command should NOT be used. On its own, it isn't awful, but it is dangerous
once installed.

To install this such that it does anything, root permissions are required 
intitially; however, after that you can call `meh-do` regardless.

## Building

```
make
```

## Installing

```
sudo make install
```

If you want someone other than root to own the binary (and as such, be able to
execute commands as that user), run

```
sudo make OWNER=<USER> install
```

And replace `<USER>` with the desired owner.

## License

This is licensed under the MIT License. See LICENSE for more information.
