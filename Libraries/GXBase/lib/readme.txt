This directory contains the gxbase library, which must
be linked with your project. This is done automatically,
providing that Visual Studio has this directory in its
library search path, and that you use the default project
settings. You only need to read the rest of this file if
you are having linking problems, or want to use a different
runtime library.

There are several different versions of the library, which
correspond to different runtime libraries or Win32 or x64
architecture. The GXBase.h file contains code to
automatically link with the right version of the library,
depending on your project settings.

The supported Debug setting is:
  Debug Multithreaded DLL

The supported Release setting is:
  Multithreaded DLL

The following naming convention is used:
  gxbase.lib     = Single threaded
  gxbased.lib    = Debug Single threaded
  gxbasem.lib    = Multithreaded DLL
  gxbasemd.lib   = Debug Multithreaded DLL
  gxbasem64.lib  = Multithreaded DLL x64
  gxbasemd64.lib = Multithreaded Debug DLL x64

The following project settings are NOT supported:
  Multithreaded
  Debug Multithreaded

For VS.NET 2005 the single threaded libraries are deprecated

If you need to use an unsupported version of the runtime
libraries, the source code is available so that you can
create a suitable build configuration.
