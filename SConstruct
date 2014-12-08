env = Environment()

env.ParseConfig('pkg-config --cflags --libs glfw3')
env.AppendUnique(CCFLAGS=['-g', '-O2', '-Wall', '-Wextra', '-std=c++11'])
env.AppendUnique(CPPPATH=['src'])

env.SharedLibrary('rrrgame', Glob('src/rrrgame/*.cpp'))
env.Program('runrunrun', Glob('src/runrunrun/*.cpp'), LIBS=['rrrgame'], LIBPATH=['.'])
