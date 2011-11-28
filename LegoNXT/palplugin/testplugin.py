#!/usr/bin/env python
from openravepy import *
RaveInitialize()
RaveLoadPlugin('build/palplugin')
try:
    env=Environment()
    env.Load('scenes/myscene.env.xml')
    PalPhysics = RaveCreatePhysicsEngine(env,'PalPhysics')
    print PalPhysics.SendCommand('help')
finally:
    RaveDestroy()
