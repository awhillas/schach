# Alex's C++ notes

## Forward declarations

- Help break cyclic dependancies.
- Significantly reduce build times.

foo.h

    class bar;    // This is useful
    class foo
    {
        bar* obj; // Pointer or even a reference.
    };

foo.cpp

    #include "bar.h"
    #include "foo.h"

bar.h

    class foo;   // This is also useful

bar.cpp

    #include "foo.h"
    #include "bar.h"


## Call with pointer vs call by reference

    func(SPRITE \*x);

with a call of:

    func(&mySprite);

vs.

    func(SPRITE &x);

with a call of:

    func(mySprite);

## Trouble shooting

Error:
```
dyld: lazy symbol binding failed: Symbol not found: __ZN5PieceD1Ev
  Referenced from: /private/var/tmp/_bazel_alex/2d57536a86fcea3046c07ff4838acca7/bazel-sandbox/6281834107144465742/execroot/com_github_awhillas_schach/bazel-out/local-fastbuild/bin/test/piece_test.runfiles/com_github_awhillas_schach/test/piece_test
  Expected in: flat namespace

dyld: Symbol not found: __ZN5PieceD1Ev
  Referenced from: /private/var/tmp/_bazel_alex/2d57536a86fcea3046c07ff4838acca7/bazel-sandbox/6281834107144465742/execroot/com_github_awhillas_schach/bazel-out/local-fastbuild/bin/test/piece_test.runfiles/com_github_awhillas_schach/test/piece_test
  Expected in: flat namespace
 ```
Cause:
