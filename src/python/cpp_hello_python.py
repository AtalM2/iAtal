#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append('.libs')
import python_hello
world = python_hello.World()
world.set('Hello World!')
print(world.greet())
