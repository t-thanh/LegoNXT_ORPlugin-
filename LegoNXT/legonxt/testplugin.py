#!/usr/bin/env python
from openravepy import *
RaveInitialize()
RaveLoadPlugin('build/legonxt')
try:
    env=Environment()
    env.Load('scenes/myscene.env.xml')
    LegoNXT = RaveCreateModule(env,'LegoNXT')
    print LegoNXT.SendCommand('activate')
finally:
    RaveDestroy()
