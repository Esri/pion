Pion is used as a thin http client which is statically linked into our local server.
There's a requirement to use a version of boost but since we are only building a
static library, we do not need to have boost libraries.  Changes were made to the
configuration so that we only build what we need with minimal requirements. Once
this repo is cloned, grab a copy of boost and put it somewhere on disk. Then, from
the root of this repo, configure the builds. You will need cmake on your PATH.

cd build && mkdir build32 && cd build32
cmake ../.. -G"Visual Studio 12 2013" -DBOOST_ROOT=<PATH_TO_BOOST>
cd ..
mkdir build64 && cd build64
cmake ../.. -G"Visual Studio 12 2013 Win64" -DBOOST_ROOT=<PATH_TO_BOOST>
cd ..

You will now have a pion_solution.sln in each build directory that you can open
and build pion with.  The static libs will go to their respective Bin directories
under the build${ARCG} folders.
