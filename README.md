# Setup

## OS X

Bazel needs java8 (bug with java9 still)

    brew cask install caskroom/versions/java8
    brew install bazel

# Build instructions

## Bazel

    bazel build //src:schach

then to run

    bazel run //src:schach

or run all the tests

    bazel test ... --test_output=errors

### Troubleshooting Bazel builds

- If getting an error that mentions "missing dependency declarations" and your toolchain had an upgrade somewhere i.e. new compiler with new copy of STD lib., try:

    bazel clean --expunge


## `make`

To use the `Makefile` in the `src/` folder.
Ensure you have a recent version of the gnu compiler collection.

```
cd src
make
./schach
```

To clean:

```
cd src
make clean
```
