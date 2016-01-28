# Let's define a common build environment first...
env = Environment()
#env.Append(CPPDEFINES={'VERSION': 1})
env.Append(CPPPATH = ['/Users/taok/seiscode/include'])

print env['CPPPATH']

env.VariantDir('build', 'src')
env.SConscript('build/SConscript', {'env': env})
