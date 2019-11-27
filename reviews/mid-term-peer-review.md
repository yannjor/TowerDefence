# Review form for project Tower defence 1

**Name of project to be reviewed: tower-defence-2019-1**

**Names of reviewers: Lars Dieterich, Tuukka Pihlaja, Tuure Nurminen (tower-defence-2019-2)**

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p)

  * 1.1: The implementation corresponds to the selected topic and scope. 
The extent of project is large enough to accommodate work for everyone (2p)

    **Yes, they are clearly making a tower defence game however it is difficult to say if they will fully reach the planned extent of the game as they still have alot to do. Based on their commits there is clearly enough work for everyone.**

  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

    **Yes, they have a clear structure to their software. Obviously there is no documentation at this moment.**

  * 1.3: Use of external libraries is justified and well documented. (2p)

    **In their project plan they have a good idea on what libraries they are going to use and why. To implement the game mechanics many elements of the SFML-library is used.**

## 2. Working practices (0-6p)

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

    **The commit are very frequent, even a bit too frequent. We do see cases of commiting code that would not run. Commit logs do get the point across.**

  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

    **According to the project plan they opted to go for a TODO list and a project manager who keeps track of things. Seems like a very flexible way of doing things and seems to work quite well.**

  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

    **No documentation on testing so it is quite hard to say.**

## 3. Implementation aspects (0-8p)

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

    **They are using CMake and they have some simple instructions in the README file.**

  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

    **Pointers are used in some places to access larger resources such as textures. At the moment no objects are destroyed using Destructors. The memory management is not documented yet.**

  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

    **We haven’t spotted any custom containers or anything else of the sort.**

  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

    **It is easily possible to crash the program with wrong file inputs or missing data this should be considered in their schedule. For example to have decisions when certain textures are missing or maps can not be found.**

## 4. Project extensiveness (0-10p)

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions 
give a rough guideline about how these points are awarded on different 
topics, but note that this will be always case-by-case estimation by 
the supervisor, depending on the actual implementation and its 
characteristics. (0-10p)

    **According to the initial project plan, the following points should be implemented as additional tasks:**
        **Non hardcoded maps**
        *This is currently being worked on (according to Git-commits).*
        **Upgradeable towers**
        *Currently not implemented.*
        **More kinds of enemies and towers**
        *The classes used make it easy to adapt enemies and towers.*
        **A list of high scores that is saved locally per map, with a username**
        *Not yet implemented.*
        **Dynamic enemy paths that are altered with the placement of towers**
        *Would be easy to implement due to the A\* algorithm used.*
        **Sound effects**
        *Not yet implemented.*
        **The working health bar under the enemies to visualize their taken damage  is anadditional feature that could be pointed out for extra points.**
