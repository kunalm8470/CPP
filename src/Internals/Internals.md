# C++ Internals
___

The C++ compiler sequentially goes through each source code (.cpp) file in your program and does two important tasks:
1. Checking for correctness of syntax against the standard definition of the C++ Language standard, if an error is encountered during the process the compilation is stopped.
2. Each C++ source file is translated into a machine format file called the **object file** which typically have the file extension `.o` or `.obj` with the filename same as the C++ source file. C++ does not know anything about source files.
    - C++ creates [`Translation Units`](https://docs.microsoft.com/en-us/cpp/cpp/program-and-linkage-cpp?view=vs-2019) which consists of the contents of a single source file, plus the contents of any header files directly or indirectly included by it, minus those lines that were ignored using conditional preprocessing statements.
    - Post creating `Translation Units` tokenization and parsing process takes place as a result of which `Abstract Syntax Trees (AST)` being created.
___

If the program had 3 .cpp files, the compiler would generate 3 object files:
![CompileSource](./CompileSource.png)
___

After the compiler creates one or more object files in the previous step, an another program called the **linker** comes into picture, which does the following 3 tasks -

1. Enumerating over all the object files created by the compiler and combining them into a single executable program having the extension `.exe`.
2. Linking `library files` which are nothing but collection of precompiled code that has been bundled up for reuse in other programs.
3. All cross-file dependencies are resolved properly without any issues.

Once all the above 3 steps are successfully done, we will get an executable file that we can run.

![LinkingObjects](./LinkingObjects.png)

___

An IDE usually consists of a text-editor, compiler and linker which is the entire package to run C++ in one-go.