# Review form for project tower-defence-2019-1

**Name of the reviewer: Essi Jukkala**
Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and
scope. The extent of project is large enough to accommodate work for
everyone (2p)

    **The project implements all the basic features and extra features on top of those. (2p)**

  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

    **The classes are clearly thought out and make sense. Inheritance is used correctly. 
    Functionality is implemented in a clear way and information is stored where it is appropiate. 
    Everything is well documented. (2p)**

  * 1.3: Use of external libraries is justified and well documented. (2p)

    **The game uses Boost and SFML. Both of these are sensible choices and are utilized well in the project. (2p)**

## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

    **Git has been used throughout the project with frequent commits and 
    the commits messages make sense. All looks good here. (2p)**

  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

    **The workload has been divided between the group members fairly well. 
    Everyone has participated in programming the project. (2p)**

  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

    **The testing practices are justified. The memory management has also been tested. (2p)** 

## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

    **The software can be easily built with the provided instructions. 
    CMake is used correctly with the external libraries. (2p)**

  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

    **Memory management is done quite well. RO3/5 is not followed everywhere, 
    as there are destructors but no copy or assignment 
    operators/constructors or the other way around. (1p)**

  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

    **C++ standard library is used correctly. (2p)**

  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

    **The game handles invalid input well and didn't crash while testing. 
    Many possible exceptions have been taken into account. (2p)**

## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. (0-10p)

    **- Non-hardcoded maps, i.e. read from a file or randomly generated (2 points)**
    **- Upgradeable towers (2 points)**
    **- More different kinds of enemies and towers (2 points)**
    **- Multiple paths of the enemies, so branched paths and enemies choose one with some intelligence (3 points)**
    **- Background music (1 point)**
    
