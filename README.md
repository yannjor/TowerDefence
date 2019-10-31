# Tower Defence

Current directory structure:

  * `plan/` -- Our project plan can be found here. It is also included as a PDF.

  * `doc/` -- The documentation sources related to your project should be put here.
    You may use different tools for documentation (e.g. latex),
    but we hope to get the final version of the document
    **also as pdf file**.

  * `src/` -- Here are the C++ source files. 

  * `cmake/` -- Here are the CMake modules.

  * `out/` -- Output directory. You'll find your executable file here after compling.


## Build instructions

* Two dependencies are currently needed to build the project, **CMake** and **SFML 2.5** so make sure these are installed on your system.

* Run the build.sh script found in the main directory (`./build.sh`)

* Go to the `out/` directory (`cd out/`) and simply run the excecutable (`./tower-defence`)