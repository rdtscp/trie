# Trie
Trie implementation in C++. Built using CMake and Google Test. 

# Download
```
git clone https://github.com/acwilson96/Trie
cd Trie
```
The following should be run from within the "Trie" directory.
# Release Install
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
make install
```
# Debug Install & Run Unit Tests
```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
make install
make test
cd ..
```
# Uninstall
```
cd build
xargs rm < install_manifest.txt
cd ..
rm -rf ./build/
```