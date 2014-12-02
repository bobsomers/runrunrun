env = Environment()

env.ParseConfig('pkg-config --cflags --libs glfw3')
env.AppendUnique(CCFLAGS=['-g', '-O2', '-Wall', '-Wextra', '-std=c++11'])

env.Program('runrunrun', Glob('src/*.cpp'))
