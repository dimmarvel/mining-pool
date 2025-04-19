## 📋 Requirements

- **Compiler**: 
  - g++ (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
  - gcc (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
- **System**: Ubuntu 22.04 or compatible Linux distribution
- **Tools**: 
  - `wget` or `curl` for downloading
  - `tar` for extraction
  - `make`, `g++`, `cmake` for building

## 🛠 Tech Stack

- **Boost 1.81.0** (System module only)
- **C++20** standard
- **Static linking** (libboost_system.a)
- **CMake** integration support

## 🚀 Installation & Build

### Download and extract Boost
```bash
wget https://archives.boost.io/release/1.81.0/source/boost_1_81_0.tar.gz
tar -xzf boost_1_81_0.tar.gz
./bootstrap.sh --prefix=/usr/local --with-libraries=system --with-toolset=gcc
sudo ./b2 install -j8  --with-system link=static threading=multi variant=release cxxflags="-std=c++20 -O2"  --prefix=/usr/local
```

### Build
```bash
mkdir build
cd build
cmake ..
make -j(nproc)
./mining-pool
```