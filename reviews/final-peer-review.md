# Review form for project tower-defence-2019-1

**Names of the reviewers: Lars Dieterich, Tuukka Pihlaja, Tuure Nurminen**
Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and
scope. The extent of project is large enough to accommodate work for
everyone (2p)

    - They did make a tower defence game and implement most of the things theyplanned though some are missing. Looking at the commits it is evident thateverybody had something to do. 2p

  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

    - Yes, they have a clear structure to their software and it is well documented.2p

  * 1.3: Use of external libraries is justified and well documented. (2p)

    - They are using SFML and Boost. Good justifications can be found in theirdocumentation. 2p

## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

    - The commits are very frequent with good enough descriptions. 2p

  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

    - According to the project plan they opted to go for a TODO list and a projectmanager who keeps track of things. In their documentation we can see thateverybody had responsibilities assigned to them and they had group meetingsevery week. Seems to be very well organized. 2p

  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

    - They have a good amount of documentation on their testing methods and aclear set of rules on how they will write their code. 2p

## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

    - They are using CMake and they have some simple instructions in theirdocumentation on how to build the program. 2p

  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

    - They used valgrind to check for memory leaks. We did also see some customcopy assignment operators. 2p

  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

    - We haven’t spotted any custom containers or anything else of the sort. 2p

  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

    - We have spotted several cases of exception handling (try/catch). 2p

## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. (0-10p)

    **Implemented additional features that were planned:**
    - Non hardcoded maps (max 2p): They are loading their maps from .txt files in the map folder so you could add your own if you wanted to. 2p
    - Upgradeable towers (max 2p): Towers can be upgraded with additional damage, range and attack speed. 2p
    - More kinds of enemies and towers (max 2p): They have five different enemies and three different towers. The minimum was three and three. 1p
    - Dynamic enemy paths (max 2p): They are using A* algorithm for their path planning so the path can be dynamic. 2p
    **Other additional features:**
    - Non hardcoded waves: They have their wave system in .json files and then use Boost to parse them. Probably ought to have the same value as nonhardcoded maps.
    - Resizable window: Their windows can be resized to whatever you want which is very convenient.
    - Background music: Some nice music to imerese you into the experience.
    **Planned but not implemented:**
    - Saved high score for maps
    - Sound effects

