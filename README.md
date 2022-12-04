# libcas

libcas is a collection of helpful stuff I use in my C projects. Rather than
copy/paste the same headers across different projects, I decided to make a
library out of it.

## Features

* Various basic things which should be part of stdlib like MIN/MAX macros as
  well as a `zalloc` macro for allocating zeroed memory.
* Binary data handling with `bytearray.c`, also `print_hex_dump()` from [Bjorn
  Andersson](https://github.com/andersson/rmtfs/blob/master/util.c#L12)
* A simple logging implementation, originally from
  [rxi/log.c](https://github.com/rxi/log.c) on GitHub.
* A bunch of timespec helpers from
  [solemnwarning/timespec](https://github.com/solemnwarning/timespec) on GitHub.

## Build configuration

There a are a few macros you can define to configure libcas, for now these have
to be set at build time, hopefully these will be runtime configurable in the
future. See `config.h` for the list of available macros.

## Importing to your project

