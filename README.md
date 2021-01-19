![xP](https://socialify.git.ci/theProgrammerDavid/xP/image?description=1&font=Bitter&language=1&owner=1&stargazers=1&theme=Dark)

# xP
C++ native app to test HTTP endpoints
### Dependencies
- CMake
- OpenGL (with supporting drivers)
- CMake supported C++ Compiler
- Debian and Ubuntu systems might need some additional dependencies as given below: 
```bash
sudo apt-get install libx11-dev xorg-dev libglu1-mesa-dev 
```

* Windows systems need the Visual Studio environment setup with the necessary files for C++ development. If required, you need to run 
```powershell
vcvarsall.bat x64
```

You also need the dev libraries for `OpenSSL` installed. Windows will default to using `WINSSL`
```bash
sudo apt-get install libssl-dev

```
### Get Started

```bash
git clone https://github.com/theProgrammerDavid/xP.git
```

### Building

- Create a ``build`` folder and `cd` into that, and run ``cmake ..`` (or if you want a Release build, use ``cmake -DCMAKE_BUILD_TYPE=Release ..``)
- Configuring CMake might take a while initially as it is downloading dependencies


### Libraries used
| Library         | URL                              |
|-----------------|----------------------------------|
| ImGui           | https://github.com/ocornut/imgui |
| Glew            | https://glew.sourceforge.net     |
| GLFW            | https://github.com/glfw/glfw     |
| Curl For People | https://whoshuu/cpr              |