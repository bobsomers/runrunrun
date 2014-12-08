env = Environment()

# Global construction environment.
env.VariantDir('build', 'src', duplicate=0)
env.AppendUnique(CCFLAGS=['-g', '-O2', '-Wall', '-Wextra', '-std=c++11'])

# Load the SConscripts for each project.
Export('env')
SConscript([
    'build/game/SConscript',
    'build/runrunrun/SConscript'
])
