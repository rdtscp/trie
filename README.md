# Trie
Trie implementation in C++. Built using CMake and Google Test. 

# Download
```
git clone https://github.com/acwilson96/Trie
cd Trie
```
The following should be run from within the "Trie" directory.
# Install
```
mkdir build
cd build
cmake ..
make
make install
```
# Uninstall
```
cd build
xargs rm < install_manifest.txt
cd ..
rm -rf ./build/
```
# Development/Testing
Install using the above, then run
```
cd build
make
make test
cd ..
```