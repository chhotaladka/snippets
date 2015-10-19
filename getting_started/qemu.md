## Getting started with QEMU
================================

1. **Install** (Ubuntu 14.04 i386 Machine)
   [Resource - Installation](https://en.wikibooks.org/wiki/QEMU/Linux)
   [ERROR: glib-2.12 gthread-2.0 is required to compile QEMU](https://superuser.com/questions/812809/unable-to-configure-qemu-on-ubuntu-14-04)
   
   ```bash
   wget http://wiki.qemu-project.org/download/qemu-2.4.0.tar.bz2
   tar -xf qemu-2.4.0.tar.bz2
   cd qemu-2.4.0
   sudo apt-get install libglib2.0-dev zlib1g-dev
   ./configure
   make
   sudo make install
   ```