# Setup

## OS X

Bazel needs java8 (bug with java9 still)

    brew cask install caskroom/versions/java8
    brew install bazel

## Ubuntu 17.10

Install Java 8:
```
sudo apt install openjdk-8-jdk
```

Install Bazel:

 * [Google instructions](https://docs.bazel.build/versions/master/install-ubuntu.html)


# Build instructions

## Bazel

    bazel build //src:schach

then to run

  bazel run //src:schach

or run all the tests

  bazel test ... --test_output=errors


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
